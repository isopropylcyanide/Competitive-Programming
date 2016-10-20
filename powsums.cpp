#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MOD 1000000007

ll T, N, Q, temp, x;
vector<ll> A;     //denotes the value of constants
vector<ll> Y;     //denotes f(x) for x from 1 to n
vector<ll> QQ;     //stores queries

ll fast_exp(ll base, ll exp) {
    // fast exp
    ll res = 1;
    while(exp > 0) {
       if(exp %2 == 1)
        res = (res * base) % MOD;
       base = (base * base) % MOD;
       exp /= 2;
    }
    return res % MOD;
}

ll modInv(ll N){
    return fast_exp(N, MOD -2);
}

void computeConstants(){
    // Computes constants A, B,..upto N and stores in A
    A[1] = Y[1];
    for (int i = 2; i <= N; i++){
        ll lhs = Y[i], rhs = 0, incr = 1;

        for (int k = i -1; k >= 1; k--, incr++){
            temp = (A[incr] * Y[k]) % MOD;
            temp = incr % 2 == 0 ? (-temp + MOD)%MOD : temp;
            rhs = (rhs + temp) % MOD;
        }
        lhs = ((lhs - rhs + MOD) * modInv(incr)) % MOD;
        A[i] = incr % 2 == 1 ? lhs : (-lhs + MOD)%MOD;
    }
    for (int i = 2; i <= N; i+=2)
        A[i] = (-A[i] + MOD) % MOD;
}

void preCompute(ll MAX_LIM){
    // Precompute value of k till 5000
    for (int i = N + 1; i <= MAX_LIM; i++){
        ll rhs = 0;
        ll incr = 1;
        for (int k = i -1; incr <= N; k--, incr++)
            rhs = (rhs + (A[incr] * Y[k]) % MOD ) % MOD;
        Y[i] = rhs;
    }
}

int main(){
    scanf("%lld", &T);
    while (T--){
        scanf("%lld %lld", &N, &Q);

        Y.resize(5002);
        A.resize(N + 1);
        QQ.resize(Q + 1);
        ll maxm = -1;

        for (int i = 1; i <= N; i++)
            scanf("%lld", &Y[i]);

        // compute constants
        computeConstants();
        for (int i = 1; i <= Q; i++){
            scanf("%lld", &QQ[i]);
            maxm = max(maxm, QQ[i]);
        }

        preCompute(maxm);
        for (int i = 1; i <= Q; i++)
            printf("%lld ", Y[QQ[i]]);

        printf("\n");
    }

    return 0;
}
