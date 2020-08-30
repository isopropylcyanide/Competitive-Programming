#include<iostream>			//minimum sum of absolute differences 
#include<cstdlib>
	using namespace std;
	

int ht[100];
int pen[100][2];

int t,i,j,n;


int main()
{
  cin>>t; 
  
  while(t)
  {
    cin>>n; 
    
    for(i=0; i<n; i++)
    	cin>>ht[i];
    
    for(i=0; i<n; i++)
    	cin>>pen[i][0];
    	
     for(i=0; i<n; i++)
    	pen[i][1]=0;
    	
    
    int temp=0,minSum=0,toMark;
    
    for(i=0; i<n; i++)
     {
       //cout<<"For "<<ht[i]<<": "<<endl;
       temp=ht[i];
       
       for(j=0; j<n; j++)
       	{
       	   if(pen[j][1]!=1)
       		if(abs(pen[j][0]-ht[i])<=temp)
       			{
       			 temp=abs(pen[j][0]-ht[i]);
       			 toMark=j;
       			}
       			
       	 // else cout<<pen[j][0]<<" has been marked \n";      
       }	
       pen[toMark][1]=1;
       minSum+=temp;
  	
      }
     cout<<"Case "<<t<<": "<<minSum<<endl;
     t--;
  }
  
  return 0;
 }


void next_comb(int r , int n){
  for(llu r = 1 ; r<n; r++){

    vector<bool> v(n);
    fill(v.begin() + r, v.end() ,true);

    do{
      for(llu i = 0; i<n; i++)
        if (!v[i])
          cout <<i+1<<" ";
      cout<<endl;
    }
    while(next_permutation(v.begin(),v.end()));

  }
}