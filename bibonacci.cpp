#include <bits/stdc++.h>
using namespace std;

#define MAX 100005
typedef long long ll;

ll N, M, t;

vector<ll> A, P;

typedef vector<vector<ll>>matrix;
matrix m{
    {1, 1, 1},
    {1, 0, 0},
    {0, 0, 1}
};

matrix mul(matrix &a, matrix &b){
    // Multiply two matrices
    int n = a.size();
    matrix c(n, vector<ll>(n, 0));

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            for (int k = 0; k < n; k++)
                c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % M;
        }
    }
    return c;
}

matrix matpow(matrix &A, ll p){
    // return A * p
    if (p == 1)
        return A;
    if (p % 2 == 1){
        matrix k = matpow(A, p -1);
        return mul(A, k);
    }
    matrix c = matpow(A, p/2);
    return mul(c, c);

}


ll solve(ll val){
    ll ans = 0;
    if (val < 2)
        ans =  (ans + 1) % M;
    else{
        matrix k = matpow(m,  val - 1);
        ans = (ans + k[0][0] + k[0][1] + k[0][2]) % M;
    }
    return ans;
}

ll N2solve(){
    //N2 solve
    ll ans = 0;
    for (int i = 0; i < N; i++){
        for (int j = i; j < N; j++){
            int val = i == 0 ? P[j] : P[j] - P[i -1];
            ans = (ans + solve(val)) % M;
        }
    }
    return ans;
}

int main(){
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    A.resize(N);
    P.resize(N);

    for (int i = 0; i < N; i++)
        cin >> A[i];

    P[0] = A[0];
    for (int i = 1; i < N; i++)
        P[i] = P[i -1] + A[i];

    cout << N2solve() << endl;

}
