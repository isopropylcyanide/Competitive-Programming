#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned llu;
#define MOD 1000000007

vector<llu> risk;
vector<llu> P;
vector<llu> R;
llu N, Q, a, b;

llu fastMult(llu a, llu b){
    llu ans = 0;
    while(b){
        if(b & 1){
            ans += a;
            ans %= MOD;
        }
        a <<= 1;
        a %= MOD;
        b >>= 1;
    }
    return ans;
}


llu getRoot(llu node){
    while (node != P[node])
        node = P[node];
    return node;
}

void display(){
    cout << " PARENT" << endl;
    for (llu i = 0; i < P.size(); i++)
        cout << P[i] << " -> ";
    cout << endl << endl;
}

void initialize(llu N){
    risk.resize(N);
    P.resize(N);
    R.resize(N, 1);
    for (llu i = 0; i < N; i++)
        P[i] = i;

}


void unionCity(llu a, llu b){
    llu rootA = getRoot(a);
    llu rootB = getRoot(b);
    if (rootA == rootB)
        return;
    P[rootB] = rootA;
}

void formConnectedComponents(){
    vector<bool> visited(N, false);
    map<llu, vector<llu> > components;

    for (llu i = 0; i < N; i++){
        if (!visited[i]){
            visited[i] = true;
            llu root = getRoot(i);
            components[root].push_back(i);
        }
    }

    llu prodCount = 1;

    for (auto k : components){
        vector<llu> branch;
        llu count = 0;
        for (auto v : k.second)
            branch.push_back(risk[v]);

        llu minElement = *min_element(branch.begin(), branch.end());
        for (auto v : branch)
            if (v == minElement)
                count = (count + 1) % MOD;

        prodCount = fastMult(prodCount, count);
    }
    cout << prodCount % MOD << endl;

}

int main(){
    ios :: sync_with_stdio(false);
    cin >> N;
    initialize(N);

    for (llu i = 0; i < N; i++)
        cin >> risk[i];

    cin >> Q;
    for (llu i = 0; i < Q; i++){
        cin >> a >> b;
        a --, b--;
        //do union of a, b
        unionCity(a, b);
    }

    formConnectedComponents();
    //from each component, find the number of elements which have minimum risk. Add all of them

    return 0;
}
