import collections

n,q=[int(i) for i in raw_input().split()]
lis=map(int,raw_input().split())

while q:
	L,R=[int(i)-1 for i in raw_input().split()]
	t=lis[L:R+1]
	count=0
	
	for i in xrange(1,len(t)-4+1):
		for j in xrange(i+1,len(t)-3+1):
			for k in xrange(j+1,len(t)-2+1):	
				if t[L]>t[i]<t[j]>t[k]<t[R]:
					count+=1
	q-=1
	print count

	
