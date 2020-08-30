#include <bits/stdc++.h>
using namespace std;

/*
Given N * M field of O's and X's, where O=white, X=black
Return the number of black shapes. A black shape consists of one or more adjacent X's
*/

#define mp make_pair
int N, M, shape;
map< pair<int, int>, int > cache;

void dfsBlack(int i, int j, int curShape, vector<string> & A){
    // check for bounds
    if (i < 0 || i >= N || j < 0 || j >= M || A[i][j] == 'O')
        return;

    //if already stored, return
    if (cache.find(mp(i, j)) != cache.end())
        return;

    // Definitely an X mark that is unvisited
    cache.insert(mp(mp(i, j), curShape));
    dfsBlack(i , j + 1, curShape, A);
    dfsBlack(i , j - 1, curShape, A);
    dfsBlack(i + 1, j, curShape, A);
    dfsBlack(i - 1, j, curShape, A);
}

int black(vector<string> &A) {
    N = A.size();
    M = A[0].size();
    shape = 0;

    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            if (A[i][j] == 'X'){
                //DFS recur only if unmarked
                if (cache.find(mp(i, j)) == cache.end()){
                    dfsBlack(i, j, shape + 1, A);
                    shape += 1;
                }
            }
        }
    }
    return shape;
}


int main(){

    vector<string> A = {
        "XOOOOOXXOX",
        "OOXXXXOOXX",
        "XXOXXOOXXO",
        "OXOXXXXXXO",
        "XOXXOXOXXX",
        "OOOOOOOXOO",
        "XOXXXOOXOX",
        "XXXOXOXXXO"
    };

    cout << black(A) << endl;

    return 0;
}
