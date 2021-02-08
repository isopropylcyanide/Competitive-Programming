#include <bits/stdc++.h>

/*
 * There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. 
 * You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you 
 * must take course bi first if you want to take course ai.
 * (containing at least one number) which has the largest
 * 
 * For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
 */

template <typename T>
ostream& operator<<(ostream& c, vector<T>& vs) {
    for (auto v : vs) {
        c << " -> " << v;
    }
    c << std::endl;
    return c;
}

typedef map<int, vector<int>> graph;

bool hasCycle(graph& g, vector<bool>& secondPass, vector<bool>& firstPass, int node) {
    if (secondPass[node]) {
        //what? again::cycle
        return true;
    }
    if (firstPass[node]) {
        //we have probably seen this
        return false;
    }
    firstPass[node] = true;
    secondPass[node] = true;
    for (int v : g[node]) {
        if (hasCycle(g, secondPass, firstPass, v)) {
            return true;
        }
    }
    secondPass[node] = false;
    return false;
}

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    graph graph;
    for (auto edge : prerequisites) {
        int u = edge[0], v = edge[1];
        graph[u].push_back(v);
    }
    vector<bool> secondPass(numCourses, false);
    vector<bool> firstPass(numCourses, false);

    for (int i = 0; i < numCourses; i++) {
        if (!firstPass[i] && hasCycle(graph, secondPass, firstPass, i)) {
            return false;
        }
    }
    return true;
}

bool canFinishBFS(int numCourses, vector<vector<int>>& prerequisites) {
    //each node says who all point to it
    graph graph;
    vector<int> degrees(numCourses + 1, 0);
    for (auto edge : prerequisites) {
        int u = edge[0], v = edge[1];
        graph[v].push_back(u);
        degrees[u] += 1;
    }
    queue<int> sinkNodes;

    for (int i = 0; i < numCourses; i++) {
        if (degrees[i] == 0) {
            sinkNodes.push(i);
        }
    }
    while (!sinkNodes.empty()) {
        int node = sinkNodes.front();
        sinkNodes.pop();
        numCourses -= 1;
        for (auto parent : graph[node]) {
            //reduce their indegree.. if zero, add it to queue
            degrees[parent] -= 1;
            if (degrees[parent] == 0) {
                sinkNodes.push(parent);
            }
        }
    }
    return numCourses == 0;
}

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    //each node says who all point to it
    graph graph;
    vector<int> degrees(numCourses + 1, 0);
    for (auto edge : prerequisites) {
        int u = edge[0], v = edge[1];
        graph[v].push_back(u);
        degrees[u] += 1;
    }
    queue<int> sinkNodes;
    vector<int> sortedOrder;

    for (int i = 0; i < numCourses; i++) {
        if (degrees[i] == 0) {
            sinkNodes.push(i);
        }
    }
    while (!sinkNodes.empty()) {
        int node = sinkNodes.front();
        sinkNodes.pop();
        sortedOrder.push_back(node);
        numCourses -= 1;
        for (auto parent : graph[node]) {
            //reduce their indegree.. if zero, add it to queue
            degrees[parent] -= 1;
            if (degrees[parent] == 0) {
                sinkNodes.push(parent);
            }
        }
    }
    if (numCourses != 0) {
        return {};
    }
    return sortedOrder;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    // vector<vector<int>> preReqs = {{1, 0}, {0, 1}};
    // vector<vector<int>> preReqs = {{1, 0}};
    // vector<vector<int>> preReqs = {
    //     {1, 2},
    //     {0, 2},
    //     {5, 6},
    //     {6, 7},
    //     {8, 7},
    //     {3, 4},
    //     {4, 6},
    //     {7, 4}};
    vector<vector<int>> preReqs = {
        {1, 0},
        {3, 1},
        {3, 2},
        {2, 0}
        // {3, 2}
    };
    std::cout << canFinishBFS(5, preReqs) << std::endl;
    vector<int> order = findOrder(5, preReqs);
    std::cout << order << std::endl;
    return 0;
}
