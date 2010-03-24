import os,string,re

def hash_1(s):
    

for name in filter(lambda x:x[-3:]=='.py',os.listdir('.')):
    for word in re.split('\W+', file(name,'r').read() ):
        if len(word)==0 or not word[0] in string.ascii_letters: continue
        print word
        