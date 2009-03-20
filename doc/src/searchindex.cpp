/******************************************************************************
 *
 * $Id: searchindex.cpp,v 1.7 2001/03/19 19:27:41 root Exp $
 *
 * Copyright (C) 1997-2008 by Dimitri van Heesch.
 *
 * Permission to use, copy, modify, and distribute this software and its
 * documentation under the terms of the GNU General Public License is hereby 
 * granted. No representations are made about the suitability of this software 
 * for any purpose. It is provided "as is" without express or implied warranty.
 * See the GNU General Public License for more details.
 *
 * Documents produced by Doxygen are derivative works derived from the
 * input used in their production; they are not affected by this license.
 *
 */
#include <ctype.h>

#include "searchindex.h"
#include "target.h"
#include "token.h" // tolower

// file format: (all multi-byte values are stored in big endian format)
//   4 byte header
//   256*256*4 byte index (4 bytes)
//   for each index entry: a zero terminated list of words 
//   for each word: a \0 terminated string + 4 byte offset to the stats info
//   padding bytes to align at 4 byte boundary
//   for each word: the number of urls (4 bytes) 
//               + for each url containing the word 8 bytes statistics
//                 (4 bytes index to url string + 4 bytes frequency counter)
//   for each url: a \0 terminated string

//--------------------------------------------------------------------

const int SearchIndex::numIndexEntries = 256*256;

IndexWord::IndexWord(const char *word) : m_word(word) {
    //m_urls.setAutoDelete(TRUE);
    printf("IndexWord::IndexWord(%s)\n",word);
}

void IndexWord::addUrlIndex(int idx,bool hiPriority) {

    URLInfo ui(idx,2);
    if (hiPriority)
        ui.freq|=1; // mark as high priority document
    //printf("IndexWord::addUrlIndex(%d,%d)\n",idx,hiPriority);
    map<int,URLInfo>::iterator it = m_urlinfo.find(idx);
    if (it==m_urlinfo.end()) {
        //printf("URLInfo::URLInfo(%d)\n",idx);
        m_urlinfo[idx] = ui;
    } else {
        it->second.freq+=2;
        if (hiPriority)
            it->second.freq|=1; // mark as high priority document
    }
}

//--------------------------------------------------------------------

SearchIndex::SearchIndex() : m_urlIndex(-1) {

    m_index = new vector<IndexWord*>[numIndexEntries];
    /// problème si m_index == NULL;
    if (m_index == NULL)
        cerr << "  ATTENTION : m_index == NULL " << endl;
}

SearchIndex::~SearchIndex() {

    for(int i=0;i<numIndexEntries;i++)
        for(int j=0;j<m_index[i].size();j++)
            delete m_index[i][j];

    if (m_index)
        delete[] m_index;
}

void SearchIndex::setCurrentDoc(Target* t ) {
    m_urlIndex++;
    m_urls[m_urlIndex] = t ;
}

static int charsToIndex(const char *word) {
    if (word==0)
        return -1;
    
    // Fast string hashing algorithm
    //register ushort h=0;
    //const char *k = word;
    //ushort mask=0xfc00;
    //while ( *k ) 
    //{
    //  h = (h&mask)^(h<<6)^(*k++);
    //}
    //return h;
    
    // Simple hashing that allows for substring searching
    unsigned int c1=word[0];
    if (c1==0) {
        cerr << "[[[[ problème avec charsToIndex ]]]] :: word[0] = " << word[0] << endl;
        return -1;
    }
    unsigned int c2=word[1];
    if (c2==0) {
        cerr << "[[[[ problème avec charsToIndex ]]]] :: word[1] = " << word[1] << endl;
        return -1;
    }
    return c1*256+c2;
}

void SearchIndex::addWord(const string& word,bool hiPriority) {
    //printf("____________________SearchIndex::addWord(%s,%d)\n",word,hiPriority);
    IndexWord *w;
    string wStr = word;
    if (wStr.empty())
        return;
    tolower(wStr);
    cerr << " tolower(wStr) = " << wStr << endl;
    map<string,IndexWord*>::iterator it = m_words.find(wStr);
    if (it==m_words.end()) {
        int idx=charsToIndex(wStr.c_str());
        if (idx<0) return;
        w = new IndexWord(wStr);
        //fprintf(stderr,"addWord(%s) at index %d\n",word,idx);
        m_index[idx].push_back(w);
        m_words[wStr] = w;
    } else
        it->second->addUrlIndex(m_urlIndex,hiPriority);
        //w->addUrlIndex(m_urlIndex,hiPriority);
}


void writeInt(ostream & os, int index) {
    os.put((unsigned char)(((unsigned int)index)>>24));
    os.put((unsigned char)((((unsigned int)index)>>16)&0xff));
    os.put((unsigned char)((((unsigned int)index)>>8)&0xff));
    os.put((unsigned char)(((unsigned int)index)&0xff));
}

void writeString(ostream & os,const char *s) {
    const char *p = s;
    while (*p) os.put(*p++);
    os.put(0);
}

void SearchIndex::write(const char *fileName) {
    int i,j;
    int size=4; // for the header
    size+=4*numIndexEntries; // for the index
    int wordsOffset = size;
    // first pass: compute the size of the wordlist
    for (i=0;i<numIndexEntries;i++) {
        for(j=0;j<m_index[i].size();j++) {
            size += m_index[i][j]->length_word()+5; // 5 = 1+4
        }
        size++; // zero list terminator
    }

    // second pass: compute the offsets in the index
    int indexOffsets[numIndexEntries];
    int offset=wordsOffset;
    for (i=0;i<numIndexEntries;i++) {
        if (m_index[i].size()>0) {
            indexOffsets[i]=offset;
            for(j=0;j<m_index[i].size();j++) {
                offset+= m_index[i][j]->length_word()+5; // 5 = 1+4
            }
            offset++; // zero list terminator
        } else
            indexOffsets[i]=0;
    }
    int padding = size;
    size = (size+3)&~3; // round up to 4 byte boundary
    padding = size - padding;

    int *wordStatOffsets = new int[m_words.size()];
    int count=0;
    // third pass: compute offset to stats info for each word
    for (i=0;i<numIndexEntries;i++) {
        for(j=0;j<m_index[i].size();j++) {
            wordStatOffsets[count++] = size;
            size+=4+m_index[i][j]->size_map()*8;// count + (url_index,freq) per url
        }
    }

    int *urlOffsets = new int[m_urls.size()];
    //int urlsOffset = size;
    map<int,Target*>::iterator udi;//QIntDictIterator<URL> udi(m_urls);

    for(udi=m_urls.begin();udi!=m_urls.end();udi++) {
        urlOffsets[udi->first] = size;
        size += udi->second->name.name.length()+1+udi->second->reference().length()+1;
    }
    //printf("Total size %x bytes (word=%x stats=%x urls=%x)\n",size,wordsOffset,statsOffset,urlsOffset);
    ofstream f(fileName, ios::out);
    if (f.is_open()) {
        // write header
        f.put('D'); f.put('O'); f.put('X'); f.put('S');
        // write index
        for (i=0;i<numIndexEntries;i++)
            writeInt(f,indexOffsets[i]);
        // write word lists
        count=0;
        for (i=0;i<numIndexEntries;i++) {
            for(j=0;j<m_index[i].size();j++) {
                writeString(f,m_index[i][j]->m_word.c_str());
                writeInt(f,wordStatOffsets[count++]);
            }
            if (m_index[i].size())
                f.put(0);
        }
        // write extra padding bytes
        for (i=0;i<padding;i++) 
            f.put(0);
        // write word statistics
        for (i=0;i<numIndexEntries;i++) {
            for(j=0;j<m_index[i].size();j++) {
                int numUrls = m_index[i][j]->size_map();
                writeInt(f,numUrls);
                map<int,URLInfo>::iterator it;
                for(it=m_index[i][j]->m_urlinfo.begin();it!=m_index[i][j]->m_urlinfo.end();it++) {
                    writeInt(f,urlOffsets[it->second.urlIdx]);
                    writeInt(f,it->second.freq);
                }
            }
        }
        // write urls
        map<int,Target*>::iterator it;
        for(it=m_urls.begin();it!=m_urls.end();it++) {
            writeString(f,it->second->name.name.c_str());
            writeString(f,it->second->reference().c_str());
        }
    } else
        cerr << "error : imposible to open " << fileName << endl;
    
    delete[] urlOffsets;
    delete[] wordStatOffsets;
}

