#include <bits/stdc++.h>

/*
 * Given a tree of n nodes labelled from 0 to n - 1, and an array of n - 1 edges
 * you can choose any node of the tree as the root. When you select a node x as the root,
 * the result tree has height h. Among all possible rooted trees, those with minimum height
 * (i.e. min(h))  are called minimum height trees (MHTs).
 * 
 * Return a list of all MHTs' root labels. You can return the answer in any order.
 */
typedef pair<int, int> pii;

template <typename T>
ostream& operator<<(ostream& c, vector<T>& vs) {
    for (auto v : vs) {
        c << " -> " << v;
    }
    c << std::endl;
    return c;
}

template <typename T>
ostream& operator<<(ostream& c, map<T, vector<T>>& map) {
    for (auto entry : map) {
        c << " -> " << entry.first << " -> " << entry.second;
    }
    c << std::endl;
    return c;
}

void addNode(int u, int v, map<int, vector<int>>& graph) {
    if (graph.find(u) == graph.end()) {
        graph[u] = vector<int>();
    }
    graph[u].push_back(v);
}

vector<int> findMinHeightTrees(int n, vector<pii>& edges) {
    if (n < 2) {
        return {0, 1};
    }
    map<int, vector<int>> graph;
    vector<int> mhtNodes(n + 1, INT_MAX);
    for (pii edge : edges) {
        int u = edge.first;
        int v = edge.second;
        addNode(u, v, graph);
        addNode(v, u, graph);
    }
    vector<int> leaves;
    for (auto node : graph) {
        if (node.second.size() == 1) {
            leaves.push_back(node.first);
        }
    }
    while (n > 2) {
        n = n - leaves.size();
        //remove all leaves level by level
        //if you create a new leaf in this process, add it again
        vector<int> newLeaves;

        for (int i = 0; i < leaves.size(); i++) {
            int leaf = leaves[i];
            int node = graph[leaf][0];
            std::vector<int>::iterator position = std::find(graph[node].begin(), graph[node].end(), leaf);
            if (position != graph[node].end()) {
                graph[node].erase(position);
            }
            if (graph[node].size() == 1) {
                newLeaves.push_back(node);
            }
        }
        leaves = newLeaves;
    }
    return leaves;
}

int main() {
    vector<pii> edges;
    edges.push_back(make_pair(0, 1));
    edges.push_back(make_pair(1, 2));
    edges.push_back(make_pair(2, 3));
    edges.push_back(make_pair(1, 4));
    edges.push_back(make_pair(4, 5));

    // edges.push_back(make_pair(0, 1));
    // edges.push_back(make_pair(1, 2));
    // edges.push_back(make_pair(1, 3));
    vector<int> nodes = findMinHeightTrees(4, edges);

    std::cout << nodes << endl;
    return 0;
}
