#include <bits/stdc++.h>
using namespace std;
const int N=200005;
int n,a[N],b[N],c[N],d[N];
int fin(int x){
    if (d[x]==x) return x;
    return d[x]=fin(d[x]);
}
int main() {
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%d",&a[i]),
        d[i]=i;
    c[n]=a[n];
    b[1]=a[1];
    for (int i=2;i<=n;i++) 
        b[i]=max(b[i-1],a[i]);
    for (int i=n-1;i>=1;i--) 
        c[i]=min(c[i+1],a[i]);
    for (int i=2;i<n;i++){
        if (b[i-1]>=a[i] && a[i]>=c[i+1]) {
            cout<<0<<endl;
            return 0;
        }
    }
    stack <pair <int,int> > S;
    for (int i=n;i>=1;i--){
        int m=a[i];
        while (!S.empty() && S.top().first<=a[i]){
            d[fin(S.top().second)]=i;
            m=min(m,S.top().first);
            S.pop();
        }
        S.push(make_pair(m,i));
    }
    long long ans=1;
    for (int i=1;i<=n;i++) 
        ans=ans*(1+(d[i]==i))%1000000007ll;
    cout<<ans<<endl;
    return 0;
}
