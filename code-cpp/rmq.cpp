#include <bits/stdc++.h>
using namespace std;

int MAX = 100005;
int *A;
int *st;

int N, Q, l, r, i;
char t;

int min(int a, int b){
	return a < b ? a : b;
}

void build(int pos, int l, int r){
	if (l > r)
		return;
	if (l == r){
        st[pos] = A[l];
        return;
    }
	int mid = l + ((r - l) >> 1);
	build(2*pos + 1, l, mid);
	build(2*pos +2, mid + 1, r);
	st[pos] = min(st[pos*2 + 1], st[pos*2 + 2]);
}

int query(int pos, int l, int r, int s, int e){
	if (s > r || e < l)
		return INT_MAX;
	if (s <= l && r <= e)
		return st[pos];
	int mid = l + ((r - l) >> 1);
	return min(query(2*pos + 1, l, mid, s, e), query(2*pos +2, mid +1, r, s, e));
}

void update(int pos, int l, int r, int i, int val){
	if (i < l || i > r)
		return;
	if (l == r){
        st[pos] = val;
        return;
    }
	int mid = l + ((r - l) >> 1);
	build(2*pos + 1, l, mid);
	build(2*pos +2, mid + 1, r);
	st[pos] = min(st[pos*2 + 1], st[pos*2 + 2]);
    return;
}

int main(){
	cin >> N >> Q;
	A = (int *)malloc(sizeof(int) * N + 10);
	st = (int *)malloc(sizeof(int) * 4 * N + 10);

	for (i = 0; i < N; i++)
		cin >> A[i];

	build(0, 0, N -1);

	for (i = 0; i < Q; i++){
		cin >> t >> l >> r;
		if (t == 'q')
            printf("%d\n", query(0, 0, N -1, l -1, r -1));
		else{
			A[l -1] = r;
			update(0, 0, N -1, l -1, r);
		}
	}


}
