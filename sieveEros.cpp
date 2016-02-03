#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <cstdlib>
using namespace std;

#define max 10000000
typedef long long unsigned llu;
vector<bool> prime (max + 5, 1);

bool primeChecker(llu &n){
    if (n < 2)
        return false;
    if (n % 2 == 0)
        return n == 2;
    llu limit = (llu)sqrt(n*1.);
    for(llu i = 3; i <= limit ; i += 2)
        if (n % i == 0)
            return false;
    return true;
}

void normal_sieve(){
    prime[1] = prime[0] = 0;
	llu i = 2;

    while (i*i < max){
        if(prime[i] == 1)
          for(llu j= i*i; j < max; j += i)
              prime[j] = 0;
        i +=1;
    }
}


llu power(int a, int n, int mod){
     llu power=a,result=1;

     while(n){
      if(n&1)
       result=(result*power)%mod;
      power=(power*power)%mod;
      n>>=1;
     }
     return result;
}

bool witness(int a, int n){
 int t,u,i;
 llu prev,curr;

 u=n/2;
 t=1;
 while(!(u&1)) {
  u/=2;
  ++t;
 }

 prev=power(a,u,n);
 for(i=1;i<=t;++i) {
  curr=(prev*prev)%n;
  if((curr==1)&&(prev!=1)&&(prev!=n-1))
   return true;
  prev=curr;
 }
 if(curr!=1)
  return true;
 return false;
}

inline bool IsPrime( int number){
 if ( ((!(number & 1)) && number != 2 ) || (number < 2) || (number % 3 == 0 && number != 3) )
  return false;

 if(number<1373653){
  for( int k = 1; 36*k*k-12*k < number;++k)
  if ( (number % (6*k+1) == 0) || (number % (6*k-1) == 0) )
   return false;

  return true;
 }

 if(number < 9080191){
  if(witness(31,number)) return false;
  if(witness(73,number)) return false;
  return true;
 }


 if(witness(2,number)) return false;
 if(witness(7,number)) return false;
 if(witness(61,number)) return false;
 return true;

 /*WARNING: Algorithm deterministic only for numbers < 4,759,123,141 (unsigned int's max is 4294967296)
   if n < 1,373,653, it is enough to test a = 2 and 3.
   if n < 9,080,191, it is enough to test a = 31 and 73.
   if n < 4,759,123,141, it is enough to test a = 2, 7, and 61.
   if n < 2,152,302,898,747, it is enough to test a = 2, 3, 5, 7, and 11.
   if n < 3,474,749,660,383, it is enough to test a = 2, 3, 5, 7, 11, and 13.
   if n < 341,550,071,728,321, it is enough to test a = 2, 3, 5, 7, 11, 13, and 17.*/
}


int main(){

	llu testcases, N;
	scanf("%lld",&testcases);

	while(testcases--){
		scanf("%lld",&N);
        if (IsPrime(N))
            printf("Prime\n");
        else printf("Not prime\n");
    }
	return 0;
}
