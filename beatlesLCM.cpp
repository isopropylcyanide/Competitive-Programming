// LCM of given range queries using Segment Tree
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MAX 100005

// allocate space for tree
ll tree[4*MAX];

// declaring the array globally
ll arr[MAX];
ll L[MAX];

// Function to return gcd of a and b
ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    return gcd(b%a, a);
}

//utility function to find lcm
ll lcm(ll a, ll b)
{
    return a*b/gcd(a,b);
}

// Function to build the segment tree
// Node starts beginning index of current subtree.
// start and end are indexes in arr[] which is global
void build(ll node, ll start, ll end)
{
    // If there is only one element in current subarray
    if (start==end)
    {
        tree[node] = arr[start];
        return;
    }

    ll mid = (start+end)/2;

    // build left and right segments
    build(2*node, start, mid);
    build(2*node+1, mid+1, end);

    // build the parent
    ll left_lcm = tree[2*node];
    ll right_lcm = tree[2*node+1];

    tree[node] = lcm(left_lcm, right_lcm);
}

// Function to make queries for array range )l, r).
// Node is index of root of current segment in segment
// tree (Note that indexes in segment tree begin with 1
// for simplicity).
// start and end are indexes of subarray covered by root
// of current segment.
ll query(ll node, ll start, ll end, ll l, ll r)
{
    // Completely outside the segment, returning
    // 1 will not affect the lcm;
    if (end<l || start>r)
        return 1;

    // completely inside the segment
    if (l<=start && r>=end)
        return tree[node];

    // partially inside
    ll mid = (start+end)/2;
    ll left_lcm = query(2*node, start, mid, l, r);
    ll right_lcm = query(2*node+1, mid+1, end, l, r);
    return lcm(left_lcm, right_lcm);
}

ll N;
//driver function to check the above program
int main(){
    cin >> N;
    for (ll i = 0; i < N; i++)
        cin >> arr[i];

    build(1, 0, N -1);

    // Now we can answer each query efficiently

    // Prll LCM of (2, 5)
    for (ll i = 0; i < N; i++){
        ll left = i == 0 ? 1 : query(1, 0, N -1, 0, i -1);
        ll right = i == N -1 ? 1 : query(1, 0, N -1, i + 1, N -1);
        ll _lcm = lcm(left, right);
        L[i] = _lcm;
    }

    ll ans = -1;
    for (ll i = 0; i < N; i++){
        if (L[i] % arr[i] != 0){
            ans = i + 1;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}
