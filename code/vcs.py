import sys
t=int(sys.stdin.readline())

while t:
	n,m,k=[int(i) for i in raw_input().split()]
	A=map(int,raw_input().split())
	B=map(int,raw_input().split())
	
	print len(list(set(A) & set (B))),
	print len(set(xrange(1,n+1))-set(A) & set(xrange(1,n+1))-set(B))

	t-=1
