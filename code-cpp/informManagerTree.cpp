#include <bits/stdc++.h>

typedef vector<int> vii;
typedef map<int, vii> graph;

int traverse(graph& graph, int node, vector<int>& informTime) {
    //if leaf
    vii children = graph[node];
    if (children.empty()) {
        return informTime[node];
    }
    int maxTime = INT_MIN;
    for (auto child : children) {
        maxTime = max(maxTime, traverse(graph, child, informTime));
    }
    return maxTime + informTime[node];
}

int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
    //build a graph..do a DFS from the tree..
    //maintain max(recursively) and return sun at root
    //ans at leaf = 0
    //ans at non leaf = informTime[node] + max(ans(of its children))
    //return ans[root]
    if (n == 1) {
        return 0;
    }
    vector<int> totalTime(n);
    graph graph;

    for (int i = 0; i < n; i++) {
        //manager[i] is the manager of i which means edge from i to n
        if (manager[i] != -1) {
            if (graph.find(i) == graph.end()) {
                graph[i] = vector<int>();
            }
            graph[manager[i]].push_back(i);
        }
    }
    return traverse(graph, headID, informTime);
    //graph is built..let's traverse
}

int main() {
    // vector<int> manager{3, 3, -1, 2};
    // vector<int> informTime{0, 0, 162, 914};
    // int ans = numOfMinutes(manager.size(), 2, manager, informTime);
    // std::cout << "\nAnswer:" << ans << endl;

    // vector<int> manager{-1, 0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6};
    // vector<int> informTime{1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0};
    // int ans = numOfMinutes(manager.size(), 0, manager, informTime);
    // std::cout << "\nAnswer:" << ans << endl;

    // vector<int> manager{1, 2, 3, 4, 5, 6, -1};
    // vector<int> informTime{0, 6, 5, 4, 3, 2, 1};
    // int ans = numOfMinutes(manager.size(), 6, manager, informTime);
    // std::cout << "\nAnswer:" << ans << endl;

    vector<int> manager{2, 2, -1, 2, 2, 2};
    vector<int> informTime{0, 0, 1, 0, 0, 0};
    int ans = numOfMinutes(manager.size(), 2, manager, informTime);
    std::cout << "\nAnswer:" << ans << endl;
    return 0;
}