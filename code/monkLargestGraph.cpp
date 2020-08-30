#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

vector< vector<pll>> gg;
ll N, M, K, a, b, x;
vector<ll> A;

int main(){
    ios :: sync_with_stdio(false);
    cin >> N >> M >> K;

    A.resize(N + 1);
    gg.resize(N + 1);
    for (int i = 1; i <= N; i++)
        cin >> A[i];

    while (M--){
        cin >> a >> b;
        gg[a].push_back(make_pair(-A[b], -b));
        gg[b].push_back(make_pair(-A[a], -a));
    }


    for (int i = 1; i <= N; i++){
        ll adj = gg[i].size();
        if (K > adj)
            cout << "-1\n";
        else {
            sort(gg[i].begin(), gg[i].end());
            cout << -(gg[i][K -1].second) << "\n";
        }
            // cout << -(*g[i].find_by_order(K -1)).second << "\n";
    }
    return 0;
}
