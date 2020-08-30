
def isPower(n):
	return n != 0 and ((n & (n - 1)) == 0)

for i in xrange(input()):
	N=input()
	
	if N==1:print 2

	elif isPower(N+1):
		print N>>1
	else:
		print -1		
	