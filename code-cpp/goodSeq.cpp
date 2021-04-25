#include <bits/stdc++.h>
using namespace std;

// find the length of the  longest increasing subsequence such that all consecutive
// elements are coprime
typedef long long ll;
#define MAX 10000005

ll N;

ll A[MAX], prime[MAX], d[MAX];

void sieve_min_prime(){
    // Precompute minimum prime of each number
    for (ll i = 2; i < MAX; i++)
        prime[i] = 1;

    for (ll i = 4; i < MAX; i+=2)
        prime[i] = 0;

    for (ll i = 3; i < MAX; i += 2){
        if (prime[i])
            for (ll j = i*i; j < MAX; j+=i)
                prime[j] = 0;
    }
}

int __gcd(int a, int b){
    if (a < b){
        return __gcd(b, a);
    }
    if (b == 0){
        return a;
    }
    return __gcd(b, a % b);
}

ll solveDP(){
    //O(n2) solution
    vector<ll> dp(N, 1);

    for (ll i = 1; i < N; i++){
        for (ll j = 0; j < i; j++){
            if (A[i] > A[j] && __gcd(A[i], A[j]) > 1)
                dp[i] = max(dp[i], 1 + dp[j]);
        }
    }
    return *max_element(dp.begin(), dp.end());
}

ll solveSmart(){
    /* If gcd(ai,aj) > 1: gcd(ai,aj)>1 then aiai and ajaj have a common prime factor. Because of that we will iterate over primes which are factor of a_i.  We will store longest sequence's size for each prime.  Each integer has at most 10 factor primes. So overall complexity is O(N)O(N).
    */
    if (N == 1)
        return 1;

	for(int i = 0; i < N; i++){
		vector<int> v;
		if(prime[A[i]])
            v.push_back(A[i]);

		for(int j = 1; j * j <= A[i]; j++)
			if(A[i] % j == 0){
				if(prime[j])
                    v.push_back(j);
				if(prime[A[i] / j] && j * j != A[i])
                    v.push_back(A[i] / j);
			}

		int ans = 0;
		for(int j = 0; j <v.size(); j++)
            ans = ans > d[v[j]] ? ans : d[v[j]];
		for(int j = 0; j < v.size(); j++)
            d[v[j]] = ans + 1;

	}

	return *max_element(d, d + MAX);
}

int main(){
    sieve_min_prime();

    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> A[i];

    // TLE cout << solveDP() << endl;
    cout << solveSmart() << endl;

}
