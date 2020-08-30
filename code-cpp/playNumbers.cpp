#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define MAX  500005
#define inf 0x7fffffff

typedef long long int ll;

//Q Queries. Increment A by K and find the absolute sum
ll N, Q, temp,K;

void bruteSum(const ll& temp, vector <ll> &A){
    transform(A.begin(), A.end(), A.begin(), bind2nd(plus<ll>(),temp) );
    cout << accumulate(A.begin(),A.end(),0,[](ll acc, ll i){ return acc + abs(i); }) << endl;
}


int main(){
    ios::sync_with_stdio(false);

    cin >> N;
    vector<ll> A(N);


    for (ll i = 0; i < N; i++)
        cin >> A[i];

    sort(A.begin(), A.end());
    vector<ll> prefix(N + 1, 0);

    for (ll i = 0; i < N; i++)
        prefix[i +1] = prefix[i] + A[i];

    cin >> Q;
    ll add_delta = 0;

    for (ll i = 0; i < Q; i++){
        cin >> temp;
        add_delta += temp;

        // Binary search 
        K = lower_bound(A.begin(), A.end(), -add_delta) - A.begin();

        ll ans = 0;
        ans += (prefix[N] - prefix[K]) + add_delta * (N - K);

        ans += -((prefix[K] - prefix[0]) + add_delta * K);

        cout << ans << endl;
    }



    return 0;
}