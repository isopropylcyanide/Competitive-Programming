#include<bits/stdc++.h>
using namespace std;
#define pb push_back
int vis[100007];
vector<int>v[100007];
int dpim[100007][27];
int dfs(int parent,int a)
{
    dpim[a][0]=parent;
    int i=0;
    while(dpim[a][i])
    {
        i++;
        dpim[a][i]=dpim[dpim[a][i-1]][i-1];
    }
    vis[a]=1;
    int lm=v[a].size();
    for(i=0;i<lm;i++)
        if(!vis[v[a][i]])
            dfs(a,v[a][i]);
    return 0;
}
int main()
{
    int m;
    scanf("%d",&m);
    int i;
    for(i=1;i<m;i++)
    {
        int tem;
        int temp;
        scanf("%d %d",&tem,&temp);
        v[tem].pb(temp);
        v[temp].pb(tem);
    }
    dfs(0,1);
    int q;
    scanf("%d",&q);
    for(i=0;i<q;i++)
    {
        int tem;
        int temp;
        scanf("%d %d",&tem,&temp);
        int i=0;
        int j=temp;
        int ans=tem;
        while((j>>i)&&ans)
        {
            if((j>>i)&1)
                ans=dpim[ans][i];
            i++;
        }
        if(!ans)
            ans=1;
        printf("%d\n",ans);
    }
    return 0;
}
