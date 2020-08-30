#include<cstdio> 
#include<vector> 
#define mod 1000003 
using namespace std; 
typedef long long unsigned llu;

//some part of this code was taken from http://www.codechef.com/viewsolution/4994917 to calculate nCr 

long long countFact(llu n, int p) 
{
 int k=0; 
 while (n>=p)
  {
    k+=n/p;
    n/=p;
  }
 return k; 
}

long long pow(int a, int b, int MOD) 
{
 long long x=1,y=a; 
  while(b > 0) 
  {
    if(b%2 == 1)
   { 
    x=(x*y);
    if(x>MOD) x%=MOD;
   }
   y = (y*y); 

  if(y>MOD) y%=MOD; b /= 2; 
  }

 return x; 
}


long long InverseEuler(int n, int MOD)
{
  return pow(n,MOD-2,MOD);
 }

long long factMOD(llu n, int MOD)
{
  long long res = 1;
  while (n > 0) 
  {
   for (int i=2, m=n%MOD; i<=m; i++) 
      res = (res * i) % MOD; 

    if ((n/=MOD)%2 > 0)
    res = MOD - res;
  }
 return res; 
}

long long comb1( llu n, llu r, int MOD) 
{
  if (countFact(n, MOD) > countFact(r, MOD) + countFact(n-r, MOD))
   return 0;

   return (factMOD(n, MOD) * ((InverseEuler(factMOD(r, MOD), MOD) * InverseEuler(factMOD(n-r, MOD), MOD)) % MOD)) % MOD;
}



 int main() 
{ 
    int t; scanf("%d",&t);

    llu n,l,r,c_term,count=0;

    while(t--) 
    {
     scanf("%lld %lld %lld",&n,&l,&r);
     c_term=r-l+1;

     count=comb1(c_term+n,min(n,c_term),mod);
     printf("%lld\n",(count-1+mod)%mod);
   }

    return 0;
}
   

