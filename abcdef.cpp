#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> A;
unordered_map<int, int> L;
unordered_map<int, int> R;

int main(){

    ios_base :: sync_with_stdio(false);

    cin >> N;
    A.resize(N);

    for (int i = 0; i < N; i++)
        cin >> A[i];

    for (int a = 0; a < N; a++){
        for (int b = 0; b < N; b++){
            for (int c = 0; c < N; c++)
                L[A[a] * A[b] + A[c]] += 1;
        }
    }
    for (int d = 0; d < N; d++){
        for (int e = 0; e < N; e++){
            for (int f = 0; f < N; f++){
                if (A[d] != 0)
                    R[A[d] * (A[e] + A[f])] += 1;
            }
        }
    }
    int ways = 0;
    for (auto key: L){
        if (R.find(key.first) != R.end())
            ways += L[key.first] * R[key.first];
    }
    cout << ways << endl;

    return 0;
}
