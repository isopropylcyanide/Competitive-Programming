#include <bits/stdc++.h>
using namespace std;

#define MAX 100005
typedef long long ll;
ll A[MAX];
vector<ll> G[MAX];

void clearGraph(){
    for (auto nodeList : G){
        std::fill(nodeList.begin(), nodeList.end(), 0);
    }
}

ostream & operator<<(ostream &c, vector<ll> &T){
    for (auto t : T){
        c << t << " ";
    }
    return c;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    ll testcases, N, X, u, v, tmp;

    cin >> testcases;
    while (testcases --){
        cin >> N >> X;
        for (int i = 1; i <= N; i++){
            cin >> A[i];
        }
        clearGraph();

        for (int i = 0; i < N -1; i++){
            cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
    }
    return 0;
}