#include <bits/stdc++.h>
using namespace std;

std :: vector<int> P;
std :: vector<int> W;


int root(int node){
    while (node != P[node]){
        P[node] = P[P[node]];
        node = P[node];
    }
    return node;
}


void display(){
    cout << " RANK" << endl;
    for (auto a : W)
        cout << a << " -> ";
    cout << endl;

    cout << " PARENT" << endl;
    for (int i = 0; i < P.size(); i++)
        cout << P[i] << " -> ";
    cout << endl << endl;
}


int main(){

    int N, D, a, b;
    cin >> N >> D;

    P.resize(N);
    W.resize(N);
    //initialize
    for (int i = 0; i < N; i++){
        P[i] = i;
        W[i] = 1;
    }
    // display();

    for (int i = 0; i < D; i++){
        cin >> a >> b;
        a--; b--;
        //merge a with b depending on weight
        int pA = root(a);
        int pB = root(b);

        if (pA == pB)
            continue;

        if (W[pA] > W[pB]){
            P[pB] = pA;
            W[pA] += W[pB];
        }
        else{
            P[pA] = pB;
            W[pB] += W[pA];
        }
        // display();
    }

    //print size of min connected component
    vector<int> connected;
    for (int i = 0; i < W.size(); i++)
        if (i == P[i])
            connected.push_back(W[i]);

    cout << *min_element(connected.begin(), connected.end()) << endl;

    return 0;
}
