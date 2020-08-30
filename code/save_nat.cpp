#include <bits/stdc++.h>
#include <iostream>
#define llu long long int
llu **mat;

//Find number of submatrices whose sum is less than a particular value

llu check_mat(llu a,llu b,llu m,llu n,llu **mat){

	llu sub_sum=0;

	for(llu i=a; i<=m; i++)
		for (llu j=b; j<=n; j++)
			sub_sum+=mat[i][j];
	
	return sub_sum;
}

void solve(llu N,llu M,llu **mat,llu S){

	llu sub_less_than_S=0;

	for(llu i=0; i<N; i++)
		for(llu j=0; j<M; j++)
			for (llu m = i; m<N; m++)
				for (llu n=j; n<M; n++)
					sub_less_than_S+=check_mat(i,j,m,n,mat)<=S?1:0;

	printf("%lld\n",sub_less_than_S);
}



int main(){
	llu testcases,N,M,S;
	scanf("%lld",&testcases);

	while(testcases--){

		scanf("%lld %lld %lld",&N,&M,&S);
		mat = new llu*[N];
		for(llu i=0; i<N; i++)
			mat[i ]= new llu[M];

		for (llu i = 0; i < N; ++i)
			for (llu j = 0; j < M; ++j)
				scanf("%lld",&mat[i][j]);

		solve(N,M,mat,S);

	}

	return 0;
}
