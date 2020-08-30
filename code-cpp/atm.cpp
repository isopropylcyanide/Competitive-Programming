#include<iostream>
 using namespace std;
#define endl "\n" 
 
 int main()
 {
   int req; float bal;
   cout.setf(ios::fixed,ios::floatfield);
   cout.precision(2);
   cin>>req>>bal;
   
   if(req%5!=0) cout<<bal<<endl;
   
   else if(req>bal) cout<<bal<<endl;
   else
    {
      bal-=req+0.5;
      cout<<bal<<endl;
    }
 }     
