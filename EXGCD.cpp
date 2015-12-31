#include <cstdio>

#define MAX 10000003
#define ROOT 500

#define MOD 1000000007

// Euler totient
int phi[MAX];

jj
ddddd
// Modular multiplication
int mul(int a, int b){
	return (long long)a*b%MOD;
}

// Modular exponentiation
int power(int base, int exponent){
	if(exponent == 0)
		return 1;
	if(exponent & 1)
		return mul(base, power(base, exponent-1));
	int root = power(base, exponent/2);
	return mul(root, root);
}

// Modular inverse
int inv(int a){
	return power(a, MOD-2);
}

int solve(const int A[], const int B[], int K){
	int P=0, Q=1;
	int lo = MAX;
	// Q is product(B[i]-A[i]+1)%MOD
	for(int i=0; i<K; i++){
		Q=mul(Q, B[i]-A[i]+1);
		if(B[i] < lo)
			lo = B[i];
	}
	// P is sum(gcd(x_i))%MOD.  See the editorial for derivation
	for(int i=1; i<=lo; i++){
		int product=phi[i];
		for(int j=0; j<K; j++)
			product=mul(product, B[j]/i - (A[j]-1)/i);
		P=(P+product)%MOD;
	}
	return mul(P, inv(MOD-Q));
}

int main(){
	// Precompute phi using a sieve
	phi[1]=1;
	for(int i=2; i<MAX; i++){
		if(phi[i]==0){
			phi[i]=i-1;
			if(i<ROOT){
				for(int j=i*i; j<MAX; j+=i){
					phi[j]=i;
				}
			}
		}else{
			int d=phi[i];
			int j=i/d;
			phi[i]=(j%d==0 ? d : d-1)*phi[j];
		}
	}

	// for(int i=1; i<100; i++)
	// 	printf("%d ", phi[i]);
	// Read, solve, print
	// int T, K, A[5], B[5];
	// scanf("%d", &T);
	// while(T--){
	// 	scanf("%d", &K);
	// 	for(int i=0; i<K; i++)
	// 		scanf("%d %d", A+i, B+i);
	// 	printf("%d\n", solve(A, B, K));
	// }
	return 0;
}