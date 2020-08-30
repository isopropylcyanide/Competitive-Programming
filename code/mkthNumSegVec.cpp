#include <bits/stdc++.h>
using namespace std;
/*------- Constants---- */

#define Long                    long long
#define Ulong                   unsigned long long
#define forn(i,n)               for( int i=0 ; i < n ; i++ )
#define mp(i,j)                 make_pair(i,j)
#define pb(a)                   push_back((a))
#define all(x)                  (x).begin(),(x).end()
#define gc                      getchar_unlocked
#define PI                      acos(-1.0)
#define EPS                     1e-9
#define xx                      first
#define yy                      second
#define lc                      ((n)<<1)
#define rc                      ((n)<<1|1)
#define db(x)                   cout << #x << " -> " << x << endl;
#define Di(x)                   int x;scanf("%d",&x)
#define min(a,b)                ((a)>(b) ? (b) : (a) )
#define max(a,b)                ((a)>(b) ? (a):(b))
#define ms(ara_name,value)      memset(ara_name,value,sizeof(ara_name))

/*************************** END OF TEMPLATE ****************************/

const int N = 4e5+5;
int n,q;
int a[N];
vector<int>v;
vector<int> seg[N];
void build(int n,int b,int e)
{
    if(b==e){
        seg[n].pb(a[b]);
        return;
    }
    int mid = (b+e)/2;
    build(lc,b,mid);
    build(rc,mid+1,e);
    merge(seg[lc].begin() , seg[lc].end(), seg[rc].begin(), seg[rc].end(),back_inserter(seg[n]));
}

int query(int n,int b,int e,int i,int j,int v)
{
    if(b>j || e< i) return 0;
    if(b>=i && e<= j) {
        int k = upper_bound(all(seg[n]), v ) - seg[n].begin();
        return k;
    }
    int mid = (b+e)/2;
    return query(lc,b,mid,i,j,v) + query(rc,mid+1,e,i,j,v);
}


int main()
{
    //freopen("in.txt","r",stdin);
    scanf("%d %d",&n,&q);
    for(int i = 1; i <= n; i ++ ) {
        scanf("%d",&a[i]);
        v.pb(a[i]);
    }
    sort(all(v));
    for(int i = 1;i <= n; i ++ ) {
        a[i] = lower_bound(all(v),a[i]) - v.begin() + 1;
    }

    build(1,1,n);

    while(q--) {
        int l,r,x;
        scanf("%d %d %d",&l,&r,&x);
        int low = 1, high = n , mid, ans ;
        while(low <= high) {
            mid = (low + high) >> 1;
            int k = query(1,1,n,l,r,mid);

            if(k >= x) {
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        printf("%d\n",v[ans-1]);
    }
    return 0;
}
