#include <bits/stdc++.h>
using namespace std;

#define MAX 100005
vector<int> adj[MAX];

bool vis[MAX];
int N, M, u, v, edges = 0;

void dfs(int i){
    vis[i] = 1;
    for (auto k : adj[i]){
        edges ++;
        if (!vis[k])
            dfs(k);
    }
}

int main(){
    ios :: sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    while (M--){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int maxVal = 0;
    for (int i = 1; i <= N; i++){
        if (!vis[i])
            dfs(i);
        maxVal = max(maxVal, edges/2);
        edges = 0;
    }
    cout << maxVal << "\n";
    return 0;
}
