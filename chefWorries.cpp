#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cstring>
#include <set>
#include <queue>

#define MAX 1005
using namespace std;

static int C[MAX];

int testcases, n, q, u, v;
map<int, set<int> > adj;

bool isBiPartite(){
    // Checks if graph is bipartite
    vector<int> colorArr(n + 1, -1);
    colorArr[1] = 1;

    queue<int> q;
    q.push(1);

    while (!q.empty()){
        int u = q.front();
        q.pop();

        for (auto node : adj[u]){
            if (colorArr[node] == -1){
                colorArr[node] = 1 - colorArr[u];
                q.push(node);
            }
            else if (colorArr[node] == colorArr[u])
                return false;
        }
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> testcases;

    while(testcases--){
        memset(C, 0, sizeof C);
        cin >> n >> q;

        // Prepare a fully connected graph in the beginning
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(i != j)
                adj[i].insert(j);
            }
        }

        for(int i = 0; i < q; i++){
            cin >> u >> v;
            // Erase edges from graph

            auto it = adj[u].find(v);
            if (it != adj[u].end())
                adj[u].erase(it);

            it = adj[v].find(u);
            if (it != adj[v].end())
                adj[v].erase(it);
        }
        // If graph is bipartite then okay else not

        if (isBiPartite())
            cout << "YES\n";
        else
            cout << "NO\n";

        adj.clear();
    }
    return 0;
}
