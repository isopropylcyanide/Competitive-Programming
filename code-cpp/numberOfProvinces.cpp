#include <bits/stdc++.h>

ostream &operator<<(ostream &c, vector<int> &T) {
    for (auto t : T) {
        c << t << " ";
    }
    return c;
}

int root(int node, vector<int> &par) {
    while (par[node] != node) {
        par[node] = par[par[node]];
        node = par[node];
    }
    return node;
}

void unionNode(int nodeA, int nodeB, vector<int> &par, vector<long long unsigned> &size) {
    int rootA = root(nodeA, par);
    int rootB = root(nodeB, par);
    if (size[rootA] < size[rootB]) {
        par[rootA] = rootB;
        size[rootB] += size[rootA];
    } else {
        par[rootB] = rootA;
        size[rootA] += size[rootB];
    }
}

int findCircleNum(vector<vector<int>> &graph) {
    //maintain a parent array set to i?
    int n = graph.size();
    vector<int> par(n, 0);
    vector<long long unsigned> size(n, 1);
    for (int i = 0; i < n; i++) {
        par[i] = i;
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (graph[i][j]) {
                unionNode(i, j, par, size);
            }
        }
    }
    int provinces = 0;
    for (int i = 0; i < n; i++) {
        if (par[i] == i) {
            provinces += 1;
        }
    }
    std::cout << par << endl;
    return provinces;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    vector<vector<int>> graph = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}};

    vector<vector<int>> graph_1 = {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}};

    vector<vector<int>> graph_2 = {
        {1, 0, 0, 1},
        {0, 1, 1, 0},
        {0, 1, 1, 1},
        {1, 0, 1, 1}};

    // std::cout << findCircleNum(graph) << endl;
    // std::cout << findCircleNum(graph_1) << endl;
    std::cout << findCircleNum(graph_2) << endl;

    return 0;
}
