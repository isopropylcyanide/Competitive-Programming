import sys

t=int(sys.stdin.readline())

while t:
	n=int(raw_input())
	lis=map(int,raw_input().split())
	count,lis=0,list(lis)
	
	visited=[0 for i in xrange(len(lis))]

	for index,i in enumerate(lis):
		if index+1<len(lis):
			if i!=lis[index+1]:			
				visited[index],visited[index+1]=1,1
			
	print visited.count(1)
	t-=1

