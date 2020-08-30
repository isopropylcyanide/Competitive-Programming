#include <bits/stdc++.h>
using namespace std;

// Finding shortest path in a graph represented using adjacency list using Dijsktra's
// algo. It finds shortest path from source v to all other nodes

//Stores source : (end, weight)
vector<vector<pair<int, int>>> adjList;
int N, M, s, e, u, v, w;

vector<int>  pathA, pathB;

void addEdge(int s, int e, int w){
    adjList[s].push_back(make_pair(e, w));
}

void findPath(vector<int> &parent, int s, int &ord){
    if (parent[s] == s){
        if (ord == 1)
            pathA.push_back(s);
        else pathB.push_back(s);
        return;
    }
    findPath(parent, parent[s], ord);
    if (ord == 1)
        pathA.push_back(s);
    else pathB.push_back(s);
}

int dijkstra_singleSource(int source, int destination, int ord){
    // Output shortest distances from this source to all vertices

    // to store the parent v of each in shortest path
    vector<int> parent(N + 1);
    for (int i = 1; i <= N; i++)
        parent[i] = i; //initially all are their own parent

    vector<int> dist(N + 1, INT_MAX); //all are unreachable
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
    findPath(parent, destination, ord);
    return dist[destination];
}

bool isReverse(){
    vector<int> A(pathA.begin(), pathA.end());
    vector<int> B(pathB.begin(), pathB.end());
    int a = A.size(), b = B.size();
    if (b < a)
        return false;
    int exp = a -1;
    for (int i = 0; i < b && exp >= 0; i++){
        if (B[i] == A[exp])
            exp --;
    }
    return exp == -1 ? true : false;
}

int main(){
    ios :: sync_with_stdio(false);
    cin >> N >> M >> s >> e;
    adjList.resize(N + 1);
    for (int i = 0; i < M; i++){
        cin >> u >> v >> w;
        addEdge(u, v, w);
    }
    int a = dijkstra_singleSource(s, e, 1);
    int b = dijkstra_singleSource(e, s, 2);
    // for (auto x : pathA)
    //     cout << x << " -> ";
    // cout << endl << endl;
    // for (auto x : pathB)
    //     cout << x << " <- ";

    if (a == INT_MAX || b == INT_MAX)
        cout << -1 << endl;
    // else pathB should be a reversed of A
    else if (isReverse())
        cout << a + b << endl;
    else cout << -1 << endl;
    return 0;
}
