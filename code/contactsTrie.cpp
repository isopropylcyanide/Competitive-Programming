#include <bits/stdc++.h>
using namespace std;

#define numAlpha 26

// Add string to trie. And print count of strings with a given prefix

typedef struct trie{
    int count;//strings with this node as a prefix
    struct trie* path[numAlpha];
    trie(){
        count = 0;
        for (int i = 0; i < numAlpha; i++)
            path[i] = NULL;
    }
}trie;

void insert(trie *t, int i, string &s){
    int index = s[i] - 'a';

    if (t -> path[index] == NULL){
        t -> path[index] = new trie();
        t -> path[index] ->count = 1;
    }
    else
        t -> path[index] -> count += 1;

    if (i == s.size() - 1)
        return;
    insert(t -> path[index], i + 1, s);
}


int numPrefix(trie *t, int i, string &s){
    int index = s[i] - 'a';
    if (!t)
        return 0;

    if (i == s.size() - 1){
        if (t -> path[index] != NULL)
            return t -> path[index] -> count;
        return 0;
    }

    return numPrefix(t -> path[index], i + 1, s);
}


int main(){
    int N;
    cin >> N;
    trie * root = new trie();
    trie * avail = root;
    string choice, s;

    for (int i = 0; i < N; i++){
        cin >> choice >> s;
        if (choice == "add")
            insert(root, 0, s);
        else
            cout << numPrefix(root, 0, s) << endl;
        root = avail;
    }
}
