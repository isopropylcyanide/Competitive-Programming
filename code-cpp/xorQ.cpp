#include <bits/stdc++.h>

using namespace std;

#define N 524287

int xorarr[20];

struct node {
	int count;
	node *left, *right;
	node (int count, node *left, node *right) {
		this -> count = count;
		this -> left = left;
		this -> right = right;
	}
	node* insert(int l, int r, int w);
};

node *null = new node(0, NULL, NULL);

node * node::insert(int l, int r, int v) {
	if(l <= v && v <= r) {
		if (l == r)
			return new node(this -> count + 1, null, null);
		return new node(this -> count + 1, this -> left -> insert(l, (l + r) >> 1, v), this -> right -> insert(((l + r) >> 1) + 1, r, v));
	}
	return this;
}

int kthorder(node * a, node * b, int l, int r, int k) {
	if (l == r)
		return l;
	int count = a -> left -> count - b -> left -> count;
	if (count >= k)
		return kthorder(a -> left, b -> left, l, (l + r) >> 1, k);
	return kthorder(a -> right, b -> right, ((l + r) >> 1) + 1, r, k - count);
}

int smallerthan(node * a, int l, int r, int x) {
	if (x >= r)
		return a -> count;
	if (x < l)
		return 0;
	return smallerthan(a -> left, l, (l + r) >> 1, x) + smallerthan(a -> right, ((l + r) >> 1) + 1, r, x);
}

void maxXOR(node * a, node * b, int l, int r, int d) {
	int lc = a -> left -> count - b -> left -> count;
	int rc = a -> right -> count - b -> right -> count;
	if ((lc == 0) && (rc == 0)) {
		return;
	}
	if (xorarr[d] == 0) {
		if (rc) {
			xorarr[d] = 1;
			maxXOR(a -> right, b -> right, ((l + r) >> 1) + 1, r, d + 1);
		} else {
			maxXOR(a -> left, b -> left, l, (l + r) >> 1, d + 1);
		}
	} else {
		if (lc) {
			maxXOR(a -> left, b -> left, l, (l + r) >> 1, d + 1);
		} else {
			xorarr[d] = 0;
			maxXOR(a -> right, b -> right, ((l + r) >> 1) + 1, r, d + 1);
		}
	}
}

node *root[N];
int A[1000000];

int main() {
	ios_base::sync_with_stdio(false);
	int n, m, t, x, l, r;
	null -> left = null -> right = null;
	scanf("%d", &m);
	n = 0;
	while(m--) {
		scanf("%d", &t);
		if (t == 0) {
			scanf("%d", &x);
			root[n] = (n == 0 ? null : root[n - 1]) -> insert(0, N, x);
			A[n] = x;
			n += 1;
		}
		if (t == 1) {
			scanf("%d", &l);
			scanf("%d", &r);
			scanf("%d", &x);
			int y = x;
			l -= 1;
			r -= 1;
			for(int i = 0; i < 20; i += 1)
				xorarr[i] = 0;
			int j = 19;
			while(x > 0) {
				xorarr[j] = 0;
				if (x % 2)
					xorarr[j] = 1;
				j -= 1;
				x /= 2;
			}
			maxXOR(root[r], (l == 0 ? null : root[l - 1]), 0, N, 1);
			int ans = 0;
			for(int i = 0, j = 19; j >= 0; j -= 1, i += 1) {
				ans += xorarr[j] << i;
			}
			ans ^= y;
			printf("%d\n", ans);
		}
		if (t == 2) {
			scanf("%d", &x);
			n -= x;
		}
		if (t == 3) {
			scanf("%d", &l);
			scanf("%d", &r);
			scanf("%d", &x);
			l -= 1;
			r -= 1;
			int ans = smallerthan(root[r], 0, N, x) - smallerthan((l == 0 ? null : root[l - 1]), 0, N, x);
			printf("%d\n", ans);
		}
		if (t == 4) {
			scanf("%d", &l);
			scanf("%d", &r);
			scanf("%d", &x);
			l -= 1;
			r -= 1;
			int ans = kthorder(root[r], (l == 0 ? null : root[l - 1]), 0, N, x);
			printf("%d\n", ans);
		}
	}
}
