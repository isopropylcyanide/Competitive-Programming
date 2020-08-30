#include <bits/stdc++.h>
using namespace std;

#define N 9

// Finding shortest path in a graph represented using adjacency list using Dijsktra's
// algo. It finds shortest path from source v to all other nodes

//Stores source : (end, weight)
vector<vector<pair<int, int>>> adjList;

void addEdge(int s, int e, int w){
    adjList[s].push_back(make_pair(e, w));
    adjList[e].push_back(make_pair(s, w));
}

void findPath(vector<int> &parent, int s){
    if (parent[s] == s){
        cout << s << " -> ";
        return;
    }
    findPath(parent, parent[s]);
    cout << s << " -> ";
}

void dijkstra_singleSource(int source){
    // Output shortest distances from this source to all vertices

    // to store the parent v of each in shortest path
    vector<int> parent(N);
    for (int i = 0; i < N; i++)
        parent[i] = i; //initially all are their own parent

    vector<int> dist(N, INT_MAX); //all are unreachable
    // except for first;
    dist[source] = 0;

    set<pair<int, int>> mSet;
    // A set that acts as a minHeap consisting of the weight and vertex.
    mSet.insert(make_pair(0, source));

    while (!mSet.empty()){
        pair<int, int> minEdge = *mSet.begin();
        mSet.erase(mSet.begin());
        int u = minEdge.second;

        for (auto adj : adjList[u]){
            int v = adj.first, wt = adj.second;
            if (dist[v] > dist[u] + wt){
                // if dist[v] is not INT_MAX, find and remove it
                if (dist[v] != INT_MAX)
                    mSet.erase(mSet.find(make_pair(dist[v], v)));

                parent[v] = u;
                dist[v] = dist[u] + wt;
                mSet.insert(make_pair(dist[v], v));
            }
        }
    }

    cout << "\n SHORTEST DISTANCE FROM v: " << source << endl;
    for (int i =  0; i < N; i++){
        cout << "\nTo v : " << i << " : " << dist[i];
        cout << "\t";
        findPath(parent, i);
    }
    cout << endl;
}


int main(){
    adjList.resize(N);
    addEdge(0, 1, 4); addEdge(0, 7, 8); addEdge(1, 2, 8);
    addEdge(1, 7, 11);addEdge(2, 8, 2); addEdge(2, 5, 4);
    addEdge(2, 3, 7); addEdge(8, 7, 7); addEdge(8, 6, 6);
    addEdge(6, 7, 1); addEdge(6, 5, 2); addEdge(3, 5, 14);
    addEdge(3, 4, 9); addEdge(5, 4, 10);

    dijkstra_singleSource(0);

    return 0;
}
