#include<stdio.h>			
#define mod 1000000009


int main()
 {
   int a,b,c,count=0;
   
    scanf("%d %d",&a,&b);
    
    while(a--)
    {
     scanf("%d",&c);
     if(c%b==0) count++;
    } 
   
   printf("%d\n",count); 
   return 0;
 }  
