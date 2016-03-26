#include <bits/stdc++.h>
using namespace std;

vector<int> P;
vector<int> R;
int N, Q, a, b;
set< pair<int, int> > S;

int root(int node){
    while (node != P[node])
        node = P[node];
    return node;
}

void initialize(int N){
    P.resize(N);
    R.resize(N, 1);
    for (int i = 0; i < N; i++){
        P[i] = i;
        S.insert(make_pair(1, i));
    }
}

void unionCity(int a, int b){
    a = root(a);
    b = root(b);
    if (a == b)
        return;

    if (R[b] > R[a])
        swap(b, a);

    S.erase(make_pair(R[b], b));
    S.erase(make_pair(R[a], a));
    P[b] = a;
    R[a] += R[b];
    S.insert(make_pair(R[a], a));
}

int main(){
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> Q;
    initialize(N);

    for (int i = 0; i < Q; i++){
        cin >> a >> b;
        a--, b--;
        unionCity(a, b);
        cout << S.rbegin() -> first - S.begin() -> first << endl;
    }

    return 0;
}
