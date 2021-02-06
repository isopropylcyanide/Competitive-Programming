#include <bits/stdc++.h>

/*
 * Given an undirected tree, return its diameter: the number of edges in a 
 * longest path in that tree.
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

void calculateDownPaths(int node, int par, int height, vector<int>& downPaths, map<int, vector<int>>& graph) {
    //downpath is the max downpath amongst all of its children..don't go back to par
    int bestChildDownPath = 0;
    bool isLeaf = true;
    for (auto child : graph[node]) {
        if (child != par) {
            isLeaf = false;
            calculateDownPaths(child, node, height + 1, downPaths, graph);
            bestChildDownPath = max(bestChildDownPath, downPaths[child]);
        }
    }
    //if node is a leaf, then no downpath
    downPaths[node] = isLeaf ? 0 : 1 + bestChildDownPath;
}

void calculateDiameters(int node, int par, map<int, vector<int>>& graph, vector<int>& downPaths, vector<int>& diameters) {
    //either the path goes through the node or it doesn't
    //let's say it doesn't..then the answer is
    //the max across all of its children
    //else its 2 + top 2 downpath amongst its nodes
    int bestDiameterWhenPathDoesnotCross = 0;
    vector<int> downPathChildren;

    for (auto child : graph[node]) {
        if (child != par) {
            calculateDiameters(child, node, graph, downPaths, diameters);
            downPathChildren.push_back(downPaths[child]);
            bestDiameterWhenPathDoesnotCross = max(bestDiameterWhenPathDoesnotCross, diameters[child]);
        }
    }
    //if the path does cross, then we need to sort the downpaths of its children
    //and take the top 2. If 2 aren't available take only 1. Duh.
    int numChild = downPathChildren.size();
    sort(downPathChildren.begin(), downPathChildren.end(), std::greater<int>());

    if (numChild == 0) {
        //leaf
        diameters[node] = 0;
    } else if (numChild == 1) {
        diameters[node] = 1 + downPathChildren[0];
    } else {
        diameters[node] = 1 + downPathChildren[0] + 1 + downPathChildren[1];
    }
    diameters[node] = max(diameters[node], bestDiameterWhenPathDoesnotCross);
    std::cout << "Answer for node: " << node << " : " << diameters[node] << endl;
    //if it doesn't, we have to find the max downpath amongst all children
}

int treeDiameter(vector<pii>& edges) {
    map<int, vector<int>> graph;
    int maxNumberedNode = -1;
    for (pii edge : edges) {
        int u = edge.first;
        int v = edge.second;
        addNode(u, v, graph);
        addNode(v, u, graph);
        maxNumberedNode = max(maxNumberedNode, u);
        maxNumberedNode = max(maxNumberedNode, v);
    }
    int n = maxNumberedNode + 1;
    //root tree at 0 and find the answer
    //calculate downpath at each node: precompute it
    vector<int> downPaths(n, 0);
    calculateDownPaths(0, -1, 0, downPaths, graph);
    std::cout << "Downpaths : " << downPaths << endl;

    vector<int> diameters(n, 0);
    calculateDiameters(0, -1, graph, downPaths, diameters);
    return diameters[0];
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    vector<pii> edges;
    edges.push_back(make_pair(0, 1));
    edges.push_back(make_pair(1, 2));
    edges.push_back(make_pair(2, 3));
    edges.push_back(make_pair(1, 4));
    edges.push_back(make_pair(4, 5));

    // edges.push_back(make_pair(0, 1));
    // edges.push_back(make_pair(0, 2));

    std::cout << treeDiameter(edges) << std::endl;
    return 0;
}
