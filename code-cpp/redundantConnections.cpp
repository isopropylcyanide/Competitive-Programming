#include <bits/stdc++.h>

#define MAX 10
//basically use union find and at any point, if you see an edge
//that creates a cycle, terminate it

int parent(int node, vector<int> &par) {
    while (par[node] != node) {
        par[node] = par[par[node]];
        node = par[node];
    }
    return node;
}

void unionEdge(int u, int v, vector<int> &par, vector<int> &sz) {
    if (sz[u] < sz[v]) {
        //u should be a child of v
        par[u] = v;
    } else {
        par[v] = u;
    }
}

vector<int> findRedundantConnection(vector<vector<int>> &edges) {
    vector<int> ans;
    vector<int> par(MAX);
    vector<int> sz(MAX, 1);

    for (int i = 0; i < MAX; i++) {
        par[i] = i;
        sz[i] = 1;
    }
    for (auto edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int parU = parent(u, par);
        int parV = parent(v, par);
        if (parU == parV) {
            ans = {u, v};
        } else {
            unionEdge(parU, parV, par, sz);
        }
    }
    return ans;
}

int main() {
    vector<vector<int>> edges = {
        {1, 2},
        {2, 3},
        {3, 4},
        {4, 1},
        {5, 1},
    };
    auto edge = findRedundantConnection(edges);
    std::cout << "[" << edge[0] << ", " << edge[1] << "]" << std::endl;

    return 0;
}