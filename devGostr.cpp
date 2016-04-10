#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned ll;
#define MOD 1000000007

/*Fast ncR module : Lucas Theorem*/
ll SmallC(int n, int r){
	vector< vector<ll> > C(2,vector<ll> (r+1,0));

	for (int i=0; i<=n; i++){
		for (int k=0; k<=r && k<=i; k++)
			if (k==0 || k==i)
				C[i&1][k] = 1;
			else
				C[i&1][k] = (C[(i-1)&1][k-1] + C[(i-1)&1][k])%MOD;
	}
	return C[n&1][r];
}

ll Lucas(int n, int m){
	if (n==0 && m==0) return 1;
	int ni = n % MOD;
	int mi = m % MOD;
	if (mi>ni) return 0;
	return Lucas(n/MOD, m/MOD) * SmallC(ni, mi);
}

ll nCr(int n, int r){
	return Lucas(n, r);
}

ll fastPower(ll b, ll e){
    ll remainder;
    ll x = 1;

    while (e != 0){
    remainder = e % 2;
    e= e/2;

    if (remainder == 1)
        x = (x * b) % MOD;
        b= (b * b) % MOD; // New base equal b^2 % m
    }
    return x;
}

ll hamming(string& s1,string& s2){
    return inner_product(s1.begin(), s1.end(), s2.begin(),
        0, plus<ll>(),
        not2(equal_to<string::value_type>())
    );
}



int main(){
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    ll testcases, A, K;
    string s;
    cin >> testcases;

    while (testcases--){
        cin >> A >> K;
        cin >> s;

        if (A == 1){ //no need for good strings check if size >= 3
            if (s.size() >= 3)
                cout << 0 << endl;
            else{
                string allA = string(s.size(), 'a');
                ll curDist = hamming(s, allA);

                if (curDist <= K)
                    cout << 1 << endl;
                else
                    cout << 0 << endl;
            }
        }

        else if (A == 2){
            ll m = count(s.begin(), s.end(), 'a') + count(s.begin(), s.end(), 'b');
            ll n = s.size() - m;

            if (n > K)
                cout << 0 << endl;
            else {
                //total string with hamming dist i , i <= k
                ll curNoAPSum = 0;
                ll expFactor = fastPower(2, n);

                for (ll i = n; i <= K; i++)
                    curNoAPSum = (curNoAPSum % MOD + nCr(m, i - n) % MOD) % MOD;

                curNoAPSum = (curNoAPSum * expFactor) % MOD;
                cout << curNoAPSum << endl;
            }
        }

        else
            cout << K << endl;

    }


    return 0;
}
