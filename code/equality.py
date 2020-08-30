import sys

t=int(sys.stdin.readline())

while t:
	n=int(sys.stdin.readline())
	lis=map(int,raw_input().split())
	total=sum(lis)/(n-1)

	for index,_ in enumerate(lis):
		print total-lis[index],
	print 
	t-=1

