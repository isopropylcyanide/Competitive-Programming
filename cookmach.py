import sys,time
from math import log

t=int(sys.stdin.readline())

def get_from(a,b):
	i=0
	while a!=b:
		a=a*2
		i+=1
	return i

def get_back(a,b):
	i=0
	
	while a!=1 and b%a!=0:
		a=a/2
		i+=1
	return i+get_from(a,b)

while t:
	a,b=map(int,raw_input().split())

	if a==b:print 0

	elif b>a:		
		if b/a==0:
			print get_from(a,b)

		else:
			print get_back(a,b)
	else:
		print get_back(a,b)

	t-=1


