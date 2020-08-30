import sys		#sorts number in increasing number

a=int(raw_input())
lis=[]

while a:
	x=sys.stdin.readline()
	lis.append(x)
	a-=1
	
lis.sort()

print ''.join(lis)
