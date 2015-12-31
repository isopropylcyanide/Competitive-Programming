import sys

lis=[]
lis=xrange(1,50);
n=len(lis)
max=2**(n)

for i in xrange(max):
	j=i;
	print '{',
	for count in xrange(n):
		if j&1:
			print lis[n-count-1],',',
		j=j>>1
	print '}'

