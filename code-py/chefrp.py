import sys		#max number of times to pick items from the box in the worst case to get at least two units of each type of ingredient.

t=int(sys.stdin.readline())

while t:
	n=int(sys.stdin.readline())
	qty,c=map(int,raw_input().split()),0
	
	if 1 in qty:
		print '-1'
	
	elif n==1 and qty[0]>=2:
		print '2'

	else:
		temp=0
		sum1=sum(qty)
		for i in xrange(len(qty)):
			temp=max(temp,2+sum1-qty[i])	
		print temp
	t-=1
