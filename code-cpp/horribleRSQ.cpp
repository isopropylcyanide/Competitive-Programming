#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MAX 100005

ll T, N, C, type, p, q, v;
// Using segment tree with lazy propagation to answer range sum queryRange

ll st[4 *MAX], lazy[4 *MAX];


void update(ll pos, ll l, ll r, ll s, ll e, ll val){
    // Updates s - e range with val
    if (lazy[pos] != 0){
        // Update this node first
        st[pos] += (r - l + 1) * lazy[pos];
        if (l != r){
            // Mark children as lazy
            lazy[pos *2 + 1] += lazy[pos];
            lazy[pos *2 + 2] += lazy[pos];
        }
        lazy[pos] = 0;
    }
    if (l > r || s > r || e < l)
        return;

    if (s <= l && e >= r){
        // Update this range
        st[pos] += (r - l + 1) * val;
        if (l != r){
            // Lazily update the children
            lazy[pos *2 + 1] += val;
            lazy[pos *2 + 2] += val;
        }
        return;
    }

    ll mid = l + ((r - l) >> 1);
    update(pos * 2 + 1, l, mid, s, e, val);
    update(pos * 2 + 2, mid + 1, r, s, e, val);
    st[pos] = st[pos * 2 +1] + st[pos * 2 + 2];
}

ll queryRange(ll pos, ll l, ll r, ll s, ll e){
    if (l > r || s > r || e < l)
        return 0;

    if (lazy[pos] != 0){
        // Update this node first
        st[pos] += (r - l + 1) * lazy[pos];
        if (l != r){
            // Lazily update the children
            lazy[pos *2 + 1] += lazy[pos];
            lazy[pos *2 + 2] += lazy[pos];
        }
        lazy[pos] = 0;
    }
    if (s <= l && e >= r)
        return st[pos];
    ll mid = l + ((r - l) >> 1);
    return queryRange(pos * 2 + 1, l, mid, s, e) +
            queryRange(pos * 2 + 2, mid + 1, r, s, e);
}


int main(){
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    while (T--){
        cin >> N >> C;
        memset(st, 0, 4 * MAX);
        memset(lazy, 0, 4 * MAX);

        while(C--){
            cin >> type;
            if (type == 0){
                // Range sum update
                cin >> p >> q >> v;
                update(0, 0, N -1, p -1, q -1, v);
            }
            else{
                cin >> p >> q;
                //Range sum queryRange
                cout << queryRange(0, 0, N -1, p -1, q -1) << endl;
            }
        }
    }
    return 0;
}
