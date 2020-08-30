#include <bits/stdc++.h>
using namespace std;

/*
Given a 2D board and a word, find if the word exists in the grid.
The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The cell itself does not count as an adjacent cell.
The same letter cell may be used more than once.
*/

typedef struct qNode{
    // A queue node contains the current part of the string, and its location
    int match; //next index to match
    int i, j;
    qNode(int a, int b, int m){
        i = a; j = b;
        match = m;
    }
}qNode;


int exist(vector<string> &A, string B) {
    // Find the possible starts.
    // For each start look at itself, down, left| right
    // if any of these positions match with the next char of B, add those
    // to queue and increment B
    int N = A.size();
    if (N == 0)
        return 0;
    int M = A[0].size();
    queue<qNode> q;

    int bIndex = 0;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            if (A[i][j] == B[bIndex])
                q.push(qNode(i, j, 1));
        }
    }

    while (!q.empty()){
        auto f = q.front();
        q.pop();
        // if f contains B, then its over
        //look for next index
        int i = f.i, j = f.j;
        int k = f.match;
        if (f.match == B.size()) //this expects the end, which means we're done
            return 1;

        // Look left, right, down, up and at the same char
        if (j > 0 && A[i][j -1] == B[k])
            q.push(qNode(i, j -1, k + 1));

        if (j < M - 1 && A[i][j + 1] == B[k])
            q.push(qNode(i, j + 1, k + 1));

        if (i > 0 && A[i -1][j] == B[k])
            q.push(qNode(i - 1, j, k + 1));

        if (i < N - 1 && A[i + 1][j] == B[k])
            q.push(qNode(i + 1, j, k + 1));
    }
    return 0;
}


int main(){
        vector<string> A = {
            "ABCE",
            "SFCS",
            "ADEE"
        };
        vector<string> B = {
             "BGGAGBGE",
             "EFFAGBEG",
             "FGGCBBFF",
             "BEEBDEDC",
             "FACABDCD",
             "ECGEFFED",
             "GDBEGACG",
             "GCECFBBD"
        };
        cout << exist(B, "CABBFFEAC");
        vector<string> C = {
            "aa"
        };
        cout << exist(C, "aaa");
}
