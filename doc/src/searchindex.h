/******************************************************************************
 *
 * $Id: searchindex.h,v 1.7 2001/03/19 19:27:41 root Exp $
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

#ifndef _SEARCHINDEX_H
#define _SEARCHINDEX_H

#include <string>
#include <vector>
#include <map>
// #include <>
#include <iostream>
using namespace std;

struct Target;

void writeInt(ostream & os, int index);
void writeString(ostream & os,const char *s);

struct URLInfo {
    URLInfo() : urlIdx(0), freq(0) {}
    URLInfo(int idx,int f) : urlIdx(idx), freq(f) {}
    int urlIdx;
    int freq;
};

struct IndexWord {
    IndexWord(const char *word);
    IndexWord(const string& word) { m_word = word;}
    void addUrlIndex(int,bool);
    const map<int,URLInfo> &urlinfo() const { return m_urlinfo; }
    string word() const { return m_word; }
    int length_word() { return m_word.length();}
    int size_map() { return m_urlinfo.size(); }

    string    m_word;
    map<int,URLInfo> m_urlinfo;//QIntDict<URLInfo> m_urls;
};

struct SearchIndex {
    SearchIndex();
    ~SearchIndex();
    void setCurrentDoc(Target* t );
    void addWord(const string& word,bool hiPriority);
    void write(const char *file);

    map<string,IndexWord*> m_words;//QDict<IndexWord> m_words;
    vector<IndexWord*>* m_index; //QVector< QList<IndexWord> > m_index;
    map<int,Target*>  m_urls;
    int m_urlIndex;
    static const int numIndexEntries;
};


#endif
