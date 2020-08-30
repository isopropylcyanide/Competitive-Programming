#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll L[201][201][201];

#define N_MAX 8120601
#define MAX 32482404

ll A[N_MAX];
ll st[MAX];
ll N, K, a, b, c, d, e, f, t, val;

ll coordinate(ll i, ll j, ll k){
    return i*201 + j*201 + k*201;
}

void updateTree(ll pos, ll l, ll r, ll i, ll val){
    if (i < l || i > r)
        return;
    st[pos] += val;
    if (r != l){
        ll mid = l + ((r - l) >> 1);
        updateTree(2*pos + 1, l, mid, i, val);
        updateTree(2*pos + 2, mid + 1, r, i, val);
        st[pos] = st[2 * pos+1] + st[2 * pos+2];
    }
}

ll queryTree(ll pos, ll l, ll r, ll s, ll e){
    if (l > r || s > r || e < l)
        return 0;
    if (s <= l && e >= r)
        return st[pos];
    ll mid = l + ((r - l) >> 1);
    return queryTree(pos * 2 + 1, l, mid, s, e) +
            queryTree(pos * 2 + 2, mid + 1, r, s, e);
}

int main(){
    cin >> N >> K;
    ll numPlayer = 0;

    while (K--){
        cin >> t;
        if (t == 1){
            // update query: update segtree
            cin >> a >> b >> c >> val;
            ll index = coordinate(a, b, c);
            A[index] += val;
            updateTree(0, 0, N_MAX - 1, index, val);
            numPlayer += val;
        }
        else{
            // query number of players from a b c to d e f
            cin >> a >> b >> c >> d >> e >> f;
            ll indA = coordinate(a, b, c);
            ll indB = coordinate(d, e, f);
            if (indB == 0)
                cout << numPlayer - A[0] << endl;
            if (indA == 0)
                cout << numPlayer - queryTree(0, 0, N_MAX -1, 0, indB) << endl;
            else
                cout << numPlayer - queryTree(0, 0, N_MAX -1, indA -1, indB) << endl;
            
        }
    }
    return 0;
}
