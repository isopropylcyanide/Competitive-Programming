import sys

t=int(sys.stdin.readline())

while t:
	dic,lis={},[]
	m,k,n=map(int,raw_input().split())
	while k:
		a,b=map(int,raw_input().split())
		dic[a]=b
		k-=1
	l1=zip(dic.keys(),dic.values())
	lis=map(int,raw_input().split())
			
	

	t-=1















