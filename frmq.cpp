#include<cstdio>		
#include<vector>
#include<cmath>
#include<cstring>
#define gc getchar_unlocked    
using namespace std;
typedef long long unsigned llu;

llu max(llu a,llu b)
{return a>b?a:b; }

llu create_seg(vector<llu>& lis,vector<llu> & M,llu node,llu b,llu e)
{
   if (b>e)return 0;
   if (b==e)
    {
	M[node]=lis[b];
	return M[node];
    }
   else
    {
	llu left=2*node;
	llu right=left+1;
	llu mid=(b+e)/2;

	M[node]=max(create_seg(lis,M,left,b,mid),create_seg(lis,M,right,mid+1,e));
	return M[node];
    }
}


llu get_max(llu node,llu a,llu b,vector<llu> & M,llu i,llu j)
{
    if (i>b || j<a)return -1;
    if (a>=i and b<=j)return M[node];
	llu mid=(a+b)/2;
	
	llu l=2*node;
	llu r=l+1;
	llu left=get_max(l,a,mid,M,i,j);
	llu right=get_max(r,mid+1,b,M,i,j);

	if (left==-1)return right;
	if (right==-1)return left;

	if (M[left]<=M[right])return left;
	else return right;
}



 llu read_int() {
  char c = gc();
  while(c<'0' || c>'9') c = gc();
  llu ret = 0;
  while(c>='0' && c<='9') {
    ret = 10 * ret + c - 48;
    c = gc();
  }
  return ret;
}


int main()
{
  llu i,m,n,xp,yp,ans=0;
  vector<llu>lis;
  n=read_int();

  for(i=0; i<n; i++)
  {
   m=read_int();
   lis.push_back(m);
  }
  m=read_int();
  xp=read_int();
  yp=read_int();

  llu x=(int)(ceil(log2(n)))+1;

  vector<llu>M(2*(int)pow(3,x),-1);
  
  create_seg(lis,M,1,0,n-1);

if (yp<xp)
	ans=get_max(1,0,n-1,M,yp,xp);
else
	ans=get_max(1,0,n-1,M,xp,yp);


for (i=2; i<=m; i++)
  {
	xp=(xp+7)%(n-1);
	yp=(yp+11)%n;
		
	if (yp<xp)
		ans+=get_max(1,0,n-1,M,yp,xp);
	else
		ans+=get_max(1,0,n-1,M,xp,yp);
  }

  printf("%lld\n",ans);

 return 0;
}




























