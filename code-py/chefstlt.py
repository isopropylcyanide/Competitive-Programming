import sys		
t=int(sys.stdin.readline())

while t:
	S1=raw_input()
	S2=raw_input()
	S1,S2=list(S1),list(S2)

	qpotent,potent,impotent=0,0,0
	
	for i in xrange(len(S1)):
		if S1[i]=='?':
			if S2[i]=='?':qpotent+=1	
			else:impotent+=1

		elif S2[i]=='?':impotent+=1
		elif S1[i]==S2[i]:potent+=1
	
	maxm=len(S1)-(impotent+potent+qpotent)
	minm=len(S1)-potent
	print maxm,minm

	t-=1
