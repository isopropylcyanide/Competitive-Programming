#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007

int N, T,  K, u, v;
vector <vector<int> > A;


int main(){
    cin >> T;
    while (T --){
        cin >> N >> K;
        A.resize(N, vector<int>(N, 0));
        for (int i = 0; i < N - 1; i++){
            cin >> u >> v;
            A[u - 1][v - 1] = 1;
        }

    }

    return 0;
}
