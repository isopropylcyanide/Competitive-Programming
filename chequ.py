import sys
from collections import Counter

t=int(sys.stdin.readline())

while t:
	n=int(raw_input())
	lis=map(int,raw_input().split())

	lis=[int(i) for i in lis] 
	elem=max(Counter(lis).values())
	
	print n-elem
	t-=1
