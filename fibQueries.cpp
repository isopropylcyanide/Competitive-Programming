#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>

const int MAXN = 100000 + 5;
const int MOD = 1000000000 + 7;

class SegmentTree {
private:
	struct Matrix {
		int a[2][2];

		Matrix operator * (const Matrix &you) {
			Matrix answer;
			answer.a[0][0] = answer.a[0][1] = answer.a[1][0] = answer.a[1][1] = 0;
			for(int i = 0; i < 2; i++)
				for(int j = 0; j < 2; j++)
					for(int k = 0; k < 2; k++)
						answer.a[i][j] = (answer.a[i][j] + a[i][k] * 1LL * you.a[k][j]) % MOD;
			return answer;
		}

		Matrix operator + (const Matrix &you) {
			Matrix answer;
			for(int i = 0; i < 2; i++)
				for(int j = 0; j < 2; j++)
					answer.a[i][j] = (a[i][j] + you.a[i][j]) % MOD;
			return answer;
		}

	};

	struct TreeNode {
		int l;
		int r;
		Matrix tag;

	} tree[MAXN * 4];

	void init (int pos, int l, int r) {
		tree[pos].l = l;
		tree[pos].r = r;
		for(int i = 0; i < 2; i++)
			for(int j = 0; j < 2; j++)
				tree[pos].tag.a[i][j] = 0;
		if (l < r) {
			init(pos + pos, l, (l + r) / 2);
			init(pos + pos + 1, (l + r) / 2 + 1, r);
		}
 	}

 	inline Matrix unite (Matrix a, Matrix b) {
		return ((a + b) + (a * b));
	}

 	void modify (int pos, int index, Matrix key) {
		if (tree[pos].l == tree[pos].r) {
			tree[pos].tag = key;
			return ;
		}
		if (tree[pos + pos].r >= index) {
			modify(pos + pos, index, key);
		} else {
			modify(pos + pos + 1, index, key);
		}
		tree[pos].tag = unite(tree[pos + pos].tag, tree[pos + pos + 1].tag);
	}

	Matrix query (int pos, int l, int r) {
		if (tree[pos].l == l && tree[pos].r == r) {
			return tree[pos].tag;
		}
		Matrix answer_left;
		Matrix answer_right;
		for(int i = 0; i < 2; i++)
			for(int j = 0; j < 2; j++)
				answer_left.a[i][j] = answer_right.a[i][j] = 0;
		if (l <= std::min(r, tree[pos + pos].r)) {
			answer_left = query(pos + pos, l, std::min(r, tree[pos + pos].r));
		}
		if (std::max(l, tree[pos + pos + 1].l) <= r) {
			answer_right = query(pos + pos + 1, std::max(l, tree[pos + pos + 1].l), r);
		}
		return unite(answer_left, answer_right);
	}

public:

	void init (int size) {
		init(1, 1, size);
	}

	void modify (int pos, long long key) {
		Matrix current_power;

		current_power.a[0][0] = current_power.a[0][1] = current_power.a[1][0] = 1;
		current_power.a[1][1] = 0;

		Matrix actual_key;

		actual_key.a[0][0] = actual_key.a[1][1] = 1;
		actual_key.a[0][1] = actual_key.a[1][0] = 0;

		for(int i = 0; (1LL << i) <= key; ++i) {
			if (key & (1LL << i)) {
				actual_key = (actual_key * current_power);
			}
			current_power = (current_power * current_power);
		}
		modify(1, pos, actual_key);
	}

	int query (int l, int r) {
		return (query(1, l, r)).a[0][1];
	}

};

SegmentTree tree1;

int main () {
	int size, number_of_queries;
	std::ios_base::sync_with_stdio(false);
	std::cin >> size >> number_of_queries;
    
	tree1.init(size);
	for(int i = 1; i <= size; i++) {
		long long x;
		std::cin >> x;
		tree1.modify(i, x);
	}
	while (number_of_queries--) {
		long long x, y;
		std::string query_type;
		std::cin >> query_type >> x >> y;
		if (query_type == "C") {
			tree1.modify(x, y);
		} else {
			std::cout << tree1.query(x, y) << std::endl;
		}
	}
	return 0;
}
