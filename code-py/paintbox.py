import sys

t=int(sys.stdin.readline())

while t:
	list=[]
	n,w=map(int,raw_input().split())
	lis=map(int,raw_input().split())
	q=int(raw_input())
	
	while q:
		pos,col=map(int,raw_input().split())
		lis[pos-1],count,i=col,0,0
		
		for i in xrange(0,len(lis)-1):
			if lis[i]==lis[i+1]:
				count+=1

		print count
		q-=1
	t-=1



	
