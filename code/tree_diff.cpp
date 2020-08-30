#include <bits/stdc++.h>
#include <iostream>
#define MAX 100001
using namespace std;

int value[MAX];
vector<bool> visited(MAX, false);
vector<int> sum(MAX, 0);
int nodes;

auto lambda = [] (auto x, auto y) { return x + y; };

int dfs(int node, vector<vector<int> >& graph) {
        int ret = 0;
        visited[node] = true;

        for (int i = 0; i < signed(graph[node].size()); i++) {
                int next = graph[node][i];
                if (visited[next] == false) ret += dfs(next, graph);
        }
        return sum[node] = value[node] + ret;
}

int main() {
        ios::sync_with_stdio(false);

        int x, y, total = 0;
        cin >> nodes;
        int high = INT_MAX;

        for (int i = 1; i <= nodes; i++) {
                cin >> value[i];
                total += value[i];
        }

        vector<vector<int> > graph;
        graph.resize(nodes + 1);

        for (int i = 1; i < nodes; i++) {
                cin >> x >> y;
                graph[x].push_back(y);
                graph[y].push_back(x);
        }
        dfs(1, graph);

        for (int i = 1; i <= nodes; i++) {
                if (abs(total - 2 * sum[i]) < high) high = abs(total - 2 * sum[i]);
        }

        cout << high << endl;
        return 0;
}
