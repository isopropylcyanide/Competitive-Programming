#include <bits/stdc++.h>
using namespace std;

#define MAX 100005
typedef long long  ll;

ll L, R;
vector<ll> P(MAX);


ll func(ll N){
    // bool odd = N & 1;
    ll F = 0;

    for (ll i = 1; i * i <= N; i++){
        if (N % i == 0){
                F += int(pow(-1, N/i)) * i;
            if (i != N/i)
                F += int(pow(-1, i)) * (N/i);
        }
    }
    return -F;
}

int main(){
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 1; i <= MAX; i++)
        P[i] = func(i);


    ll testcases;
    cin >> testcases;
    while (testcases --){
        cin >> L >> R;

        ll ans = 0;
        for (int i = L; i <= R; i++)
            ans += P[i];
        cout << ans << endl;
    }
}
