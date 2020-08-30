#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll N, Q, l, r, t;
string s;

// Each seg tree node contains a single value denoting the remainder at that stage

typedef struct node{
    ll modSum;    //indicates the modSum stored in this node mod 3
    ll count;
    node(int x, int y){
        modSum = x, count = y;
    }
    node(){}
}node;

vector<node> st;

ll fastPower(ll a, ll b, ll mod){
    ll x = 1, y = a;
    while(b > 0) {
        if(b % 2 == 1)
        x = (x * y) % mod;
        y = (y * y) % mod;
        b /= 2;
    }
    return x;
}

void build(int pos, int l, int r){
    if (l > r)
        return;
    if (l == r){
        st[pos] = node();
        st[pos].modSum = s[l] - '0';
        st[pos].count = 1;
        return;
    }
    ll mid = l + ((r - l) >> 1);
    ll lC = pos *2 + 1, rC = pos *2 + 2;
    build(lC, l, mid);
    build(rC, mid + 1, r);

    st[pos].modSum = (st[lC].modSum * fastPower(2, st[rC].count, 3)) % 3;
    st[pos].modSum = (st[pos].modSum + st[rC].modSum) % 3;
    st[pos].count = st[lC].count + st[rC].count;
}

void constructTree(){
    st.resize(4 * N);
    build(0, 0, N -1);
}

node query(int pos, int l, int r, int s, int e){
    // Query the tree for positional sum
    // l..r array bounds, s..e query interval
    if (s > r || e < l)
        return node(0, 0);

    else if (s <= l && e >= r)
        return st[pos];

    ll mid =  l + ((r - l) >> 1);
    // cout << "\n partial overlap at l: " << l << " r: " << r << endl;
    node left = query(pos *2 + 1, l, mid, s, e);
    node right = query(pos *2 + 2, mid +1, r, s, e);
    node ans;
    ans.modSum = (left.modSum * fastPower(2, right.count, 3)) % 3;
    ans.modSum = (ans.modSum + right.modSum) % 3;
    ans.count = left.count + right.count;
    return ans;
}


void update(int pos, int l, int r, int i){
    // Update the segment tree by setting ith bit to 1
    // l..r array bounds, s..e query interval
    if (i < l || i > r)
        return;
    if (l == r){
        st[pos].modSum = 1;
        return;
    }
    ll mid = l + ((r - l) >> 1);
    ll lC = pos *2 + 1, rC = pos *2 + 2;
    update(lC, l, mid, i);
    update(rC, mid + 1, r, i);

    st[pos].modSum = (st[lC].modSum * fastPower(2, st[rC].count, 3)) % 3;
    st[pos].modSum = (st[pos].modSum + st[rC].modSum) % 3;
}

void flip(ll i){
    if (s[i] == 1)
        return;
    else{
        s[i] = 1;
        update(0, 0, N -1, i);
    }
}

int main(){
    ios :: sync_with_stdio(false);
    cin >> N;
    cin >> s;
    constructTree();

    cin >> Q;
    while (Q--){
        cin >> t;

        if (t == 1){
            cin >> l;
            // Flip the value at index l if 0
            flip(l);
        }
        else{
            cin >> l >> r;
            // Report remainder of binary string b/w l-r
            cout << query(0, 0, N -1, l, r).modSum << endl;
        }
    }

    return 0;
}
