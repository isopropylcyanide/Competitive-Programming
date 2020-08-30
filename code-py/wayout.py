import sys
import operator
from math import log

def get_min(hashmap,N,H):
	sum_map=sum(hashmap)
	min_map=min(hashmap)

	if H==1:
		return min_map
	elif H==N:
		return sum_map
	else:
		min_count,starter=sum_map,N-1

		while starter!=H-2:
			total=0
			for i in xrange(starter,starter-H,-1):
				total+=hashmap[i]

			if total<min_count:
				min_count=total
			starter-=1	

	return min_count

t=int(sys.stdin.readline())
while t:

	N,H=map(int,raw_input().split())
	hashmap=[N for i in xrange(N)]
	
	for j in xrange(N):
		yi,yf=map(int,raw_input().split())
		
		for i in xrange(N-1-yf,N-yi):
			hashmap[i]-=1
			
	print get_min(hashmap,N,H)
		
	t-=1

