#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
typedef pair<int, int> pii;
typedef map<int, set<int> > graph;
int N, M, u, v, x;
graph g;
vector<int> col, visited;

void addEdge(int u, int v){
    // Adds an undirected edge in the graph
    g[u].insert(v);
    g[v].insert(u);
}

ostream &operator <<(ostream &c, pii &a){
    c << a.first << ", " << a.second;
    return c;
}

void bfs(int node, int color){
    // a node which has an int, and its color
    queue<pii> q;
    q.push(mp(node, color));
    visited[node] = 1;

    while (!q.empty()){
        pii x = q.front();
        q.pop();
        col[x.first] = x.second;

        for (auto neigh : g[x.first]){
            if (!visited[neigh]){
                visited[neigh] = 1;
                q.push(mp(neigh, (x.second + 1) % 2));
            }
        }
    }
}

int main(){
    ios :: sync_with_stdio(0);
    cin.tie(NULL);

    cin >> N >> M;
    col.resize(N + 1);
    visited.resize(N + 1);

    for (int i = 0; i < M; i++){
        cin >> u >> v;
        addEdge(u, v);
    }
    bfs(1, 1);
    for (int i = 1; i <= N; i++)
        cout << col[i] << " ";

    return 0;
}
