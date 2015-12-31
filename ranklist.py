import sys

t=int(sys.stdin.readline())

while t:
	n,gsum=map(int,raw_input().split())
	op,tsum=0,n*(n+1)/2
	
	if gsum in [1,tsum]:
		print 0
	elif gsum==n:
		print n-1
	else:
		print abs(tsum-gsum)%n
	t-=1


