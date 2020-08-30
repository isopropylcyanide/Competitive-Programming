#include <bits/stdc++.h>
#include <iostream>
typedef long long int llu;
using namespace std;

int N, M, Q, x, y;
llu temp;
llu maxSum = 0, curr_max;
int A, K;
char query_type;
// A vector to store populations of ith town
vector <llu> pop;

// A vector that stores pair of roads in the input along with their validity
vector <pair <pair<int, int>, bool> > road_input;

// A vector that stores the connected components for each pair
vector <pair<int, vector<int> > > connected;

void display(){
    for (auto a : pop)
                cout <<" "<<a;

        for (auto a : road_input) {
                cout << "\nRoad: "<<a.first.first<<" - "<<a.first.second<<" Nalid: "<<a.second;
        }
}


void DFSUtil(int v, vector<bool> & visited, llu & mySum){
        // Mark the current node as visited and print it
        visited[v] = true;
        mySum += pop[v];

        // Recur for all the vertices
        // adjacent to this vertex
        int iterator = 0;
        for (auto road : road_input) {
                if (visited[iterator] == false && road.second == true)
                        DFSUtil(iterator, visited, mySum);
                iterator++;
        }
}

llu kosaraju_connectedComponents(){
        // Mark all the vertices as not visited
        vector<bool> visited(N,false);
        maxSum = 0;

        for (int v = 0; v < N; v++) {
                if (visited[v] == false) {
                        // store all reachable vertices
                        // from v
                        curr_max = 0;
                        DFSUtil(v, visited, curr_max);
                        maxSum = max(curr_max, maxSum);
                }
        }
        return maxSum;
}


void tarjanUtil(int u, int disc[], int low[], stack<int> *st,
                bool stackMember[]){
        // A static variable is used for simplicity, we can avoid use
        // of static variable by passing a pointer.
        static int time = 0;

        // Initialize discovery time and low value
        disc[u] = low[u] = ++time;
        st->push(u);
        stackMember[u] = true;

        // Go through all vertices adjacent to this
        int v = 0;
        for (auto road : road_input) {
                if (disc[v] == -1 && road.second == true) {
                        tarjanUtil(v, disc, low, st, stackMember);
                        low[u]  = min(low[u], low[v]);
                }

                else if (stackMember[v] == true)
                        low[u]  = min(low[u], disc[v]);

                v++;
        }

        int w = 0; // To store stack extracted vertices
        if (low[u] == disc[u]) {

                curr_max = 0;

                while (st->top() != u) {
                        w = (int) st->top();
                        curr_max += pop[w];
                        // cout << w << " ";
                        stackMember[w] = false;
                        st->pop();
                }

                w = (int) st->top();
                curr_max += pop[w];
                // cout << w << "\n and curr_max: "<<curr_max;
                maxSum = max(curr_max, maxSum);
                stackMember[w] = false;
                st->pop();
        }

}


// The function to do DFS traversal. It uses tarjanUtil()
void tarjanConnectedComponents(){
        int *disc = new int[N];
        int *low = new int[N];
        bool *stackMember = new bool[N];
        stack<int> *st = new stack<int>();

        // Initialize disc and low, and stackMember arrays
        for (int i = 0; i < N; i++) {
                disc[i] = -1;
                low[i] = -1;
                stackMember[i] = false;
        }
        maxSum = 0;

        // Call the recursive helper function to find strongly
        // connected components in DFS tree with vertex 'i'
        for (int i = 0; i < N; i++)
                if (disc[i] == -1)
                        tarjanUtil(i, disc, low, st, stackMember);

        cout << maxSum << endl;
}

int main(){

        ios :: sync_with_stdio(false);
        cin >> N >> M >> Q;

        for (int i = 0; i < N; i++) {
                cin >> temp;
                pop.push_back(temp);
        }

        for (int i = 0; i < M; i++) {
                cin >> x >> y;
                // Initially all roads are valid
                road_input.push_back(make_pair(make_pair(x,y),true));
        }

        for (int i = 0; i < Q; i++) {
                cin >> query_type;
                if (query_type == 'D') {
                        // Destroy a particular road
                        cin >> K;
                        road_input[K - 1].second = false;
                }
                else if (query_type == 'P') {
                        // Population of area A is now x
                        cin >> A >> x;
                        pop[A - 1] = x;
                }

                // cout << kosaraju_connectedComponents()<<endl;
                tarjanConnectedComponents();
        }

        return 0;
}
