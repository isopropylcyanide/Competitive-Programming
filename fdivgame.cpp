#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll N;
vector<ll> A;



int main(){
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    ll tests, temp;
    cin >> tests;

    while (tests --){
        cin >> N;
        A.resize(N, 0);
        for (ll i = 0; i < N; i++){
            cin >> temp;
            A.push_back(temp);
        }
    }
    return 0;
}
