#include <bits/stdc++.h>

#define MAX 100000
//basically use union find and at any point, if you see an edge
//that creates a cycle, terminate it

int parent(int node, vector<int> &par) {
    while (par[node] != node) {
        par[node] = par[par[node]];
        node = par[node];
    }
    return node;
}

vector<int> findRedundantDirectedConnection(vector<vector<int>> &edges) {
    int n = edges.size();
    vector<int> par(n + 1, 0), candA, candB;
    // step 1, check whether there is a node with two parents
    for (auto &edge : edges) {
        if (par[edge[1]] == 0)
            par[edge[1]] = edge[0];
        else {
            candA = {par[edge[1]], edge[1]};
            candB = edge;
            edge[1] = 0;
        }
    }
    // step 2, union find
    for (int i = 1; i <= n; i++) {
        par[i] = i;
    }
    for (auto &edge : edges) {
        if (edge[1] == 0) {
            continue;
        }
        int u = edge[0], v = edge[1], parU = parent(u, par);
        // Now every node only has 1 parent, so root of v is implicitly v
        if (parU == v) {
            if (candA.empty()) return edge;
            return candA;
        }
        par[v] = parU;
    }
    return candB;
}

int main() {
    vector<vector<int>> edges = {
        {1, 2},
        {2, 3},
        {3, 4},
        {4, 1},
        {5, 1},
    };
    auto edge = findRedundantDirectedConnection(edges);
    std::cout << "[" << edge[0] << ", " << edge[1] << "]" << std::endl;

    return 0;
}