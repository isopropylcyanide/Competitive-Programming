#include <bits/stdc++.h>
using namespace std;

#define numAlpha 26
#define END 23

// Given  strings. Each string contains only lowercase letters from (both inclusive). The set of  strings is said to be GOOD SET if no string is prefix of another string else, it is BAD SET. (If two strings are identical, they are considered prefixes of each other.)

typedef struct trie{
    int count;//strings with this node as a prefix
    struct trie* path[numAlpha];
    trie(){
        count = 0;
        for (int i = 0; i < numAlpha; i++)
            path[i] = NULL;
    }
}trie;

bool insert(trie *t, int i, string &s){
    int index = s[i] - 'a';

    if (t -> path[index] == NULL){
        t -> path[index] = new trie();
        t -> path[index] ->count = 1;
    }
    else{
        /* this node already exists,
        eg a -> b -> c -> x and we are at a -> b -> (c) -> d -> e;
        Now we need to check if this node also has the END marker set
        if it has, then return false; else continue
        */
        if (t -> path[index] -> path[END] == NULL)
            t -> path[index] -> count += 1;
        else
            return false;
    }

    if (i == s.size() - 1){
        /* if the count at this node is > 1
            return false, as this string will become a prefix
        */
        if (t -> path[index] -> count > 1)
            return false;


        /* Now set 'x' = END as the last node
            eg abc -> a -> b -> c -> x
            but if x has already been set.
            Return false;
        // this is the last node*/
        if (t -> path[index] -> path[END] != NULL)
            return false; //somebody already marked this
        else{
            // We are going to mark end for the first time
            t -> path[index] -> path[END] = new trie();
            return true;
        }
    }

    else
        return insert(t -> path[index], i + 1, s);
}



int main(){
    int N;
    cin >> N;
    vector<string> A(N);

    trie * root = new trie();
    trie * avail = root;

    // One by one insert strings into the trie
    // if during insertion, we encounter end of another string,
    // mark it as false;
    string defaulterLine = "";

    for (int i = 0; i < N; i++){
        cin >> A[i];
        if (!insert(root, 0, A[i])){
            defaulterLine = A[i];
            break;
        }
        root = avail;
    }

    if (defaulterLine.size() != 0)
        cout << "BAD SET " << endl << defaulterLine << endl;
    else cout << "GOOD SET" << endl;
}
