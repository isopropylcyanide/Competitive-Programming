#include <bits/stdc++.h>
using namespace std;


void shortestDist(int S, vector<list<int> >& adj){
    // print shortest distance of each from source vertex
    int N = adj.size();
    vector<int> depth (N, -1);
    // initially no vertex is reachable

    vector<bool> visited (N, false);
    queue<int> q;
    q.push(S);
    visited[S] = true;
    depth[S] = 0;

    while (!q.empty()){

        int curNode = q.front();
        q.pop();

        for (auto node : adj[curNode]){
            if (!visited[node]){
                visited[node] = true;
                q.push(node);
                depth[node] = depth[curNode] + 1;
            }
        }
    }

    for (int i = 0; i < N; i++){
        if (i != S){
            int dist = depth[i] == -1 ? -1 : depth[i] * 6;
            cout << dist << " ";
        }
    }

}

int main(){
    int testcases, N, M, x, y, S;
    cin >> testcases;

    while (testcases --){
        cin >> N >> M;
        vector<list<int> > adj(N);

        for(int i = 1; i <= M; i++){
            cin >> x >> y;
            adj[x -1].push_back(y -1);
            adj[y -1].push_back(x -1);
        }

        cin >> S;
        shortestDist(--S, adj);
        cout << endl;
    }

}
