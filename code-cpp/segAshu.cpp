#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MAX 100005

/*
Query 0:- modify the element present at index i to x.
Query 1:- count the number of even numbers in range l to r inclusive.
Query 2:- count the number of odd numbers in range l to r inclusive.
*/


struct node{
	ll odd;
	ll even;
};
ll A[MAX];
node st[4* MAX];

void build(ll l, ll r, ll pos){
	if(l > r)
		return;
	if(l == r){
        st[pos].odd = (A[l] & 1);
        st[pos].even = not (A[l] & 1);
	}
	else{
		ll mid = l + ((r - l) >> 1);
		build(l, mid, 2*pos + 1);
		build(mid + 1, r, 2*pos + 2);
		st[pos].odd = st[2*pos + 1].odd + st[2*pos + 2].odd;
		st[pos].even = st[2*pos + 1].even + st[2*pos + 2].even;
	}
}
void update(ll l, ll r, ll i, ll val, ll pos){
	if(l>r)
		return;
	if(l == r){
		A[i] = val;
        st[pos].odd = (A[l] & 1);
        st[pos].even = not (A[l] & 1);
	}
	else{
		ll mid = l + ((r - l) >> 1);
		if(i >= l && i <= mid)
			update(l, mid, i, val, 2*pos + 1);
		else
			update(mid + 1, r, i, val, 2*pos + 2);

		st[pos].odd = st[2*pos + 1].odd + st[2*pos + 2].odd;
		st[pos].even = st[2*pos + 1].even + st[2*pos + 2].even;
	}
}

ll query(ll l, ll r, ll s, ll e, ll pos, ll type){
	if(s > r || e < l)
		return 0;

    if(s <= l && r <= e)
		return type == 1 ? st[pos].even : st[pos].odd;

	else{
		ll mid = l + ((r - l) >> 1);
		return query(l, mid, s, e, 2*pos + 1, type) +
	       query(mid + 1, r, s, e, 2*pos + 2, type);
	}
}

int main(){
	std::ios::sync_with_stdio(false);
	ll n, q;
	cin >> n;
	for(ll i = 0; i < n; ++i)
		cin >> A[i];
	build(0, n-1, 0);
	cin >> q;
	ll type, l, r, i, x;
	while(q--)
	{
		cin >> type;
		if(type == 0){
			cin >> i >> x;
			i--;
			update(0, n-1, i, x, 0);
		}
		else{
			cin >> l >> r;
			l--; r--;
			ll ans = query(0, n-1, l, r, 0, type);
			cout << ans << endl;
		}
	}
	return 0;
}
