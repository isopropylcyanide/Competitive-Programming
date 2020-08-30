
def x(n):

	ans = 0
	for i in xrange(1,n+1):
		if i&1:
			ans+= (i+1)/2
		else:
			ans+= (i+2)/2

	return ans

t = input()
print x(t)