#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<vector<ll>>matrix;
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

ostream &operator << (ostream &c, matrix &m){
    ll n = m.size();
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++)
            c << m[i][j] << " ";
        c << endl;
    }
    return c;
}

ll modInv(ll N){
    return fast_exp(N, MOD -2);
}

matrix mul(matrix &a, matrix &b){
    // Multiply two matrices
    int n = a.size();
    matrix c(n, vector<ll>(n, 0));

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            for (int k = 0; k < n; k++)
                c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % MOD;
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

void computeConstants(){
    // Computes constants A, B,..upto N and store in A
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
    // for (int i = 1; i <= N; i++)
    //     cout << "A["<<i <<"] : " << A[i] << endl;
    for (int i = 2; i <= N; i+=2)
        A[i] = (-A[i] + MOD) % MOD;
}


matrix createBasicMatrix(){
    // Create the recurrence matrix;
    matrix m (N , vector<ll> (N, 0));
    for (int j = 0; j < N; j++)
        m[0][j] = A[j + 1];

    for (int i = 1; i < N; i++)
        m[i][i -1] = 1;
    return m;
}

void preCompute(ll MAX_LIM){
    // Precompute value of k till 5000
    MAX_LIM = (MAX_LIM > 5000) ? 5000 : MAX_LIM;

    for (ll i = N + 1; i <= MAX_LIM; i++){
        ll rhs = 0;
        ll incr = 1;
        for (ll k = i -1; incr <= N; k--, incr++)
            rhs = (rhs + (A[incr] * Y[k]) % MOD ) % MOD;
        Y[i] = rhs;
    }
}


ll solveMatrixExpo(matrix &m, ll Q){
    // constants are in the array A
    // cout << "\n Q: " << Q << " N: " << N;
    if (Q <= N)
        return Y[Q];

    // cout << "\n Init: " << m;
    matrix k = matpow(m, Q -N);
    // cout << "\n After pow: " << Q - N << " : " << m;
    ll ret = 0;
    for (int i = 0; i < N; i++)
        ret = (ret + k[0][i] * Y[N - i]) % MOD;

    return ret;
}

int main(){
    scanf("%lld", &T);
    while (T--){
        scanf("%lld %lld", &N, &Q);
        ll maxm = -1;

        Y.resize(5002+ 1);
        A.resize(N + 1);
        QQ.resize(Q + 1);

        for (int i = 1; i <= N; i++)
            scanf("%lld", &Y[i]);

        // compute constants
        computeConstants();
        for (int i = 1; i <= Q; i++){
            scanf("%lld", &QQ[i]);
            maxm = max(maxm, QQ[i]);
        }

        matrix m = createBasicMatrix();
        preCompute(maxm);

        for (int i = 1; i <= Q; i++){
            if (QQ[i] <= 5000)
                printf("%lld ", Y[QQ[i]]);
            else printf("%lld ", solveMatrixExpo(m, QQ[i]));
        }

        printf("\n");
    }

    return 0;
}
