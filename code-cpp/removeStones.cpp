#include <bits/stdc++.h>

#define MAX 10000
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

int removeStones(vector<vector<int>> &stones) {
    int N = stones.size();
    vector<int> ans;
    vector<int> par(2 * MAX);
    vector<int> sz(2 * MAX, 1);

    for (int i = 0; i < MAX; i++) {
        par[i] = i;
    }
    for (auto edge : stones) {
        int u = edge[0];
        int v = edge[1] + MAX;
        int parU = parent(u, par);
        int parV = parent(v, par);
        unionEdge(parU, parV, par, sz);
    }
    set<int> rootsOfConnected;

    for (auto edge : stones) {
        int u = edge[0];
        int root = parent(edge[0], par);
        std::cout << "For " << edge[0] << " parent: " << root << endl;
        rootsOfConnected.insert(root);
    }

    return N - rootsOfConnected.size();
}

int main() {
    vector<vector<int>> stones = {
        {0, 0},
        {0, 2},
        {1, 1},
        {2, 0},
        {2, 2},
    };
    std::cout << removeStones(stones) << std::endl;

    return 0;
}
