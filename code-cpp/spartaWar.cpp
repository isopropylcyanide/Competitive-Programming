#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll N, T, Q, t, l, r;

typedef struct node{
    ll maxL, l, r, llen, rlen, range;
    // l and r is the storage for next merge
    // llen.. 1, 2, 3, 4, 1, 2, = 4
    // rlen .. 1, 2, 3, 4, 1, 2 = 2
    node(){
        maxL = l = r = llen = rlen = range = 0;
    }
    node(int y){
        maxL = -1;
    }
}node;

ostream & operator<<(ostream &c, node k){
    cout << "\nl: " << k.l << " r: " << k.r;
    cout << "\nllen: " << k.llen << " rlen: " << k.rlen;
    cout << "\n max: " << k.maxL << " range: " << k.range;
    cout << endl;
    return c;
}

vector<node> st;
vector<ll> A;

node merge(node a, node b){
    node ans;
    if (a.maxL == -1)
        return ans = b;
    else if (b.maxL == -1)
        return ans = a;

    ans.maxL = max(a.maxL, b.maxL);

    if (a.r < b.l)
        ans.maxL = max(ans.maxL, a.rlen + b.llen);

    ans.l = a.l;
    ans.r = b.r;
    ans.range = a.range + b.range;
    if (a.llen == a.range){
        if (a.r < b.l)
            ans.llen = a.range + b.llen;
        else ans.llen = a.range;
    }
    else ans.llen = a.llen;

    if (b.rlen == b.range){
        if (a.r < b.l)
            ans.rlen = a.rlen + b.range;
        else ans.rlen = b.range;
    }
    else ans.rlen = b.rlen;
    return ans;
}

node build(ll pos, ll l, ll r){
    if (l > r)
        return node(-1);

    st[pos].range = r -l + 1;

    if (l == r){
        st[pos].maxL = 1;
        st[pos].llen = st[pos].rlen = 1;
        st[pos].l = st[pos].r = A[l];
        return st[pos];
    }
    ll mid = l + ((r - l) >> 1);
    node a = build(2* pos + 1, l, mid); //left node
    node b = build(2* pos + 2, mid +1, r); //right node

    st[pos] = merge(a, b);
    return st[pos];
}

node query(int pos, int l, int r, int s, int e){
    if (s > r || e < l)
        return node(-1);
    if (s <= l && e >= r)
        return st[pos];
    ll mid = l + ((r - l) >> 1);
    node ans = query(2 * pos + 1, l, mid, s, e); //left node
    ans = merge(ans, query(2 * pos + 2, mid +1, r, s, e)); //right node
    return ans;
}

void update(int pos, int l, int r, int i, int val){
    if (i < l || i > r)
        return;
    if (l == r){
        st[pos].maxL = 1;
        st[pos].llen = st[pos].rlen = 1;
        st[pos].l = st[pos].r = val;
        return;
    }
    ll mid =  l + ((r - l) >> 1);
    update(2 * pos + 1, l, mid, i, val);
    update(2 * pos + 2, mid + 1, r , i, val);
    st[pos] = merge(st[pos * 2 + 1], st[pos * 2 + 2]);
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin >> T;

    while (T--){
        cin >> N >> Q;
        A.resize(N);
        st.resize(4 * N);
        for (int i = 0; i < N;  i++)
            cin >> A[i];

        build(0, 0, N -1);
        while (Q--){
            cin >> t >> l >> r;
            if (t == 0){
                // Query operation, longest increasing substring
                l--; r--;
                cout << query(0, 0, N -1, l, r).maxL << endl;
            }
            else{
                // Update power of lth soldier to r. i.e propagate val
                l--;
                A[l] += r;
                update(0, 0, N -1, l, A[l]);
            }
        }

    }
    return 0;
}
