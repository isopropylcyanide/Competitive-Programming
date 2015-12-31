import sys

t=int(sys.stdin.readline())
while t:
	x,y,k,n=map(int,raw_input().split())
	flag=0

	while not flag and n:
		p,c=map(int,raw_input().split())
		
		if p>=x-y and c<=k:
			flag=1
			break
		n-=1

	if flag==1:
		print "LuckyChef"
	else:
		print "UnluckyChef"
	t-=1

			
		
