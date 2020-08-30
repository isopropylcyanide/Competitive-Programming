#include <bits/stdc++.h>
using namespace std;
#define numAlpha 26

//Find shortest unique prefix to represent each word in the list.
// Simple. Create a trie, where each node stores the number of nodes emanating from it
// Unique prefix is reached only when the number of emanating nodes is 1 from the respective node

typedef struct trie{
    int count; //number of nodes emanating from this trie node
    struct trie *path[numAlpha];

    trie(){
        count = 0;
        for (int i = 0; i < numAlpha; i++)
            path[i] = NULL;
    }
}trie;

void insert(trie * root, int i, string &s){
    // Inserts a string into a trie
    int index = s[i] - 'a';

    if (root -> path[index] == NULL){
        root -> path[index] = new trie();
        root -> path[index] -> count = 1;
    }
    else
        root -> path[index] -> count += 1;

    if (i + 1 == s.size())
        return;

    insert(root -> path[index], i +1, s);
}

void findUniquePrefix(trie * root, int i, string &uniq, string &s){
    // Finds the shortest uniquely identifying prefix of a string
    int index = s[i] - 'a';
    uniq += s[i];

    if (i + 1 == s.size())
        return;

    if (root -> path[index] -> count == 1)
        return;

    findUniquePrefix(root -> path[index], i + 1, uniq, s);
}


vector<string> prefix(vector<string> &A) {
    vector<string> ans;

    trie * root = new trie();
    trie * avail = root;

    for (auto str: A)
        insert(avail, 0, str);

    // Now all strings have been inserted into the trie. All that remains, is to find their common prefix
    for (auto str : A){
        string uniq;
        findUniquePrefix(avail, 0, uniq, str);
        ans.push_back(uniq);
        avail = root;
    }

    return ans;
}


int main(){

    vector<string> A = {"bearcat", "bert"};              //bea ber
    vector<string> B = {"zebra", "dog", "dove", "duck"}; //z dog dov du
    for (auto a : prefix(A) )
        cout << a << " ";

    cout << endl;

    for (auto a : prefix(B) )
        cout << a << " ";

    return 0;
}
