#include <bits/stdc++.h>
using namespace std;

#define MOD 100000007
typedef long long ll;
ll Q, N, u, v;
char type;

vector<ll> A, P, W;

void display(vector<ll> &P){
    cout << endl;
    for (auto x : P)
        cout << x << " ";
}

ll root(ll N){
    //find root nodes of DSU
    while (N != P[N]){
        P[N] = P[P[N]];
        N = P[N];
    }
    return P[N];
}

void merge(ll A, ll B){
    //merge two nodes in DSU
    ll rootA = root(A);
    ll rootB = root(B);
    if (rootA != rootB){
        if (W[rootA] < W[rootB]){
            P[A] = B;
            W[B] += W[rootA];
        }
        else{
            P[B] = A;
            W[A] += W[B];
        }
    }
}


void init(){
    P.resize(N + 10);
    W.resize(N + 10);
    A.resize(N + 10);
    for (int i = 1; i <= N; i++){
        P[i] = i;
        W[i] = 1;
    }
}

ll closestDistance(vector<ll> &A){
    sort(A.begin(), A.end());
    ll closest = LONG_LONG_MAX;
    for (int i = 1; i < A.size(); i++){
        ll diff = A[i] - A[i -1];
        if (diff < closest)
            closest = diff;
    }
    return closest;
}

ll farthestDistance(vector<ll> &A){
    sort(A.begin(), A.end());
    return  *(A.rbegin()) - *(A.begin());
}

ll compute(ll x, ll y, ll type){
    // Compute lowest common ancestor
    vector<ll> valA;
    vector<ll> valB;
    vector<ll> val;

    valA.push_back(A[x]);
    while (x != P[x]){
        x = P[x];
        valA.push_back(A[x]);
    }

    valB.push_back(A[y]);
    while (y != P[y]){
        y = P[y];
        valB.push_back(A[y]);
    }

    ll i = valA.size() -1, j = valB.size() -1;
    while (i >= 0 && j >= 0 && valA[i] == valB[j]){
        i --; j --;
    }
    if (i == -1){
        j++;
        for (int k = j; k >= 0; k--)
            val.push_back(valB[k]);
    }
    else if (j == -1){
        i++;
        for (int k = i; k >= 0; k--)
            val.push_back(valA[k]);
    }
    else{
        i++;
        for (int k = i; k >= 0; k--)
            val.push_back(valA[k]);
        for (int k = j; k >= 0; k--)
            val.push_back(valB[k]);
    }
    if (type == 'F')
        return farthestDistance(val);
    else
        return closestDistance(val);
}

int main(){
    cin >> N;
    init();

    for (int i = 1; i <= N; i++)
        cin >> A[i];

    for (int i = 1; i < N; i++){
        cin >> u >> v;
        merge(u, v);
    }

    cin >> Q;
    while (Q--){
        cin >> type >> u >> v;
        cout << compute(u, v, type) << endl;
    }

    return 0;
}
