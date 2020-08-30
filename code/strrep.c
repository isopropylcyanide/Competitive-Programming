#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *ret;		//must be global if it is to be returned to main

char *firstnon_repeat(char *str)
{
	int i,j,flag,len=0;

	char *x=str;
	while(x[i+1]!='\0')
	{	len++;	i++;	}

	char mark[len];
	for(i=0; i<len; i++)mark[i]='0';

	for(i=0; i<len; i++)
	{

		if (mark[i]=='1')continue;

			flag=0;
			for(j=i+1; j<len ; j++)
			{
				if (mark[j]=='1')continue;
				if(str[i]==str[j])
					{
						flag=1;
						mark[j]='1';
					}				
			}
			if(flag==0)
				{   
					ret=(char*)malloc(sizeof(char)*2);
					ret[0]=str[i];
					ret[1]='\0';
					return ret;
				}
	  }
		return "NONE";
}

int main()
{
	FILE *fp=fopen("input_for_strrep","r");
	if (fp==NULL)
		{ perror("Coudln't open file"); return -1; }
	
	char str[100],*res;

	while(fgets(str,100,fp)!=NULL)
	{
		res=firstnon_repeat(str);
		printf("\nAnswer for is: %s",res);
	}
		

	printf("\n");
	return 0;
}