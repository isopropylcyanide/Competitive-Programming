import sys
import string

lis=map(str,raw_input().split())
lis=str(lis)
q=int(raw_input())

def cstr(a,b,l,r):
	global lis
	count =0
	for i in xrange(l,r+1):
		for j in xrange(i+1,r+2):
			if lis[i]==a and lis[j]==b:
				count+=1
	return count

while q:
	a,b,l,r=raw_input().split()
	a,b,l,r=str(a),str(b),int(l),int(r)
	print cstr(a,b,l,r)

	q-=1

