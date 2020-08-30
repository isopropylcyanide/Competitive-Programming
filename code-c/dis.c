#include<stdio.h>
#include<string.h>

		//to detect maximum distinguishable distinct sub string ina given string and give its count

  int main()
 {
    printf("HI hi\n");
    int t,i,k; int count=0,flag=0;
     char a[10],b[10];
    
     scanf("%d",&t);
   
   while(t<=10 && t>=1)
 {
    scanf("%s",a);
    strcpy(b,a);
    
    for(i=0; i<strlen(a); i++)
     {
       if(a[i+1]!=a[i])
        {
          for(k=0; k<=i; k++) 
            {
             if(a[i+1]==b[k])
               flag=1;
               
             }  
              if(flag!=1)
             	 count++;   
              else 
                {
                 count=0;
                 flag=0;    
                }
        }
     }
      printf("%d",count);
      count=0; 
    t--;
    
   }
   
 }
