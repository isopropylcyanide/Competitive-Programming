#include<iostream>		//Print powerset in fastest way
#include<vector>
#include<cmath>

using namespace std;

int main()
{
 int i,n,j;

 cout<<"\nEnter number of elements: "; cin>>n;
 cout<<"Enter elements of set : ";
 vector<int> set; 
 
 for(i=0; i<n; i++){
   cin>>j;
   set.push_back(j);
 }
 int max=pow(2,n),count;

 cout<<"\nThe power set is :\n"; 

 for(i=0; i<max; i++)
 {
   j=i;
   cout<<"{";
   for(count=1; count<=n; count++)
   {
     if(j&1)
	cout<<set[n-count]<<", ";
     j=j>>1;
   }
  cout<<"}"<<endl;
 }
}
