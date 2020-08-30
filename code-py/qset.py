#string queries. 1. replace 2. check for substring divisibilty by 3
import itertools

n,m=map(int,raw_input().split())

lis=map(int,raw_input())

while m:	
	query_no,init,final=map(int,raw_input().split())
	init,final=init-1,final-1
	count=0
	if query_no==1:
		lis[init]=final+1
	
	elif query_no==2:
		count=0
    		r0,r1,r2=0,0,0
    		for i in xrange(init,final+1):
        		r=int(lis[i])%3
        		if r==0:
            			r0+=1
        		elif r==1:
        			r0,r1,r2=r2,r0,r1
           			r1+=1
        		elif r==2:
           		 	r0,r1,r2=r1,r2,r0
            			r2+=1
        		count+=r0
    		print count		
		
	m-=1


