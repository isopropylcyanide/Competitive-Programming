#include <bits/stdc++.h>
using namespace std;

// Program to find LCS and print any one
int N, M;
vector<int> A, B;

void findLCS(vector<int> &A, vector<int> &B){
    vector<vector<int>> L(M, vector<int>(N, 0));

    for (int i = 0; i < M; i++){
        for (int j = 0; j < N; j++){
            if (i == 0 && j == 0)
                L[i][j] = B[i] == A[j] ? 1 : 0;
            else if (j == 0)
                L[i][j] = B[i] == A[j] ? 1 : L[i -1][j];
            else if (i == 0)
                L[i][j] = B[i] == A[j] ? 1 : L[i][j -1];
            else
                L[i][j] = B[i] == A[j] ? 1 + L[i -1][j -1]:
                    max(L[i -1][j], L[i][j -1]);
        }
    }

    for (int i = 0; i < M; i++){
        for (int j = 0; j < N; j++)
            cout << L[i][j] << " ";
        cout << endl;
    }
    vector<int> res;
    int i= M -1, j = N -1;

    while (i > 0 && j > 0){
        int left = L[i][j -1];
        int up = L[i -1][j];
        if (B[i] == A[j]){
            res.push_back(B[i]);
            i--; j--;
        }
        else if (up > left)
            i--;
        else
            j--;
        if (i == 0)
            res.push_back(B[i]);
        else if (j == 0)
            res.push_back(A[j]);
    }
    reverse(res.begin(), res.end());
    for (auto a : res)
        cout << a << " ";
    cout << endl;
}

int main(){
    cin >> N >> M;
    A.resize(N);
    B.resize(M);

    for (int i = 0; i < N; i++)
        cin >> A[i];
    for (int i = 0; i < M; i++)
        cin >> B[i];

    findLCS(A, B);

    return 0;
}
