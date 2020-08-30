#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned ll;
typedef pair<ll, ll> pll;
typedef map<ll, set<ll> > graph;

set<ll> visited;
graph g;
ll K, p, r, u, v;
vector<pll> fact;
vector<ll> divs, path;


void setDivisors(ll n, int i) {
    // Find divisors from prime factorisation
    ll j, x, k;
    for (j = i; j < fact.size(); j++) {
        x = fact[j].first * n;
        for (k = 0; k < fact[j].second; k++) {
            divs.push_back(x);
            setDivisors(x, j + 1);
            x *= fact[j].first;
        }
    }
}

void addEdge(ll u, ll v){
    // Adds an undirected edge in the graph

    g[u].insert(v);
    g[v].insert(u);
}

void dfs(ll node){
    if (visited.find(node) != visited.end())
        return;
    visited.insert(node);
    path.push_back(node);
    for (auto ch : g[node]){
        if (visited.find(ch) == visited.end())
            dfs(ch);
    }
}

void createGraph(){
    // Creates graph. Add edge if they divide each other
    ll n = divs.size();
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            if (divs[j] % divs[i] == 0)
                addEdge(divs[i], divs[j]);
        }
    }
}


int main(){
    scanf("%lld", &K);
    for (int i = 0; i < K; i++){
        scanf("%lld %lld",&u, &v);
        fact.push_back(make_pair(u, v));
    }

    setDivisors(1, 0);
    divs.push_back(1);
    sort(divs.begin(), divs.end());

    createGraph();

    dfs(1);
    if (path.size() == divs.size()){
        for (auto p : path)
            printf("%lld ", p);
        printf("\n");
    }
    else printf("No\n");

    return 0;
}
