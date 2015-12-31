#include<iostream>		//To find the length of the longest non decreasing sequence
#include<vector>
 using namespace std;

void print(vector<int>S,int n)
{
 for(int i=0; i<n; i++)
   cout<<S[i]<<" ";
}

int main()
{
  int n;

  cin>>n; 
  int V[n]; vector<int>S(n,1);
 
  for(int i=0; i<n; i++) cin>>V[i];
  
  for(int i=0; i<n; i++)
   {
     int j=i-1;
     if (V[j]<V[i])
	S[i]=S[j]+1;
     else
	S[i]=S[j];
   }
  cout<<*(S.end()-1)<<endl;
  print(S,n);

 return 0;
}
