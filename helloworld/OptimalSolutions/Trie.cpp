#include <string>
#include <cstring>

using namespace std;

struct Trie {
    bool end[26]; // alphabets, end of trie
    bool exist[26]; // alphabets, middle of trie
    Trie *next[26]; // alphabets , next of current trie 

    Trie() {
        // INITIALIZE TO ZERO
        memset(end, 0, sizeof(end));
        memset(next, 0, sizeof(next));
        memset(exist, 0, sizeof(exist));
    }
};

Trie trie;

void trie_push(string in) {
    Trie *traverse = &trie;
    int x;

    for (int i = 0; i < in.size(); i++) {
        x = in[i] - 'a';
        traverse->exist[x] = 1;

        if (i == in.size() - 1) {
            traverse->end[x] = 1;
        } else {
            if (traverse->next[x] == 0)  // if there no next Trie
                traverse->next[x] = new Trie(); // make new one
            traverse = traverse->next[x]; // if there is next Trie, just follow through
        }
    }
}

bool trie_search(string in) {
    Trie *traverse = &trie;
    int x;
    for (int i = 0; i < in.size(); i++) {
        x = in[i] - 'a';
        if (!traverse->exist[x]) 
            return 0;
        
        if (i == in.size() - 1) {
            if (traverse->end[x])
                return true;
            else    
                return false;
        }

        if (traverse->next[x] == 0) return false;
        traverse = traverse->next[x];
    }
}