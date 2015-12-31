import sys

tR=int(sys.stdin.readline())

while tR:
	text=raw_input()
	lis=list(text)
	n=int(raw_input())
	
	ans=0
	t,s=lis.count('T')*2,lis.count('S')
	
	play_size=s+t

	if 12*n<play_size+1:
			print 0
	else:
		ans+=12*n -play_size
	
		for i in xrange(s+t+1,12*n +1):	
			temp=play_size
			i+=temp
			while i<=12*n:

				ans+=1
				i+=temp
		print ans	

	tR-=1
	
