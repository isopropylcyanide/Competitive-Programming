#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <list>

#define INF 99999
using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
vector<vector<int>> graph;  //initial graph
vector<vector<int>> D;      //all pair shortest distance
vector<vector<int>> INTER;  //next intermediate (if any) path towards shortest goal

vector<int> gateWays;
int N; // the total number of nodes in the level, including the gateways
int L; // the number of links
int E; // the number of exit gateways

void printMat(vector<vector<int>> G){
    // Prints a 2D matrix
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            if (G[i][j] == INF)
                cout << "INF - ";
            else
                cout << G[i][j] << " - ";
        }
        cout << endl;
    }
    cout << endl;
}

void floydWarshall(){
    // Compute shortest distance between all pairs of path
    D.resize(N, vector<int> (N, INF));
    INTER.resize(N, vector<int> (N, INF));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++){
            D[i][j] = graph[i][j];
            INTER[i][j] = j;
        }

    for (int k = 0; k < N; k++){
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++){
                if (D[i][k] + D[k][j] < D[i][j]){
                    INTER[i][j] = k;
                    D[i][j] = D[i][k] + D[k][j];
                }
            }
    }
    printMat(D);
    printMat(INTER);
}



int main(){
    cin >> N >> L >> E; cin.ignore();
    // cerr << "N: " << N << " L: " << L << " E: " << E << endl;

    graph.resize(N, vector<int> (N, INF));
    for (int i = 0; i < N; i++)
        graph[i][i] = 0;

    for (int i = 0; i < L; i++) {
        int N1; // N1 and N2 defines a link between these nodes
        int N2;
        cin >> N1 >> N2; cin.ignore();
        graph[N1][N2] = 1;
        graph[N2][N1] = 1;
        // cerr << "Edge " << N1 << " - " << N2 << endl;
    }

    for (int i = 0; i < E; i++) {
        int EI; // the index of a gateway node
        cin >> EI; cin.ignore();
        gateWays.push_back(EI);
        // cerr << "G: " << EI << endl;

    }

    printMat(graph);
    floydWarshall();

    // game loop
    while (1) {
        int SI; // The index of the node on which the Skynet agent is positioned this turn
        cin >> SI; cin.ignore();

        cerr << "S: " << SI << endl;
        //For S, look at the adjacency list of S
        int severEnd = SI;
        int closestGateWay = INF;
        for (auto gate : gateWays){
            int currDist = D[SI][gate];
            if (currDist < closestGateWay){
                closestGateWay = currDist;
                severEnd = INTER[SI][gate];
            }
        }
        cerr << " Found closestGateWay: " << closestGateWay << " by severing end " << severEnd << endl;
        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;
        cout << SI << " " << severEnd << endl;
    }
    return 0;
}
