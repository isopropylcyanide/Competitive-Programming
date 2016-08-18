#include <bits/stdc++.h>
using namespace std;

#define BLOCK_SIZE 320
#define MAX 100005

// Use Mo's square root decomposition to order queries

typedef struct query{
	long long hash;
	int l, r, id;
}query;

map<long long,int> counts;
long long A[MAX];
int answer[MAX];
vector<query> Q(MAX);

inline bool cmp(query a,query b){
	a.l /= BLOCK_SIZE;
	b.l /= BLOCK_SIZE;
	return a.l == b.l ? a.r < b.r : a.l < b.l;
}
inline long long getHash(string &str){
	int j;
	long long hash = 0;
	for(j = 0; str[j]; j++){
		hash *= 27;
		hash += str[j]-'a';
	}
	for(; j < 10; j++)
		hash *= 27;
	return hash;
}

int n, q;
string s;

int main(){
	ios::sync_with_stdio(false);
	cin >> n;

	for(int i = 0; i < n; i++){
		cin >> s;
		A[i] = getHash(s);
	}
	cin >> q;

	for(int i = 0; i < q; i++){
		cin >> Q[i].l >> Q[i].r >> s;
		Q[i].hash = getHash(s);
		Q[i].l--;
		Q[i].r--;
		Q[i].id=i;
	}

	sort(Q.begin() , Q.begin() + n, cmp);

	int l = 0, r = -1;

	for(int i = 0; i < q; i++){
		while(l > Q[i].l){
			l--;
			counts[A[l]]++;
		}
		while(r < Q[i].r){
			r++;
			counts[A[r]]++;
		}
		while(r > Q[i].r){
			counts[A[r]]--;
			r--;
		}
		while(l < Q[i].l){
			counts[A[l]]--;
			l++;
		}
		answer[Q[i].id] = counts[Q[i].hash];
	}

	for(int i = 0; i < q; i++)
		cout << answer[i] << "\n";
}
