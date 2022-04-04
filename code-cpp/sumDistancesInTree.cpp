#include<bits/stdc++.h>

using namespace std;

/**
 * You are given the integer n and the array edges where edges[i] = [ai, bi] indicates that
 * there is an edge between nodes ai and bi in the tree.
 *
 * Return an array answer of length n where answer[i] is the sum of the distances between the
 * ith node in the tree and all other nodes.
 */

vector<list<int>> g; // adjacency list
vector<int> subtreeSize; // size of subtree rooted at this node
vector<int> subtreeAns; // distance of each child
vector<int> ans;

void dfsBottom(int node, int parent) {
    for (auto child: g[node]) {
        if (child != parent) {
            dfsBottom(child, node);
            subtreeSize[node] += subtreeSize[child];
            subtreeAns[node] += subtreeAns[child] + subtreeSize[child];
        }
    }
    subtreeSize[node] = subtreeSize[node] + 1; // include the actual node
}

void dfsTop(int node, int parent, int partialParWRTNode, int n) {
    // this routine solves: if we re root the tree at a node, what is the answer then?
    // ans[node] = answer for its subtree + partial answer for its parent wrt node + node - subtree size
    ans[node] = subtreeAns[node] + partialParWRTNode + (n - subtreeSize[node]);
    for (auto child: g[node]) {
        if (child != parent) {
            int partial = ans[node] - (subtreeAns[child] + subtreeSize[child]);
            dfsTop(child, node, partial, n);
        }
    }
}

vector<int> sumOfDistancesInTree(int n, vector<vector<int>> &edges) {
    g.resize(n);
    ans.resize(n);
    subtreeSize.resize(n);
    subtreeAns.resize(n);

    // can create a graph first
    for (auto edge: edges) {
        // insert edge u <-> v
        int u = edge[0];
        int v = edge[1];
        g[u].push_back(v);
        g[v].push_back(u);
    }

    // dfs from bottom up
    dfsBottom(0, 0);

    // dfs from top down (after re-rooting)
    dfsTop(0, 0, 0, n);

    return ans;
}

void reset() {
    g.clear();
    subtreeSize.clear();
    subtreeAns.clear();
    ans.clear();
}

int main() {
    vector<vector<int>> edges = {{0, 1},
                                 {0, 2},
                                 {2, 3},
                                 {2, 4},
                                 {2, 5}};
    auto distances = sumOfDistancesInTree(6, edges);
    for (int i = 0; i < distances.size(); i++) {
        std::cout << "Sum distance of all child nodes from " << i << " : " << distances[i] << endl;
    }

    std::cout << "\n*****************" << endl;
    reset();
    edges = {{0, 1},
             {0, 2},
             {2, 3},
             {2, 4}};
    distances = sumOfDistancesInTree(5, edges);
    for (int i = 0; i < distances.size(); i++) {
        std::cout << "Sum distance of all child nodes from " << i << " : " << distances[i] << endl;
    }

    /**
     *        0
             / \
            3   4
           / \
          2   1

     */
    std::cout << "\n*****************" << endl;
    reset();
    edges = {{0, 3},
             {3, 2},
             {3, 1},
             {0, 4}};
    distances = sumOfDistancesInTree(5, edges);
    for (int i = 0; i < distances.size(); i++) {
        std::cout << "Sum distance of all child nodes from " << i << " : " << distances[i] << endl;
    }


    /**

               0
             / | \
            3  4  5
           / \
          2   1

    From 0: dist(3) + dist(4) + dist(2) + dist(1) + dist(5) = 1 + 1 + 2 + 2 + 1 = 7
    ...
    From 1: dist(3) + dist(2) + dist(0) + dist(4) + dist(5) = 1 + 2 + 2 + 3 + 3 = 11
    */
    
    std::cout << "\n*****************" << endl;
    reset();
    edges = {{0, 3},
             {3, 2},
             {3, 1},
             {0, 5},
             {0, 4}};
    distances = sumOfDistancesInTree(6, edges);
    for (int i = 0; i < distances.size(); i++) {
        std::cout << "Sum distance of all child nodes from " << i << " : " << distances[i] << endl;
    }


    return 0;
}
