import sys

t=int(sys.stdin.readline())

while t:
	n,k,l=map(int,raw_input().split())
	maxrot=n*k
	l=l%maxrot
	count,j=0,0

	lis=[1 for i in xrange(n)]
	
	if l in xrange(maxrot/4 +1,maxrot/2 +1):
		for i in xrange	(n-1,n):
			lis[i]=k		
		print 'init: ',lis
		l=l%maxrot/4
		while count!=l:
			print 'count',count,' j ',j, ' l ',l
			lis[n-2]=j+1
			count+=1
			j+=1

	print lis	

	t-=1
	











	
