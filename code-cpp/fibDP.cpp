#include<iostream>		//Find nth terms in fibbonaci using dynamic programming
using namespace std;

void fibDP(long long unsigned n)
{
   long long unsigned arr[n+1];
   arr[0]=arr[1]=1;
   
   for(int i=2; i<=n; i++)
   	for(int j=2; j<i; j++)
   	   arr[j]=arr[j-1]+arr[j-2];	
   
   for(int i=0; i<n; i++)
   	cout<<arr[i]<<" " ;
   	cout<<endl;	
}


int main()
{
   int n,i,j,t; 
   cin>>t;
   
  while(t){
   cin>>n;
   fibDP(n);
   t--;
   }
   return 0;
  
 }
      



