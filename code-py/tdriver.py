import sys

t=int(sys.stdin.readline())

while t:
	n=int(sys.stdin.readline())
	a,b=map(int,raw_input().split())
	
	v=[[1 for i in xrange(n)] for i in xrange(n)]
	x,y=[],[]
	while n:
		c,d=raw_input().split()
		x.extend(c)
		y.extend(d)
		n-=1

	x=[int(i) for i in x]
	y=[int(i) for i in y]
	maxm=0

	for i in xrange(len(x)):
		for j in xrange(len(x)):
			if i==j:continue

			if v[i][j]==1 and v[j][i]==1:

				maxm+=max(a*abs(x[i]-x[j]), b*abs(y[i]-y[j]))
				v[i][j],v[j][i]=0,0
	print maxm
