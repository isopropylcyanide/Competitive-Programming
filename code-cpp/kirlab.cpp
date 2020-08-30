#include <bits/stdc++.h>
using namespace std;

#define MAX 10000005
typedef long long ll;
ll T, N, x;
ll prime[MAX];
ll minprime[MAX];
ll m[MAX];

void sieve_min_prime(){
    // Precompute minimum prime of each number
    for (ll i = 2; i < MAX; i++){
        prime[i] = 1;
        minprime[i] = i;
    }
    for (ll i = 4; i < MAX; i+=2){
        prime[i] = 0;
        minprime[i] = 2;
    }
    for (ll i = 3; i < MAX; i += 2){
        if (prime[i]){
            for (ll j = i*i; j < MAX; j+=i){
                prime[j] = 0;
                if (minprime[j] == j)
                    minprime[j] = i;
            }
        }
    }
}

set<ll> factorization(ll x){
	/*Once we have the minimum prime we can have others easily*/
	set<ll> fact;
	while (minprime[x]>0){
		fact.insert(minprime[x]);
		x /= minprime[x];
	}

	fact.insert(x);
	return fact;
}

void insertUpdate(ll num){
    // inserts and updates map with the prime factors of num
    if (num == 1)
        return;

    set<ll> facts = factorization(num);
    ll maxVal = 0;
    for (auto factor: facts){
        if (m[factor] != 0 && factor != 1)
            maxVal = max(maxVal, m[factor]);
    }
    for (auto factor: facts)
        m[factor] = maxVal + 1;
}

int main(){
    sieve_min_prime();
    scanf("%lld", &T);
    while (T--){
        scanf("%lld", &N);
        for (int i = 0; i < MAX; i++)
            m[i] = 0;

        for (int i = 0; i < N; i++){
            cin >> x;
            insertUpdate(x);
        }

        ll maxElem = 1;
        for (int i = 0; i < MAX; i++)
            maxElem = max(maxElem, m[i]);

        printf("%lld\n", maxElem);
    }

    return 0;
}
