#include<stdio.h>
					//it is possible to divide his sanskars equally amongst his followers;
int t,n,k,i,j;
  	
  int sub(long long unsigned *sans,int n ,int sum)
  {
    if (sum == 0)
     return 1;
   if (n == 0 && sum != 0)
     return 0;
 
   if (sans[n-1] > sum)
     return sub(sans, n-1, sum);
 
    return sub (sans, n-1, sum) || sub (sans, n-1, sum-sans[n-1]);
  }
  	
  				
  int main()
 {
   scanf("%d",&t);
   
   while(t>=1 && t<=10)
  {
    scanf("%d",&n);
    scanf("%d",&k);
    
    long long unsigned sans[n];
    
    for(i=0; i<n; i++)			//get the sanskar
    scanf("%llu",&sans[i]);
    
   if(n>=1 && n<=21 && (k>=1 && k<=8))
    {
      long long unsigned sum=0;
     
      for(i=0; i<n; i++)
      sum+=sans[i];
    
       long long unsigned maximum = sans[0];
 
	  for (i = 1; i <n; i++)
 	 {
  	  if (sans[i] > maximum)
      	    maximum = sans[i];
  	}
    
      if(sum%2!=0) 
      {
       printf("no\n");
       break;
      }
      
      else
      {
         long long unsigned temp=sum/k;
         if(temp<maximum)
          {
     	  printf("no\n");
    	  return 0;
    	  }  
         if(sub(sans,n,temp))
         printf("yes\n");
         else printf("no\n");
         sum=0; 
     }
    
    }
    
    t--; 
  }  
  
  return 0;
 }  
  
