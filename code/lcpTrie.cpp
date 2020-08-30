#include <bits/stdc++.h>
using namespace std;

#define NUM 26
#define MOD 1000000007

typedef struct trie{
    int level, count;
    struct trie* path[NUM];
    trie(){}
    trie(int l){
        level = l;
        count = 0;
        for (int i = 0; i < NUM; i++)
            path[i] = NULL;
    }
}trie;

void insertToTrie(int i, string &s, trie * root, int level){
    int index = s[i] - 'a';

    if (root -> path[index] == NULL){
        root -> path[index] = new trie();
        root -> path[index] -> count = 1;
        root -> path[index] -> level = level;
    }
    else
        root -> path[index] -> count += 1;

    if (i + 1 == s.size())
        return;

    insertToTrie(i +1, s, root -> path[index], level + 1);
}

trie * addStringsToTrie(vector<string> &A){
    // Insert into trie
    trie * root = new trie(0); //trie with level 0
    trie * copy  = root;

    for (auto s : A){
        insertToTrie(0, s, root, 1);
        root = copy;
    }
    return root;
}

void walkTrie(trie *root, int reqdLevel, int &count){
    if (!root)
        return;
    if (root -> level == reqdLevel){
        int curCount = root -> count;
        count = (count + (curCount) * (curCount + 1)/2) % MOD;
        return;
    }
    else{
        for (int i = 0; i < NUM; i++){
            if (root -> path[i])
                walkTrie(root -> path[i], reqdLevel, count);
        }
    }
}


int LCPrefix(vector<string> &A, int B) {
    int count = 0;
    trie * root = addStringsToTrie(A);
    // Now trie has been created. Traverse the tree upto the depth of B and add nodes

    walkTrie(root, B, count);
    return count;
}

int main(){

    vector<string> A = {
        "a",
        "aman",
        "bc",
        "bcd"
    };
    cout << LCPrefix(A, 1) << endl;
    cout << LCPrefix(A, 2) << endl;
    cout << LCPrefix(A, 3) << endl;
    cout << LCPrefix(A, 4) << endl;

    return 0;
}
