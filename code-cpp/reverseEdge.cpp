#include<bits/stdc++.h>
using namespace std;

#define MAX 505

// Indicates an edge from index to edge[index].to
typedef struct edge{
    int to;
    bool rev;
    //rev is true if edge is reversed;
    edge(){}
    edge(int t, bool isRev){
        to = t; rev = isRev;
    }
}edge;

vector<edge> adj[MAX];
int N, M, a, b, src, dest;

// A node displays a node's status that is
// the node value as well as rev edges ecountered so far
typedef struct node{
    int val;
    int revEdges;
    int par;
    node(int a, int b, int c){
        val = a, revEdges = b, par = c;
    }
}node;

int m[MAX][MAX];
//if i
int bfs(int src, int dest){
    queue<node> q;
    q.push(node(src, 0, src));
    int minAns = INT_MAX;

    while (!q.empty()){
        node cur = q.front();
        q.pop();
        int val = cur.val;
        int revEdges = cur.revEdges;
        // cout << "\n cur: " << " (" << val << ", " << revEdges << ", " << cur.par << ")\n";
        if (val == dest){
            minAns = min(minAns, revEdges);
        }
        else{
            for (auto e : adj[val]){
                if (e.to == cur.par)
                    continue;
                if (m[e.to][val] == 1 || m[val][e.to] == 1)
                    continue;
                if (e.rev){
                    // cout << "\n pushing rev ("<< e.to << ", " << revEdges + 1 << ", " << val << ")\n";
                    m[e.to][val] = 1;
                    m[val][e.to] = 1;
                    q.push(node(e.to, revEdges + 1, val));
                }
                else{
                    // cout << "\n pushing ("<< e.to << ", " << revEdges << ", " << val << ")\n";
                    m[e.to][val] = 1;
                    m[val][e.to] = 1;
                    q.push(node(e.to, revEdges, val));
                }
            }
        }
    }

    return minAns == INT_MAX ? -1 : minAns;
}

int main(){
    ios :: sync_with_stdio(0);
    cin >> N >> M;

    for (int i = 0; i < M; i++){
        cin >> a >> b;
        adj[a].push_back(edge(b, false));
        adj[b].push_back(edge(a, true));
    }

    cin >> src >> dest;


    cout << bfs(src, dest) << "\n";

    return 0;
}
