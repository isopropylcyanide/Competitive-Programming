#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll t, n;

ll solveA(vector<ll> A, vector<ll> B){
	vector<bool> V(10005, false);
	pair<ll, ll> M;

	for(ll i = 0; i < n; i ++ ){
		if (M.first < A[i])
			M = make_pair(A[i], i);
	}

	ll ans = -1;

	vector <ll> tM;
	tM.push_back(M.first);
	if(M.second)
		tM.push_back(M.first + B[M.second - 1]);
	if(M.second != n - 1)
		tM.push_back(M.first + B[M.second + 1]);
	tM.push_back(M.first + B[M.second]);

	sort(tM.begin(), tM.end(), greater<ll>());
	ll x;
	for(ll j = 0; j < tM.size(); j ++ ) {
		x = tM[j];
		for (ll z = 0; z < n; z ++ )
			V[z] = false;

		bool fl = true;
		for(ll i = 0; i < n; i ++ ) {
			if(A[i] == x)
				continue;
			else {
				if(i && (x - A[i]) == B[i - 1] && !V[i - 1])
					V[i - 1] = true;

				else if((x - A[i]) == B[i] && !V[i])
					V[i] = true;

				else if(i && ((x - A[i]) == (B[i - 1] + B[i])) && !V[i - 1] && !V[i]){
					V[i - 1] = true;
					V[i] = true;
				}
				else if((i != n - 1) && (x - A[i] == B[i + 1]) && !V[i + 1])
					V[i + 1] = true;

				else if(i && (i != n - 1) && ((x - A[i]) == (B[i - 1] + B[i + 1])) && !V[i - 1] && !V[i + 1]){
					V[i - 1] = true;
					V[i + 1] = true;
				}
				else{
						if(i != n - 1 && x - A[i] == B[i] + B[i + 1] && !V[i + 1] && !V[i]){
							 V[i + 1] = true;
							 V[i] = true;
						 }
						else if(i && i != n - 1 && x - A[i] == B[i] + B[i - 1] + B[i + 1] && !V[i] && !V[i - 1] && !V[i + 1]){
							 V[i - 1] = true;
							 V[i + 1] = true;
							 V[i] = true;
						 }
						else{
							fl = false;
							break;
						}
				}
			}
		}
	  for (ll z = 0; z < n; z++ )
		  if(!V[z]){
			  fl = false;
			  break;
		  }
		  if(fl){
			ans = x;
			break;
		 }
	}
	return ans;

}

ll solveB(vector<ll>a, vector<ll> b){
	ll sum= std::numeric_limits<int>::max();
	int af,bf,i,f,max;
	ll d[100005];
	ll sum1,sum2,rem;
	af=bf=0;
	max=0;
	f=0;
	sum1=sum2=0;
	for(i=0;i<n;i++){
		if(i>0 && b[i]!=b[i-1])
		bf=1;
		sum1+=b[i];
		d[i]=b[i];
	}
	for(i=0;i<n;i++)
	{
		if(a[i]>a[max])
		max=i;
		if(i>0 && a[i]!=a[i-1])
		af=1;
		sum2+=a[i];
	}
    if(af==0 && bf == 0)
    {
    	return (a[0]+b[0]);
    }
    else if(af == 0)
    {
    	return a[0];
    }
    else
    {
    	sum=(sum1+sum2)/n;
    	if((sum1+sum2)%n == 0)
    	{
	    	for(i=0;i<n;i++)
			{
	            rem=sum-a[i];
	    		if(rem>0)
	    		{
		    		if(i==0 && b[i]!=rem && i+1<n && (b[i]+b[i+1])!=rem && b[i+1]!=rem)
		    		{
		    			f=1;
		    			break;
		    		}
		    		else if(i==n-1 && b[i]!=rem && b[i-1]!=rem && (b[i]+b[i-1])!=rem )
		    		{
		    			f=1;
		    			break;
		    		}
		    		else if(b[i]!=rem && b[i-1]!=rem && b[i+1]!=rem && (b[i]+b[i-1])!=rem && (b[i]+b[i+1])!=rem && (b[i]+b[i-1]+b[i+1])!=rem &&(b[i-1]+b[i+1])!=rem)
		    		{
		    			f=1;
		    			break;
		    		}
	    		}
			}
    	}
    	else
    	{
    		f=1;
    	}
		if(f==1)
		{
			f=0;
	    	for(i=0;i<n;i++)
			{
                rem=a[max]-a[i];
	    		if(rem>0)
	    		{
		    		if(i==0 && b[i]!=rem && (b[i]+b[i+1])!=rem && b[i+1]!=rem)
		    		{
		    			f=1;
		    			break;
		    		}
		    		else if(i==n-1 && b[i]!=rem && b[i-1]!=rem && (b[i]+b[i-1])!=rem )
		    		{
		    			f=1;
		    			break;
		    		}
		    		else if(b[i]!=rem && b[i-1]!=rem && b[i+1]!=rem && (b[i]+b[i-1])!=rem && (b[i]+b[i+1])!=rem && (b[i]+b[i-1]+b[i+1])!=rem &&(b[i-1]+b[i+1])!=rem)
		    		{
		    			f=1;
		    			break;
		    		}
	    		}

			}
			if(f==1)
			return -1;
			else
			return a[max];
		}
		else
		{
			return sum;
		}
    }
}

int main() {
	cin >> t;
	while(t--) {
		cin >> n;

		vector<ll> A(n), B(n);
		for(ll i = 0; i < n; i ++ )
			cin >> B[i];

		for(ll i = 0; i < n; i ++ )
			cin >> A[i];

		ll ansA = solveA(A, B);
		ll ansB = solveB(A, B);
		if (n <= 15)
			// All answers for first subtask of ansA are correct
			cout << ansA<< endl;
		else{
			// this is second task
			if (ansA == ansB) //then this is correct ans
				cout << ansA << endl;
			else{
				cout << ansB << endl;
			}
		}

	}
	return 0;
}
