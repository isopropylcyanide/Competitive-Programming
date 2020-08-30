#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned ll;
vector<ll> W;
vector<ll> strategicCost;
multiset<ll> S;

void display(){
    cout << "\nW: ";
    for (auto a : W)
        cout << a << " ";
    cout << endl;
}



int main(){
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    ll testcases, N, u, v, w;
    cin >> testcases;

    while(testcases --){
        cin >> N;

        W.resize(N +1);
        strategicCost.resize(N +1);;

        for (ll i = 1; i <= N -1; i++){
            cin >> u >> v >> w;
            W[i] = w;
            S.insert(w);
        }

        strategicCost[1] = *S.rbegin();
        for (ll i = 2; i <= N; i++){
            S.erase(W[i -1]);
            strategicCost[i] = W[i -1] + *S.rbegin();
            S.insert(W[i -1]);
        }
        display();





        for (ll i = 1; i <= N; i++)
            cout << "S[" << i <<"] : " << strategicCost[i] << endl;


    }

    return 0;
}
