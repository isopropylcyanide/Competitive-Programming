#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define F first
#define S second

const int N = 1111;

int n, m;
bool used[N][N];
vector< pair<int, int> > g[N];

int main() {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= m; i++) {
                int u, v, c;
                scanf("%d%d%d", &u, &v, &c);
                g[u].pb(mp(v, c));
                g[v].pb(mp(u, c));
        }
        int a, b;
        scanf("%d%d", &a, &b);
        queue< pair<int, int> > q;
        q.push(mp(a, 0));
        while (!q.empty()) {
                int ver = q.front().F;
                int res_or = q.front().S;
                q.pop();
                used[ver][res_or] = true;
                for (size_t j = 0; j < g[ver].size(); j++) {
                        int to = g[ver][j].F;
                        int add = g[ver][j].S;
                        if (!used[to][(add | res_or)]) {
                                used[to][(add | res_or)] = true;
                                q.push(mp(to, (add | res_or)));
                        }
                }
        }
        int ans = -1;
        for (int i = 0; i < N; i++) {
                if (used[b][i]) {
                        ans = i;
                        break;
                }
        }
        printf("%d\n", ans);
        return 0;
}
