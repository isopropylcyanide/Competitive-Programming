import sys

t=int(sys.stdin.readline())
while t:
	n=int(sys.stdin.readline())
	count=0
	for i in xrange(1,int(n**0.5) +1):
		if n%i==0:
			if (n/i)==i:
				count+=i
			else:
				count+=i+(n/i)
	print count
	t-=1

