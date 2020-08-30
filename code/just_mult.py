import sys

t=int(sys.stdin.readline())
m,lis=0,[]

while t:
	m,lis=raw_input().strip().split()
	
	n,m,temp=len(lis),int(m),1
	
	lis=lis.replace('**',' ')
	lis=lis.split('*')
	
	for i in lis:
		no,temp2=map(int,i.split())
		temp*=pow(no,temp2,m)	

	print temp%m
	t-=1
	
			
				
