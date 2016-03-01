#include "bits/stdc++.h"
using namespace std;
const int N = 5e4 + 4;
int n;
vector < int > v[N];
bool done[N];
int dp[N];
int cur[N];
int turn = 0;
int subtree[N];
int a, b;
bool sieve[N];
int primes[N];
int cnt;
long long res = 0;
int sz;
void pre(){
        cnt = 0;
        memset(sieve, 0, sizeof(sieve));
        sieve[0] = sieve[1] = 1;
        for(int i = 2; i * i < N; ++i) {
                if(!sieve[i]) {
                        for(int j = i * i; j < N; j += i) {
                                sieve[j] = 1;
                        }
                }
        }
        for(int i = 2; i < N; ++i) {
                if(!sieve[i]) {
                        primes[++cnt] = i;
                }
        }
}
void dfs1(int node, int parent){
        subtree[node] = 1;
        for(int next : v[node]) {
                if(next != parent && !done[next]) {
                        dfs1(next, node);
                        subtree[node] += subtree[next];
                }
        }
}
int find(int node, int parent){
        for(int next : v[node]) {
                if(next != parent && !done[next]) {
                        if(subtree[next] > sz) {
                                return find(next, node);
                        }
                }
        }
        return node;
}
void go(int node, int baap, int dist){
        for(int i = 1; i <= cnt; ++i) {
                if(primes[i] >= dist) {
                        if(cur[primes[i] - dist] == turn) {
                                res += dp[primes[i] - dist];
                        }
                }
        }
        for(int next : v[node]) {
                if(next != baap && !done[next]) {
                        go(next, node, dist + 1);
                }
        }
}
void upd(int node, int baap, int dist){
        if(cur[dist] != turn) {
                cur[dist] = turn;
                dp[dist] = 0;
        }
        ++dp[dist];
        for(int next : v[node]) {
                if(next != baap && !done[next]) {
                        upd(next, node, dist + 1);
                }
        }
}
void get(int node){
        ++turn;
        cur[0] = turn;
        dp[0] = 1;
        for(int next : v[node]) {
                if(!done[next]) {
                        go(next, node, 1);
                        upd(next, node, 1);
                }
        }
}
void solve(int node){
        dfs1(node, 0);
        sz = subtree[node] >> 1;
        int centroid = find(node, 0);
        get(centroid);
        done[centroid] = 1;
        for(int next : v[centroid]) {
                if(!done[next]) {
                        solve(next);
                }
        }
}
int main(){
        pre();
        scanf("%d", &n);
        for(int i = 1; i < n; ++i) {
                scanf("%d %d", &a, &b);
                v[a].emplace_back(b);
                v[b].emplace_back(a);
        }
        solve(1);
        double ans = res + res;
        ans /= n;
        ans /= n - 1;
        printf("%.6lf\n", ans);
}
