#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int> A, st, lazy;

/* It's Christmas time and Santa is in town. There are N children each having a bag with a mission to fill in as many toffees as possible. They are accompanied by a teacher whose ulterior motive is to test their counting ability.  The toffees are of different types. Since Santa is a busy person, he proceeds in the following way. He distributes a particular type of toffee to a range  of students.

The teacher also wishes to calculate the number of toffees there are of a particular type given a range of children. Formally, there are 2 queries:

Type 1: It is of the form 1 a m n
    1 is the type no, a is the brand of the toffee, m - n the range of children the toffees were distributed to (both inclusive).
Type 2: It is of the form 2 p m n
    where 2 is the type no, p is the brand of the toffeem m - n is the range of children inclusive. Report the sum of toffees of brand p within the given range
*/

void constructTree(ll pos, ll l, ll r){
    // Constructs a minimum segment tree
    if (l > r)
        return;
    if (l == r){
        st[pos] = A[l];
        return;
    }
    ll mid = l + ((r - l) >> 1);
    constructTree(2 * pos + 1, l, mid);
    constructTree(2 * pos + 2, mid + 1, r);
    st[pos] = min(st[pos*2 +1], st[pos*2 + 2]);
}

void updateRange(ll pos, ll l, ll r, ll s, ll e, ll incr){
    // Updates the range of s - e with incr
    if (l > r || r < s || l > e)
        return;

    if (lazy[pos] != 0){
        // Lazy updates a range in the segment tree
        // Propagate values first;
        st[pos] += lazy[pos];
        if (l != r){
            lazy[pos*2 + 1] += lazy[pos];
            lazy[pos*2 + 2] += lazy[pos];
        }
        lazy[pos] = 0;
    }

    if (s <= l && e >= r){
        // Update this node
        st[pos] += incr;
        if (l != r){
            lazy[pos*2 + 1] += incr;
            lazy[pos*2 + 2] += incr;
        }
        return;
    }
    ll mid = l + ((r - l) >> 1);
    updateRange(2 * pos + 1, l, mid, s, e, incr);
    updateRange(2 * pos + 2, mid + 1, r, s,  e, incr);
    st[pos] = min(st[pos*2 +1], st[pos*2 + 2]);
}

ll queryRange(ll pos, ll l, ll r, ll s, ll e){
    // Query the range s - e for the minimum element
    if (l > r || r < s || l > e)
        return INT_MAX;

    if (lazy[pos] != 0){
        st[pos] += lazy[pos];
        if (l != r){
            lazy[pos*2 + 1] += lazy[pos];
            lazy[pos*2 + 2] += lazy[pos];
        }
        lazy[pos] = 0;
    }
    if (s <= l && e >= r)
        return st[pos];
    ll mid = l + ((r - l) >> 1);
    return min(queryRange(pos * 2 + 1, l, mid, s, e),
            queryRange(pos * 2 + 2, mid + 1, r, s, e));
}


int main(){
    ios :: sync_with_stdio(false);

    A = {8, 6, -1, 3, 4, 7};
    st.resize(A.size() * 4);
    lazy.resize(A.size() * 4);

    constructTree(0, 0, A.size() -1);

    while (1){
        for (auto a : A)
        cout << a << " - ";
        cout << "\n\n 1 m n x update with x: ";
        cout << "\n\n 2 min from m n update: ";
        int c, m, n, x;
        cin >> c;
        if (c == 1){
            cin >> m >> n >> x;
            updateRange(0, 0, A.size() -1, m, n, x);
            for (int i = m; i <= n; i++)
                A[i] += x;
        }
        else{
            cin >> m >> n;
            cout << queryRange(0, 0, A.size() -1, m, n) << endl;
        }
    }
    return 0;
}
