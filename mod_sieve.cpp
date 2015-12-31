#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <cstdlib>
using namespace std;

#define max 5000000
typedef long long unsigned llu;

/*
 is it possible to transform the equilateral triangle keeping two sides fixed and alter the third side such that it
 still remains a triangle, but the altered side will have its length as an even integer, and the line drawn
 from the opposite vertex to the mid-point of the altered side is of integral length.
*/

void normal_sieve(){
	llu i=2;
	llu prime[max + 1];

    while (i*i<max){

        if(prime[i]==0)
          for(llu j=i*i; j<max; j+=i)
              prime[j]=1;
        // }
        i+=1;
    }
}
void precompute_minimum_prime(vector<llu>&pre_c){
	/*Precomputes first minimum prime of any number*/

	llu i=2,k;
	while (i*i<=max){

		if (pre_c[i]==0)
			k=i*i;

		while(k<=max){
			if (pre_c[k]==0)
				pre_c[k]=i;
			k+=i;
		}
		i+=1;
	}
}

vector<llu> factorization(llu x,vector<llu>&F){
	/*Once we have the minimum prime we can have others easily*/

	vector<llu>primeFactors;
	while (F[x]>0){
		primeFactors.push_back(F[x]);
		x/=F[x];
	}

	primeFactors.push_back(x);
	return primeFactors;
}

void get_4k_plus_3_count(llu N,vector<llu>& pre_c,llu &even_1,llu &even_3){
	/*For each of its prime factorisation not including 1 and 2
	  find number of factor=1 mod4 and 3 mod4. If count of 3mod4 is odd.
	  Then no solution, else there exists 1mod4 solutions.
	*/

	vector<llu>ans=factorization(N,pre_c);
	vector<llu>:: iterator it=ans.begin();

	for(;it!=ans.end();it++){
		if(*it<=2)continue;
		if ((*it)%4==1)even_1+=1;
		if ((*it)%4==3)even_3+=1;
	}
}

int main(){

	vector<llu>prime_precomp(max+1,0);
	precompute_minimum_prime(prime_precomp);

	llu testcases,N,even_1,even_3;
	scanf("%lld",&testcases);

	while(testcases--){
		scanf("%lld",&N);

		even_1=0,even_3=0;
		get_4k_plus_3_count(N,prime_precomp,even_1,even_3);

		even_1*=2,even_3*=2;
		llu ans=0;
		if (even_3%2==0)
			ans=even_1;
		if(ans)printf("YES\n");
		else printf("NO\n");

	}

	return 0;
}

