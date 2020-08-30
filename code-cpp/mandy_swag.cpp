#include <bits/stdc++.h>
using namespace std;

typedef long long int llu;

int main(){

	llu N,temp;
	vector<llu>lis;

	scanf("%lld",&N);

	for(llu i=0; i<N; i++){
		scanf("%lld",&temp);
		lis.push_back(temp);
	}


	sort(lis.begin(),lis.end());

	llu all_min=LONG_MAX;
	llu max_pro=1;

	for(llu i=0; i<N-1; i++){

		if (lis[i+1] -lis[i] <= all_min){
			max_pro = lis [i+1] * lis[i];
			all_min = lis[i+1] - lis[i];
		}
	}

	printf("%lld\n",max_pro );
	return 0;
}