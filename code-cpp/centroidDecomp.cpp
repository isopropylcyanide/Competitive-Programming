#include<bits/stdc++.h>
using namespace std;

/*You are given a tree. If we select 2 distinct nodes uniformly at random, what's the probability that the distance between these 2 nodes is a prime number?
*/
typedef long long int 	ll;

const int N = int(5e4)+10;
const int LOGN = 17;

set<int> g[N];
int ndist[LOGN][N], sub[N];
int P[N], Pr[N], len;
ll ans; int num;

void dfs1(int u, int p){
    // Store sub tree count for each node
	sub[u] = 1; num++;
	for(auto it : g[u])
		if(it != p)
			dfs1(it, u), sub[u] += sub[it];
}

int dfs2(int u, int p){
    // Centroid decompose for each node
	for(auto it :g[u])
		if(it != p && sub[it]>num/2)
			return dfs2(it, u);
	return u;
}

void dfs3(int u, int p, int depth, int dist, int add){
	ndist[depth][dist] += add;
	for(auto it : g[u])
		if(it != p)
			dfs3(it, u,depth, dist+1, add);
}

ll dfs4(int u, int p, int depth, int dist){
	ll ret = 0;
	for(int i = 0; i<len; i++){
		if(P[i]-dist<0)
            continue;
		if(!ndist[depth][P[i]-dist])
            break;
		if(P[i] != dist)
			ret += ndist[depth][P[i]-dist];
		else
			ret += 2*ndist[depth][P[i]-dist];
	}
	for(auto it : g[u])
		if(it != p)
			ret += dfs4(it, u,depth, dist+1);
	return ret;
}


void decompose(int root, int depth){
	num = 0;
	dfs1(root, root);
	int centroid = dfs2(root, root);
	dfs3(centroid, centroid, depth, 0,1);

	ll add = 0;
	int u = centroid;

	for(auto it : g[u]){
		dfs3(it, u,depth, 1,-1);
		add +=  dfs4(it, u,depth, 1);
		dfs3(it, u,depth, 1,1);
	}
	ans += add/2;
	for(auto it : g[u]){
		g[it].erase(u);
		decompose(it, depth+1);
	}
	for(int i = 0; i<N && ndist[depth][i]; i++)
		ndist[depth][i] = 0;
}

void sieve(){
	for(int i = 2; i*i<N; i++)
		if(!Pr[i])
			for(int j = i*i; j<N; j += i)
				Pr[j] = 1;
	for(int i = 2; i<N; i++)
		if(!Pr[i])
			P[len++] = i;
}

int main(){
	sieve();
	int n;
	scanf("%d\n", &n);
	for(int i = 0; i<n-1; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		g[a-1].insert(b-1);
		g[b-1].insert(a-1);
	}
	decompose(0, 0);
	double den = (ll)n*(ll)(n-1)/2.0;
	printf("%0.10lf\n", ans/den);
	return 0;
}
