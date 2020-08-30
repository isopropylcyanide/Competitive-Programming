#include <bits/stdc++.h>
using namespace std;

//Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.
//A region is captured by flipping all 'O's into 'X's in that surrounded region.

int I, J, M, N;
vector<vector<int>> V;
vector<vector<char>> A;
map<int, bool> dfsValid;
int counter;


bool surroundable(int i, int j){
    //Returns true if a region can be surrounded
    if (i > 0 && i < N -1 && j > 0 && j < M -1)
        return true;
    return false;
}

bool init(vector<vector<char> > &AA){
    //Initialize global vars and visited matrix
    N = AA.size();
    if (N == 0)
        return false;
    M = AA[0].size();
    V.resize(N, vector<int>(M, 0));
    A = AA;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++)
            if (A[i][j] == 'X')
                V[i][j] = 1;
    }
    if (!dfsValid.empty())
        dfsValid.clear();
    counter = 1;
    return true;
}

bool inBound_O_(int i, int j){
    //returns true if A[i][j] is within array and != 'X'
    if (i < 0 || i >= N || j < 0 || j >= M || A[i][j] == 'X')
        return false;
    return true;
}

void bfs(int i, int j, char val){
    //BFS from a 'O' cell
    queue<pair<pair<int, int>, char>> q;
    q.push(make_pair(make_pair(i, j), val));

    while (!q.empty()){
        i = q.front().first.first;
        j = q.front().first.second;
        val = q.front().second;
        q.pop();
        if (V[i][j] != 1){ //if node is not visited
            V[i][j] = 1;
            if (!surroundable(i, j))
            dfsValid[val] = false;
            A[i][j] = val + '0';

            if (inBound_O_(i + 1, j))
                q.push(make_pair(make_pair(i + 1, j), val));
            if (inBound_O_(i - 1, j))
                q.push(make_pair(make_pair(i - 1, j), val));
            if (inBound_O_(i, j + 1))
                q.push(make_pair(make_pair(i, j + 1), val));
            if (inBound_O_(i, j - 1))
                q.push(make_pair(make_pair(i, j - 1), val));
        }
    }
}

void solve(vector<vector<char> > &A) {
    //Capture surrounding areas
    if (!init(A))
        return;

    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            if (A[i][j] == 'O' && V[i][j] == 0){
                // cout << "\n Current counter: " << counter << " from i: " << i << " j: " << j << endl;
                dfsValid[counter] = true;
                bfs(i, j, counter);
                counter ++;
            }
        }
    }
    //Reset dfs values to their validity status
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            if (A[i][j] == 'X')
                continue;
            if (dfsValid[A[i][j] - '0'] == true)
                A[i][j] = 'X';
            else
                A[i][j] = 'O';
        }
    }
}


int main(){
    vector<vector<char>> A = {
        {'X','X','X','X'},
        {'X','O','O','X'},
        {'X','X','O','X'},
        {'X','O','X','X'}
    };
    solve(A);
    for (auto a : A){
        for (auto b : a)
            cout << b << " ";
        cout << endl;
    }
    return 0;
}
