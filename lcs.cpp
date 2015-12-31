#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

char r[10],top=-1;
void push(char x)
{ r[++top]=x; }

char pop()
{ cout<<" "<<r[top--]; }

void lcs(vector<char>a,vector<char>b)
{
  int len=max(a.size(),b.size());
  int V[len+1][len+1];
  
  for(int i=0; i<=len; i++)
    for(int j=0; j<=len;j++)
     V[i][j]=0;

  for(int i=1; i<=len; i++)
    for(int j=1; j<=len; j++)
       V[i][j]=(a[i-1]==b[j-1])? V[i-1][j-1]+1 : max(V[i-1][j],V[i][j-1]);
   
    cout<<"\n\n Length of the common subsquequence is : "<<V[len][len];
    cout<<"\n Preparing the backtracking matrix : \n\n";
  
   for(int i=0; i<=len; i++){
    for(int j=0; j<=len;j++)
	cout<<" "<<V[i][j]; cout<<endl;}

    for(int i=len,j=len; ;)
    {
	if(i==0)break;

      if(V[i][j]!=V[i-1][j])
 	{
	  while(V[i][j-1]==V[i][j])
	   j--;
	  if(V[i-1][j]!=V[i][j]) push(a[i-1]);
	}
	 i-=1;
  }
    cout<<"\n The longest common subsequence is : ";
    while(top!=-1)
    pop();    
    cout<<endl;
}

int main()
{
   int n,i;
   cout<<"\n Length A: "; cin>>n;
   cout<<" Input A: ";
   vector<char>a(n);
 
   for(i=0; i<n; i++)
	cin>>a[i];
  
   cout<<"\n Length B: "; cin>>n;
   cout<<" Input B: ";
   vector<char>b(n);
 
   for(i=0; i<n; i++)
	cin>>b[i];
   lcs(a,b);
   
   cout<<"\n Continue (1/0)?  :";
   cin>>n; 
   if (n==1){system("clear"); main();}
   system("clear");
   
  
} 


































  
