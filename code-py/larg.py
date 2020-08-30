	
t=int(raw_input())		#compute the largest of the sums of numbers that appear on the paths starting from the top towards the base

for _ in xrange(t):
	n=int(raw_input())
	
	lis=[[0 for _ in xrange(n)] for _ in xrange(n)]

	for i in xrange(n):
		lis[i]=map(int,raw_input().split())

	for i in xrange(n-1,-1,-1):
		for j in xrange(i):
			if lis[i][j]>lis[i][j+1]:
				lis[i-1][j]+=lis[i][j]
			else:
				lis[i-1][j]+=lis[i][j+1]
				
	print lis[0][0]
			
	
	
