#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<cmath>
#define gc getchar_unlocked 

using namespace std;
typedef long long unsigned llu;
llu mod=1000000007;

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
  llu t,i,j,n,ans=0;
  t=read_int();

  llu * lis=NULL;

  while(t--){
  
  n=read_int();
  lis=new llu[n];

  for(i=0; i<n; i++)
  lis[i]=read_int();
   
  sort(lis,lis+n);

  for(i=0; i<n-1; i++)
    for(j=i+1; j<n; j++)
    ans=(ans+ (lis[j]-lis[i])*int(pow(2,j-i-1)))%mod;
      
  cout<<ans%mod<<endl;
  ans=0;
 }

 return 0;
}























