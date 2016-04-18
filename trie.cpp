#include <bits/stdc++.h>
using namespace std;
#define numAlpha 26

// Implement a trie with insert, search, and startsWith methods (a -z only)
class TrieNode {
public:
    // Initialize your data structure here.
    bool end;
    TrieNode *path[numAlpha];
    TrieNode() {
        end = false;
        for (int i = 0; i < numAlpha; i++)
        path[i] = NULL;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
        copy = root;
    }

    void insertUtil(TrieNode * root, int i, string &s){
        // Inserts a string into a trie utility
        int index = s[i] - 'a';

        if (root -> path[index] == NULL){
            root -> path[index] = new TrieNode;
        }

        if (i + 1 == s.size()){
            root -> path[index] -> end = true;
            return;
        }

        insertUtil(root -> path[index], i +1, s);
    }

    // Inserts a word into the trie.
    void insert(string word) {
        copy = root;
        insertUtil(copy, 0, word);
    }

    bool searchUtil(TrieNode * root, int i, string &s){
        // Searches a string into a trie utility
        int index = s[i] - 'a';

        if (root -> path[index] == NULL)
            return false;

        if (i + 1 == s.size()){//last values
            if (root -> path[index] -> end)
                return true;
            return false;
        }
        return searchUtil(root -> path[index], i +1, s);
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        copy = root;
        return searchUtil(copy, 0, word);
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        return search(prefix);
    }

private:
    TrieNode* root, *copy;
};
