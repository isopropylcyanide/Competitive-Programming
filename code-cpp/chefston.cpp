#include<iostream>
#include<vector>

using namespace std;

typedef long long unsigned llu;

llu i,j,n,k,t,temp,maxm,limit;

llu dpmaxm (vector<llu> kind,vector<llu> prof,llu k,llu n)
{
  vector<llu>x(n);

  x[0]=k/kind[0];
  maxm=x[0]*prof[0];

  for(i=1; i<n; i++)
  {
   x[i]=k/kind[i];
   maxm=x[i]*prof[i]>maxm?x[i]*prof[i]:maxm;

  }

   cout<<maxm<<endl;
}

int main()
{

  cin>>t;

  while(t)
  {
    cin>>n>>k;

    vector<llu> kind;
    vector<llu> prof;

    for(i=0; i<n; i++){
    	cin>>temp;
    	kind.push_back(temp);}

     for(i=0; i<n; i++){
    	cin>>temp;
    	prof.push_back(temp);}

    dpmaxm(kind,prof,k,n);

    t--;
  }

 return 0;

 }
