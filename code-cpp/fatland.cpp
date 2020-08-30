#include <bits/stdc++.h>
using namespace std;

int N, K;
vector<int> A;
vector<int> P; //parent of this tree
vector<int> R; //rank of a rooted tree

int findRoot(int node){
    while (node != P[node]){
        P[node] = P[P[node]];
        node = P[node];
    }
    return node;
}



int main(){
    int a, b;
    cin >> N >> K;

    P.resize(N);
    R.resize(N);
    //initialise disjoint set
    for (int i = 0; i < N; i++){
        P[i] = i;
        R[i] = 1;
    }

    for (int i = 0; i < K; i++){
        cin >> a >> b;
        a --; b--;
        //do union of b with a
        int pA = findRoot(a);
        int pB = findRoot(b);

        P[pB] = pA;
        R[pA] += R[pB];
    }

    //find number of disjoint subsets that is trees whose parents are //they themselves
    int count = 0;
    for (int i = 0; i < N; i++)
        count = (P[i] == i) ? count + 1 : count;

    cout << count << endl;
    return 0;
}
