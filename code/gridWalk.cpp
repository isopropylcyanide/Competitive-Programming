#include <bits/stdc++.h>
using namespace std;
typedef long long unsigned llu;
typedef vector<int> vi;
/*
You are situated in an NN dimensional grid at position (x1,x2,...,xN)(x1,x2,...,xN). The dimensions of the grid are (D1,D2,...DN)(D1,D2,...DN). In one step, you can walk one step ahead or behind in any one of the NN dimensions. (So there are always 2×N2×N possible different moves). In how many ways can you take MM steps such that you do not leave the grid at any pollu? You leave the grid if at any pollu xixi, either xi <= 0 or xi>Di
*/
llu MOD = 1000000007;
llu T, N, M;

llu modPow(llu a, llu X, llu p) {
    // return a^X mod p
    llu res = 1;
    while(X>0) {
        if(X & 1) res = (res*a) % p;
        a=(a*a)%p;
        X >>= 1;
    }
    return res;
}

llu modInverse(llu a, llu p) {
    // return modular multiplicative of: a mod p, assuming p is prime
    return modPow(a, p-2, p);
}

llu modBinomial(llu n, llu k, long long unsigned p) {
    // return C(n,k) mod p, assuming p is prime
    llu numerator = 1; // n*(n-1)* ... * (n-k+1)
    llu i;
    for(i=0;i<k;i++)
        numerator = (numerator*(n-i))%p;

    llu denominator = 1; // k!
    for(i=1;i<=k;i++)
        denominator = (denominator*i) %p;

    llu res = modInverse(denominator,p);
    res = (res*numerator)%p;
    return res;
}


int getWays(vi &x, vi &d, int M) {
    int N = d.size();

    long long md[M + 1][N + 1];
    for (int i = 0; i < N; i++) {
        long long m[d[i] + 1][M + 1];
        int D = d[i];

        for (int j = 1; j <= D; j++)
            m[j][0] = 1;

        for (int n = 1; n <= M; n++) {
            for (int j = 1; j <= D; j++) {
                m[j][n] = 0;
                if (j - 1 > 0)
                    m[j][n] = (m[j][n] + m[j - 1][n - 1]) % MOD;
                if (j + 1 <= D)
                    m[j][n] = (m[j][n] + m[j + 1][n - 1]) % MOD;
            }
        }

        md[0][i + 1] = 1;
        for (int j = 1; j <= M; j++)
            md[j][i + 1] = m[x[i]][j];
    }

    long long c[M + 1][M + 1];
    for (int i = 0; i <= M; i++) {
        c[i][0] = 1;
        c[i][i] = 1;
    }
    for (int i = 1; i <= M; i++)
        for (int j = 1; j < i; j++)
        c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;

    long long mdt[M + 1][N + 1];
    for (int i = 0; i <= M; i++)
        mdt[i][1] = md[i][1];
    for (int i = 0; i <= N; i++)
        mdt[0][i] = 1;

    for (int i = 2; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            mdt[j][i] = 0;
            for (int k = 0; k <= j; k++)
                mdt[j][i] =
                    (mdt[j][i] +
                     ((c[j][j - k] *
                       ((mdt[k][i - 1] * md[j - k][i]) % MOD)) % MOD)) % MOD;
        }
    }

    return mdt[M][N];
}

int main() {
    int T, N, M, temp;
    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> N >> M;
        vector<int> x;
        vector<int> d;

        for (int j = 0; j < N; j++) {
            cin >> temp;
            x.push_back(temp);
        }

        for (int j = 0; j < N; j++) {
            cin >> temp;
            d.push_back(temp);
        }

        cout << getWays(x, d, M) << endl;
    }

    return 0;
}
