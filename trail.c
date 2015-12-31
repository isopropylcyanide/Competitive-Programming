#include<stdio.h>			//display trailling zeroes
#define mod 1000000009

unsigned int find_zero(int x)
{
  int count=0; 
  
  while(x)
  {
   count+=x/5;
   x=x/5;
  }
  return count;
}   

int main()
 {
   unsigned int a,b;
 
   scanf("%d",&a);
   
   while(a--)
   {
     scanf("%d",&b);
     printf("%d\n",find_zero(b));  
   }

  return 0;
 } 
