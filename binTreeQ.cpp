#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, u, v, Q;
ll commonAnc_uv;

ll parent(ll N){
    if (N == 1)
        return 1;
    return N >> 1;
}

ll commonAncestor_level(ll A, ll B){
    // Returns common ancestor as well as how far it was
    while (A != B){
        if (A > B)
            A = parent(A);
        else
            B = parent(B);
    }
    return A;
}

string getPath(ll A, ll anc){
    // store path from A to B
    // parent from left, 0 : parent from right 1;
    string pathA;

    while (A != anc){
        pathA += (A & 1 ? '1' : '0'); //if odd we are coming from right
        A = parent(A);
    }

    return pathA;
}

int main(){
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    cin >> Q;

    while (Q --){
        cin >> n >> u >> v;
        if (u == v){
            cout << n << endl;
            continue;
        }

        ll maxNode = max(u, v);
        commonAnc_uv = commonAncestor_level(u, v);

        string path = getPath(maxNode, commonAnc_uv);
        reverse(path.begin(), path.end());
        path.insert(0, 1, '1');


        ll width = pow(2, path.size() -1);
        ll startingVal = strtol(path.c_str(), NULL, 2);
        ll ans = (n - startingVal)/width + 1;


        cout << ans << endl;
    }
    return 0;
}
