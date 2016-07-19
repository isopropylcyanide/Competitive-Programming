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
    //To Display the vec Smh!
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

int getLength(long long int value) {
	int counter = 0;
	while (value != 0) {
		counter++;
		value /= 10;
	}
	return counter;
}

ll multiply(ll x, ll y) {
    // KaratSuba multiplication
	int xLength = getLength(x);
	int yLength = getLength(y);

	// the bigger of the two lengths
	int N = (int)(fmax(xLength, yLength));

	// if the max length is small it's faster to just flat out multiply the two nums
	if (N < 10)
		return x * y;

	//max length divided and rounded up
	N = (N/2) + (N%2);

	ll multiplier = fast_pow(10, N);

	ll b = x/multiplier;
	ll a = x - (b * multiplier);
	ll d = y / multiplier;
	ll c = y - (d * N);

	ll z0 = multiply(a,c);
	ll z1 = multiply(a + b, c + d);
	ll z2 = multiply(b, d);


    return z0 + ((z1 - z0 - z2) * multiplier) + (z2 * (ll)(fast_pow(10, 2 * N)));

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

    // Precompute answer for all values
    // precomputes();
    ll ANS[MAX];
    for (int k = 1; k < MAX; k++){
        ll ans = A[N -1];
        for (int i = N - 2; i >= 0; i--){
            ans = multiply(ans, k);
            ans = (ans + A[i]) % MOD;
        }
        ANS[k] = ans;
    }
    // printf("\ndone\n");

    cin >> Q;
    while (Q--){
        cin >> X;
        cout << ANS[X] << endl;
    }
    return 0;
}
