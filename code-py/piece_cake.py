import sys

t=int(sys.stdin.readline())

while t:
	tex=raw_input()
	lis=[i for i in tex]
	n=len(lis)
	if(n%2)==1:
		print "NO"
	else:
		count=0
		for i in xrange(n):
			for k in xrange(n):
				if lis[i]==lis[k]:
					count+=1
			if count==n-count:
				print "YES"
				flag=1
				break
			else:
				count,flag=0,0
		if flag==0:
			print "NO"
	t-=1
