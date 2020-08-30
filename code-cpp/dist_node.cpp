#include<iostream>			//minimum distance between two tree nodes
#include "InfInt.h"

using namespace std;
int t;

int main()
{
  cin>>t;
  
  
  while(t<=20000 && t--)
  {
    InfInt a,b,d1=0,d2=0,dl=0,dist=0;
    dist=0;
    cin>>a>>b;
     
    InfInt c=a; 
    InfInt d=b;
    
    if(a==b) dist=0;
    else 
    	{
    	  while(c!=1)	//dist ROOT-A
  	 {
  	  c/=2;
  	  d1++;
  	  }
  	   while(d!=1)	//dist ROOT-B
  	 {
  	  d/=2;
  	  d2++;
  	  }
  	  while(a!=b && a!=1)	//gives LCA
  	 {
  	  if(a==(b*2) || b==(a*2))	       break;
  	  else if (a==(b*2 +1) || b==(a*2 +1)) break;
  	  a/=2;
  	  b/=2;
  	  } 
  	 
  	  while(a!=1) 			//dist ROOT-LCA
  	 {
  	  a/=2;
  	  dl++;
  	  }
  	  
  	}
   dist=d1+d2-(dl*2);
   cout<<dist<<endl;
  } 
 return 0;
} 



