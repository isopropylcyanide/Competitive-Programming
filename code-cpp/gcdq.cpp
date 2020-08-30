#include<cstdio> /*code to find GCD of a list between two numbers*/
#include<vector>
#include<algorithm>
#define gc getchar_unlocked    
  using namespace std;
     
typedef long long unsigned llu;
  
	 
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


    llu i,t,n,q,l,r,temp,ans;
     
    inline llu gcd(llu x,llu y){
    while (y){
    temp=x;
    x=y;
    y=temp%y;
    }
    return x;
    }
     
     
    int main()
    {
    t=read_int();
     
    while (t){
	
    n=read_int();
    q=read_int();
    vector<llu>list(n,1);
     
    for(i=0; i<list.size(); ++i)
    list[i]=read_int();
     
    while(q){
    vector<bool>exclude(n,true);
     
    l=read_int();
    r=read_int();
    --l,--r;
     
    for(i=l; i<r+1; ++i)
    exclude[i]=false;
     
    int j=0;
     
    for(i=0; i<exclude.size(); ++i){
    if(exclude[i]){
    if(j==0) ans=list[i];
    ans=gcd(ans,list[i]);
    ++j;
    }
    }
    printf("%lld\n",ans);
    q--;
 
    }
    --t;
    list.clear();
    }
    return 0;
    } 
