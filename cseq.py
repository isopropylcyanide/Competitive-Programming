import sys	#multipl
import math

t=int(sys.stdin.readline())

def pow(a,b,mod):
	i,j=1,a
	while b:
		if b%2==1:
			i*=j
			if i>mod:i%=mod
		j*=j
		if j>mod:j%=mod
		b/=2
	return i

def inverse(a,m):
	return pow(a,m-2,m)

def comb(n,r):
    if n-r<=r:
	r=n-r
    pro=1
    for i in xrange(1,r+1):
	pro=(pro*(n-i+1))*inverse(i,1000003)
    return pro

while t:
	n,l,r=map(int,raw_input().split())
	count=0
	c_term=r-l
	if l==r:
		count=n
	else:
		for i in xrange(1,n+1):
			count+=comb(i+c_term,i)

	print count%(1000003)
	t-=1

