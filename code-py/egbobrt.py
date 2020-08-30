import sys,math
t=int(sys.stdin.readline())

while t:
	n,k=map(int,raw_input().split())
	min_size,remaining,wt=0,0,map(int,raw_input().split())

	for i in xrange(n):
		for j in xrange(n):
			if j==i:
				if wt[i]>remaining:
					min_size+=int(math.ceil((float(wt[i]-remaining)/k)))
				
					if wt[i]==k:remaining=0
					else:remaining=k-((wt[i]+remaining)%k)-1	
				else:
					remaining-=wt[i]
	print min_size
	t-=1
	
