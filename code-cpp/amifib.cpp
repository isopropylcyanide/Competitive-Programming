#include<iostream>		//Check if nth terms is arr fibbonaci number
#include<cstring>
using std::cout;
using std::cin;
using std::endl;

long long toInt(char *s)
{
  long long unsigned i,n=0;

  for(i=0;i<strlen(s);i++)
	n=10*n+s[i]-'0';
   
  return n;
}


int main()
{
   int t,i; 
   cin>>t;
   
  while(t){
  
   char inp[1001];
   cin>>inp;
   
   long long unsigned new_inp=toInt(inp),arr[6000];
   arr[0]=1;
   arr[1]=1;
   
    for(i=2;i<6000;i++)
    {
	arr[i]=arr[i-1]+arr[i-2];
	
	if(arr[i]==new_inp){
		cout<<"YES\n";
		break;
	}
	
	if(i==5999)
	cout<<"NO\n";
     }
      t--;
   
   }
   return 0;
  
 }
      



