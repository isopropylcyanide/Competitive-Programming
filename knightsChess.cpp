#include <bits/stdc++.h>
using namespace std;

//Given any source point and destination point on a chess board, we need to find whether
 // Knight can move to the destination or not in shortest steps

int N, M, xA, yA, xB, yB;
int shortestPath;
typedef pair<int, int> pii;
#define mp make_pair
typedef vector<pii> adjList;

vector<vector<adjList>> graph;
vector< vector<bool> > visited;

bool valid(int i, int j){
    if (i < 0 || j < 0 || i >= N || j >= M)
        return false;
    return true;
}

void precompute(){
    //Precomputes the possible edges graph
    graph.resize(N, vector<adjList>(M));
    visited.resize(N, vector<bool>(M, false));

    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){

            if (valid(i + 2, j + 1))
                graph[i][j].push_back(mp(i + 2, j + 1));
            if (valid(i + 2, j - 1))
                graph[i][j].push_back(mp(i + 2, j - 1));
            if (valid(i - 2, j + 1))
                graph[i][j].push_back(mp(i - 2, j + 1));
            if (valid(i - 2, j - 1))
                graph[i][j].push_back(mp(i - 2, j - 1));
            if (valid(i + 1, j + 2))
                graph[i][j].push_back(mp(i + 1, j + 2));
            if (valid(i + 1, j - 2))
                graph[i][j].push_back(mp(i + 1, j - 2));
            if (valid(i - 1, j + 2))
                graph[i][j].push_back(mp(i - 1, j + 2));
            if (valid(i - 1, j - 2))
                graph[i][j].push_back(mp(i - 1, j - 2));
        }
    }
}

void bfs(int i, int j, int dist){
    //BFS traversal to reach xB, yB
    if (visited[i][j])
        return;

    if (i == xB && j == yB){
        shortestPath = min(shortestPath, dist);
        return;
    }
    visited[i][j] = true;
    for (auto edges : graph[i][j]){
        if (!visited[edges.first][edges.second])
            bfs(edges.first, edges.second, dist + 1);
    }


}

int knight(int N, int M, int xA, int yA, int xB, int yB) {
     //check bounds
    shortestPath = INT_MAX;
    xA--, yA--, xB--, yB--;
    precompute();

    if (!valid(xA, yA))
        return -1;
    if (!valid(xB, yB))
        return -1;

    //Do a bfs from xA, yA
    bfs(xA, yA, 0);

    return shortestPath == INT_MAX ? -1 : shortestPath;
}

int main(){
    cin >> N >> M >> xA >> yA >> xB >> yB;

    cout << knight(N, M, xA, yA, xB, yB) << endl;
}
