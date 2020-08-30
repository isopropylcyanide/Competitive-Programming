#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define MAX 100010
#define mp make_pair
#define pb push_back

ll ans;

struct my_comparator {
        bool operator() (const pii &a, const pii &b){
                return a.second > b.second;
        }
};

vector <pii> g[MAX];
vector <int> arr;
int d[MAX];
int n, m, a, b, w, u, v, i, t, j, flag;
priority_queue < pii, vector < pii >, my_comparator > prio_q;

ll x[MAX], y[MAX], z[MAX];
bool f[MAX];

void solve(){
        for(i = 3; i <= n; i++) {
                if(y[i] != x[i]+x[i - 1]) {
                        flag = 1;
                        break;
                }
        }
        for(i = 4; i <= n; i++) {
                if(z[i] != x[i] + x[i - 1] + x[i - 2]) {
                        flag = 1;
                        break;
                }
        }

        if(flag == 1) {
                for(i = 2; i <= n; i++) {
                        w = x[i];
                        g[i - 1].pb(mp(i, w));
                }
                for(i = 3; i <= n; i++) {
                        w = y[i];
                        g[i - 2].pb(mp(i, w));
                }

                for(i = 4; i <= n; i++) {
                        w = z[i];
                        g[i - 3].pb(mp(i, w));
                }
                for(j = 1; j<n; j++) {
                        for(i = 1; i <= n; i++) {
                                d[i]=1e9;
                                f[i]=0;
                        }
                        d[j] = 0;
                        prio_q.push(mp(j, 0));
                        while(!prio_q.empty()) {
                                u = prio_q.top().first;
                                prio_q.pop();
                                if(f[u])
                                        continue;
                                for(i = 0; i<g[u].size(); i++) {
                                        v = g[u][i].first;
                                        w = g[u][i].second;
                                        if(!f[v] && d[u] + w < d[v]) {
                                                d[v] = d[u] + w;
                                                prio_q.push(mp(v, d[v]));
                                        }
                                }
                                f[u] = 1;
                        }
                        for(i = j+1; i <= n; i++)
                                ans += d[i];
                }
                for(i = 1; i <= n; i++)
                        g[i].clear();
        }
        else
        {
                n--;
                if(n%2 == 0) {
                        arr.pb(n - 1);
                        for(i = n - 2; i >= 0; i -=2)
                                arr.pb(i+arr[arr.size() - 1]);
                        for(i = 2; i <= n - 2; i += 2)
                                arr.pb(arr[arr.size() - 1] - i);
                }
                else
                {
                        arr.pb(n - 1);
                        for(i = n - 2; i >= 1; i -=2)
                                arr.pb(i+arr[arr.size() - 1]);
                        for(i = 1; i <= n - 2; i += 2)
                                arr.pb(arr[arr.size() - 1] - i);
                }
                for(i = 2; i <= n+1; i++)
                        ans += x[i]*(arr[i - 2]+1);
                arr.clear();
        }
        printf("%lld\n", ans);

}

int main(){
        scanf("%d", &t);
        for(int s = 1; s <= t; s++) {
                ans = 0;
                flag = 0;
                scanf("%d", &n);
                for(i = 2; i <= n; i++)
                        scanf("%lld", &x[i]);

                for(i = 3; i <= n; i++)
                        scanf("%lld", &y[i]);

                for(i = 4; i <= n; i++)
                        scanf("%lld", &z[i]);
                solve();
        }
        return 0;
}
