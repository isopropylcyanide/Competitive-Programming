def getMSB(number):			#Find max xor with given element
	no_of_bits=0
	while number:
		number=number>>1
		no_of_bits+=1
	
	return no_of_bits

def maxXor(tlis,x):
	maximum=max(tlis)

	if getMSB(x)<getMSB(maximum):
		return x^maximum
	else:
		return x^min(tlis)

import sys				
n=int(sys.stdin.readline())

lis=[]

while n:
	no,x=map(int,raw_input().split())
	lis=map(int,raw_input().split())
	
	print maxXor(lis,x)
	n-=1
