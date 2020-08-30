#include <bits/stdc++.h>
using namespace std;

#define MAX 1000005
typedef long long ll;

vector<map<char, int> > A, st, lazy;

/* It's Christmas time and Santa is in town. There are N children each having a bag with a mission to fill in as many toffees as possible. They are accompanied by a teacher whose ulterior motive is to test their counting skills. The toffees are of different types. Santa picks up a child and gives m type of toffee to him/her

The teacher wishes to calculate the number of toffees there are of a particular type given a range of children. Formally, there are 2 queries:

Type 1: It is of the form 1 m n p
    1 is the type no,"m" is the child to which "n" toffees of a brand "p" are given
Type 2: It is of the form 2 m n p
    where 2 is the type no, p is the brand of the toffeem m - n is the range of children inclusive. Report the sum of toffees of brand p within the given range
*/

void update(ll pos, ll l, ll r, ll i, ll n, char type){
    // Updates the range of s - e with incr
    // cout << "\n l: " << l << " r: " << r << " i: " << i << " n: " << n << " -> " << type << endl;
    if (i < l || i > r)
        return;

    st[pos][type] += n;
    if (l == r)
        return;

    ll mid = l + ((r - l) >> 1);
    ll left = 2* pos + 1, right = 2 * pos + 2;

    update(left, l, mid, i, n, type);
    update(right, mid + 1, r, i, n, type);

}

ll queryRange(ll pos, ll l, ll r, ll s, ll e, char type){
    // Query the range s - e for the number of types in range
    if (l > r || r < s || l > e)
        return 0;

    if (s <= l && e >= r)
        return st[pos][type];

    ll mid = l + ((r - l) >> 1);
    return queryRange(pos * 2 + 1, l, mid, s, e, type) +
            queryRange(pos * 2 + 2, mid + 1, r, s, e, type);
}


int main(int argc, char**argv){
    ios :: sync_with_stdio(false);

    A.resize(MAX);
    st.resize(4 * MAX);
    lazy.resize(4 * MAX);
    int c, m, n;
    char p;

    int queries;
    cin >> queries;
    assert(queries <= MAX);

    while (queries--){
        cin >> c >> m >> n >> p;
        // m and n are 0 indexed
        if (c == 1)
                update(0, 0, A.size() -1, m , n, p);
        else
            cout << queryRange(0, 0, A.size() -1, m, n, p) << endl;
    }
    return 0;
}
