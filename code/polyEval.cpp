#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned ll;
#define MOD 786433
#define MAX 786435

//You are given a polynomial of degree N with integer coefficients. Your task is to find the value of this polynomial at some K different integers, modulo 786433.

ll N, Q, X;
vector<ll> A;
ll POWER_TWO[MAX];

void display(vector<ll> &ret){
    //Display
    cout << endl;
    for (auto a : ret)
    cout << " -> " << a;
    cout << endl;
}

ll fast_pow(ll a, ll b) {
    // Computes fast modular exponentiation
    ll x = 1, y = a;
    while(b > 0) {
        if(b % 2 == 1)
        x = (x * y) % MOD;
        y = (y * y) % MOD;
        b /= 2;
    }
    return x;
}

void precompute(){
    // Precomputes : A[i] = (A[i] ** 2 ) % MOD
    POWER_TWO[0] = 0, POWER_TWO[1] = 1;
    for (int i = 2; i < MAX; i++)
        POWER_TWO[i] = fast_pow(i, 2);
}



ll estrin(ll X){
    // Estrin's method for fast evaluation
    // cout << "\n Mod coeff: \n";
    ll nn = N >> 1;
    vector<ll> ret(nn);

    for (int k = 0; k < nn; k++){
        ll k2 = 2 * k + 1;
        ret[k] =((X * A[k2]) % MOD + A[k2 -1]) % MOD;
    }
    // display(ret);

    X = POWER_TWO[X];
    nn >>= 1;

    while (nn){
        for (int k = 0; k < nn; k++){
            ll k2 = 2 * k + 1;
            ret[k] = ((X * ret[k2]) % MOD + ret[k2 -1]) %MOD;
        }
        X = POWER_TWO[X];
        nn >>= 1;
        // display(ret);
    }

    return ret[0];
}

int main(){
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    precompute();

    cin >> N;
    N ++;
    A.resize(N) ;
    for (int i = 0; i < N; i++)
        cin >> A[i];

    cin >> Q;

    ll nextPow = pow(2, int(ceil(log2(N))));
    for (int i = 0; i < nextPow - N; i++)
        A.push_back(0);
    N = nextPow;

    while (Q--){
        cin >> X;
        if (N == 1)
            cout << A[0] << endl;
        else
            cout << estrin(X) << endl;
    }
    return 0;
}
