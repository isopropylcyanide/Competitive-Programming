#include<iostream>			//display total holes in the text
#include<cstring>
using namespace std;

int get_hole(char a)
{
  switch(a)
  {
   case 'A': case 'D': case 'O': case 'P': case 'Q': case 'R': return 1; break;
   case 'B': return 2;	break;
   default : return 0;
   }
   
}   
int main()
{
  int t; char s[100];
  cin>>t;
  
  while(t<=40 && t--)
  { 
    int count=0;
    cin>>s;
    for(int i=0; i<strlen(s); i++)
    count+=get_hole(s[i]);
  
    cout<<count<<endl;  
  }
  return 0;
}     
 
