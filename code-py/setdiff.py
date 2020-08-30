import sys		#sum of diff in each subset of given set

t=int(sys.stdin.readline())

def expo(a,n,m):
	if n==0:return 1
	x,y,n1=2,1,n/2
	if n&1:y=2

 	while n1>0:
		x=(x**2)%m
		if n1&1:
			if y==1:y= x%m
			else:y=(y*x)%m
		n1/=2
	return y

while t:
	n=int(sys.stdin.readline())
	s=map(int,raw_input().split())
	
	ans,mod=0,10**9 +7
	s=sorted(s)

	for i in xrange(n-1):
		for j in xrange(i+1,n):
			ans+=((s[j]-s[i])*expo(2,j-i-1,mod))%mod
	print ans%mod 
	t-=1

