#include<stdio.h>				//how many of these subsequences are balanced.
#include<math.h>
#define mod 1000000009

int n,k,i,j,m,total_balance=0,flag;
long signed set[100];
				
 int checkbal(long signed temp[][n],int index)		
   {
     int ret=0,c;					
  
  for(j=0; j<n-1; j++)
  
   if(temp[index][j]==0 && temp[index][j+1]==0 ) 
       flag=1;						//empty subset is balanced	
   	else 
   	{
   	  flag=0; 
   	  break;
   	 }
   	
   	if(flag==1) {flag=0; return 1;}			
      
        else					
         { 
      	   for(j=0; j<n; j++) 
	       if(temp[index][j]<0)
	          if(temp[index][j+1]==-temp[index][j])
	          ret+=1;
	 }
     return ret;			 
   }			 
			
			
  int main()
 {
   scanf("%d",&n);
   
   if(n>=1 && n<=100)
  {
    for(i=0; i<n; i++)
    scanf("%ld",&set[i]);
    						//divide each subset of powersets into arrays
    unsigned int pow_set_size=pow(2,n);
    unsigned long int counter;
 
    long signed temp[pow_set_size][n];
 
    for(i=0; i<pow_set_size; i++)
    for(j=0; j<n; j++)
    temp[i][j]=0;
    
    for(counter = 0; counter < pow_set_size; counter++)
     {
       m=0;
       
      for(j=0; j<n; j++)
       { 
        if(counter & (1<<j))
         temp[counter][m++]=set[j];		//trap: i was using == here      
       }
     } 
      						//check balance for each power set stored as an array
    for(i=0; i<pow_set_size; i++)
     total_balance+=checkbal(temp,i);
    
    printf("%d\n",total_balance%mod);
    
   }
   
  return 0;
  
 }   
