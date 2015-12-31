#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class myArray{
 public: vector<int> a;
  
  myArray(){}

};


int dpMax(vector<int>a, int sum)
{
 
  vector<int>newA(sum+1,INT_MAX);
  newA[0]=0;
    
  for(int i=1; i<=sum; i++)
  {
    for (int j=0; j<a.size(); j++)
   {  
       if( a[j] == i) newA[i] = 1;
       else if ( i - a[j] >= 0)
          newA[i] = min(newA[i] , newA[ i -a[j]] + 1);
    }
  }
   return newA[sum];
}


int n,temp,t,sum;

int main()
{
  cin>>t;
 
  while(t--){

  cin>>n;
  myArray arr;

  for (int i=0; i<n; i++)			//Get the coin denomination;
   {
     cin>>temp;
     arr.a.push_back(temp);
   }
   						//get the sum to be found  out
   cin>>sum;
   cout<<dpMax(arr.a,sum)<<endl;   

 }
 return 0;
 
}











