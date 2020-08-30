#include <bits/stdc++.h>
using namespace std;

vector< list< pair<int, int> >> adj;

int dfsSum(int i, vector<bool> &V, int maxSum){
    if (V[i])
        return maxSum;

    V[i] = true;
    for (auto edge: adj[i]){
        if (V[edge.first] == false)
            return dfsSum(edge.first, V, maxSum + edge.second);
    }
    return maxSum;
}

int main(){

    int testcases, V, E;
    int u, v, w;

    cin >> testcases;
    while (testcases--){

        cin >> V >> E;
        adj.resize(V);

        for (int edge = 0; edge < 3 * E; edge += 3){
            cin >> u >> v >> w;
            adj[u].push_back(make_pair(v, w));
            adj[v].push_back(make_pair(u, w));
        }


        vector<bool> visited(V, false);
        int maxSum = dfsSum(0, visited, 0);

        if (maxSum >= 8)
            cout << 1 << endl;
        else
            cout << 0 << endl;
        adj.clear();
        visited.clear();
    }


    return 0;
}
