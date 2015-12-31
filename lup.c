#include<stdio.h>
#include<string.h>
#include<malloc.h>

 int t,i,j,k,lb,count,flag=0; 
			
			//to delete exactly one char and then determine if palindrome or not

  void rev(char b[])
  {
    
    char temp[100];
    for(i=strlen(b)-1,j=0; i+1!=0; --i,++j)
    {
        temp[j]=b[i];
    }
    temp[j]='\0';
    strcpy(b,temp);
   
  }
 
 void refresh(char temp[])
  {
    
    for(i=0; i<strlen(temp); i++)
    temp[i]=0;
    
    }

  int main()
 {
   char a[10];
     
     
     scanf("%d",&t);
   
   while(t>=1)
  {
	scanf("%10s",a);
	
        char *temp=malloc(strlen(a)-1);
        refresh(temp);
   
       while(strlen(a)>2 && strlen(a)<100000)
       {
       
       	  for(count=0; count<strlen(a); count++)
              {
               for(k=0,lb=0; k<strlen(a); k++) 
                {
                  if(k!=count )
                 	temp[lb++]=a[k];
	        } 
	   
                 char ttr[strlen(temp)];
                 strcpy(ttr,temp);
                 
                 rev(temp);
                 
                 if(strcmp(ttr,temp)==0) 
                  flag=1; 
                  
            	  refresh(temp);
		}
	     break;
	  }  
	  
	  if(flag==1) printf("YES\n");
	   else printf("NO\n");
	   flag=0;  
     	t--;
  }
   return 1;
}  





