#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
vector<ll> T, pw, P, L, visited, v1, v2, temp;
vector< vector<ll> >tre;

vector<vector<pll> > vec;
ll ans = 0, n, x, y, z, w, q, a, b, k;

void pre(ll node,ll le){
    if(visited[node]==1) return;
    visited[node]=1;
    L[node]=le;
    for(ll i=0; i<vec[node].size(); i++) {
            if(visited[vec[node][i].first]==1) continue;
            T[vec[node][i].first]=node;
            pw[vec[node][i].first]=vec[node][i].second;
            tre[node].push_back(vec[node][i].first);
            pre(vec[node][i].first,le+1);
    }
}


void make_p(ll node,ll nr){
    if(L[node]<nr) P[node]=1;
    else if(!(L[node]%nr)) P[node]=T[node];
    else P[node]=P[T[node]];

    for(int k=0; k<tre[node].size(); k++) make_p(tre[node][k],nr);
}


ll LCA(ll x,ll y){
    while(P[x]!=P[y]) {
        if(L[x]>L[y]) x = P[x];
        else y = P[y];
    }

    while(x!=y) {
        if(L[x]>L[y]) x=T[x];
        else y=T[y];
    }
    return x;
}


void solve(ll a,ll b,ll k,ll lca){

    while(a!=lca) {
        v1.push_back(a);
        a=T[a];
    }

    while(b!=lca){
        v2.push_back(b);
        b=T[b];
     }

    for(int j=v2.size()-1; j>=0; j--)
            temp.push_back(pw[v2[j]]);
    for(int i=v1.size()-1; i>=0; i--)
            temp.push_back(pw[v1[i]]);

    if(temp.size()<k) ans=-1;
    else{
        sort(temp.begin(),temp.end());
        ans=temp[k-1];
    }
    temp.clear();
    v1.clear();
    v2.clear();
}

int main(){

    scanf("%lld",&n);
    T.resize(n+1,0);
    pw.resize(n+1);
    vec.resize(n+1);
    L.resize(n+1);
    tre.resize(n+1);
    visited.resize(n+1,0);
    P.resize(n+1);

    for(ll i=1; i<n; i++) {
            scanf("%lld %lld %lld",&x,&y,&w);
            vec[x].push_back(make_pair(y,w));
            vec[y].push_back(make_pair(x,w));
    }

    pre(1,0);

    ll nr =0;
    for(int i=1; i<=n; i++) nr = max(nr,L[i]);
    nr++;

    nr = sqrt(nr);

    make_p(1,nr);

    //cout<<LCA(5,2);
    ll q;
    scanf("%lld",&q);
    ll last=0;

    while(q--) {
            scanf("%lld%lld%lld",&a,&b,&k);
            ll reala = ((a-1+max(last,ans))%n)+1;
            ll realb = ((b-1+2*max(last,ans))%n)+1;
            ll realk = ((k-1+3*max(last,ans))%n)+1;

            ll lca = LCA(reala,realb);
            solve(reala,realb,realk,lca);
            cout<<ans<<endl;
    }
    return 0;
}
