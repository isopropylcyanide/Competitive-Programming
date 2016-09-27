#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;
static int C[1007];
bool b;
map<int,vi> adj;
void dfs(int x){
    for(int y:adj[x]){
        if(C[y]==C[x]){b=false;return ;}// this means the graph is not bipartite
        if(C[y]==0){
            if(C[x]==1) C[y]=2;
            else C[y]=1;
            dfs(y);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc;
    scanf("%d",&tc);
    while(tc-->0){
            b=true;
            memset(C,0,sizeof C);
        int n,q;
        scanf("%d%d",&n,&q);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
            if(i!=j)
            adj[i].push_back(j);
        for(int i=0;i<q;i++){// we read the edges in G and erase them from G^c
        int u,v;
        scanf("%d %d",&u,&v);
        vector<int>::iterator it=find(adj[u].begin(), adj[u].end(), v);
        if(it!=adj[u].end())
        adj[u].erase(std::remove(adj[u].begin(), adj[u].end(), v), adj[u].end());
        it=find(adj[v].begin(), adj[v].end(), u);
        if(it!=adj[v].end())
        adj[v].erase(std::remove(adj[v].begin(), adj[v].end(), u), adj[v].end());
    }
    for(int i=1;i<=n;i++){
        if(C[i]==0){// if i has not been explored yet we dfs from i
            C[i]=1;
            dfs(i);
        }
    }
   if(b)
    printf("YES\n");
   else
    printf("NO\n");
    adj.clear();
    }//while loop tc
    return 0;
}
