#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned ll;
#define MAX 1000005

ll T, N, u, v;
ll A[MAX];
ll B[MAX];

int main(){

    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    while (T--){
        cin >> N;
        memset(A, 0, MAX);
        memset(B, 0, MAX);

        ll initate = 0;

        for (int i = 0; i < N; i++){
            cin >> u >> v;
            B[u] = v;
            if (!initate)
            initate = u;
            else{
                // Already initiated
                A[v] = u;
                if (initate == v){
                    ll temp = u;
                    while (A[temp] != 0)
                        temp = A[temp];
                    initate = temp;
                }
            }
            // cout << "\n Current initator: " << initate << endl;
        }

        ll current = initate;
        while (B[current]){
            cout << current<<"-"<<B[current]<<" ";
            current = B[current];
        }
        cout << endl;

    }

    return 0;
}
