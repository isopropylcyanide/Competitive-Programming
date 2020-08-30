#include <bits/stdc++.h>
using namespace std;

#define MAX 1000005

typedef long long ll;

typedef struct node{
    ll value;
    bool flag;
    //flag = 1; if all the element in the range which each internal node represent are 1
}node;

vector<ll> prime, A;
vector<node> st;
ll n, m, t, q, s, e;

void sieve (){
    prime.resize(MAX, 0);
    prime[1] = 1;
    prime[0] = 1;

    for(ll i = 2; i <= MAX; i += 2)
        prime[i] = 2;

    for (ll i = 3; i * i <= MAX; i += 2)
        if (!prime[i]){
            prime[i] = i;
            for (ll j = i * i; j <= MAX; j += 2 * i)
                if(!prime[j])   						// ensure not to overwrite already filled entries
                    prime[j] = i;
        }

    for (ll i = 3; i <= MAX; i += 2)						// Only prime numbers are left which are filled with 0's
        if (!prime[i])
            prime[i] = i;
 }

void constructTree(ll l, ll r, ll pos){
    if (l == r){
        st[pos].value = prime[A[l]];			// building Segment Tree on LeastPrimeDivisor of Ai's
        st[pos].flag = A[l] == 1;
        return;
    }

    ll mid = l + ((r - l) >> 1);
    constructTree(l, mid, 2 * pos + 1);
    constructTree(mid + 1, r, 2 * pos + 2);
    st[pos].value = max(st[2 * pos + 1].value, st[2 * pos + 2].value);
    st[pos].flag = st[pos*2 + 1].flag && st[pos*2 + 2].flag;
}

void update(ll s, ll e, ll l, ll r, ll pos){
    if (l > r || l > e || r < s)
        return;

    // Return if the leaf nodes in the subtree rooted at node 'pos' contains all 1's, no update is needed
    if (st[pos].flag)
        return;

    if (l == r){
        A[l] /= prime[A[l]];						// change st[pos].value and A[l] value accordingly
        st[pos].value = prime[A[l]];
        st[pos].flag = A[l] == 1;
        return;
    }

    ll mid = l + ((r - l) >> 1);
    update(s, e, l, mid, 2*pos+1);
    update(s, e, mid+1, r, 2*pos+2);

    st[pos].value = max(st[2*pos + 1].value, st[2*pos + 2].value);
    st[pos].flag = st[pos*2 + 1].flag && st[pos*2 + 2].flag;
}

ll query(ll s, ll e, ll l, ll r, ll pos){					//Simple query function
    if (l > e || r < s)
        return 0;

    if (s <= l && r <= e)
        return st[pos].value;

    ll mid = l + ((r - l) >> 1);
    return max(query(s, e, l, mid, 2 * pos + 1), query(s, e, mid + 1, r, 2 * pos + 2));

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    sieve();
    cin >> t;
    while(t--){
        cin >> n >> m;

        A.resize(MAX, 0);
        st.resize(4 * MAX);

        for (ll i = 0; i < n; i++)
            cin >> A[i];

        constructTree(0, n-1, 0);					// building segment on 'A'

        for (ll i = 0; i < m; i++){
            cin >> q >> s >> e;

            if (q == 0)
                update(s -1, e -1, 0, n-1, 0);
            else
                cout << query(s -1, e -1, 0, n-1, 0) << " ";
        }
        cout << endl;
    }

    return 0	;
}
