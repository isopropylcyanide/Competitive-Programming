import re

for i in xrange(input()):
	A=raw_input()
	B=raw_input()

	A,B=list(A),list(B)
	for i in xrange(len(B)):
		if B[i]=='?' and A[i]!='?':B[i]=A[i]
		elif B[i]=='?' and A[i]=='?':
			B[i]='z'

	A,B=''.join(A),''.join(B)
	A=A.replace('?','[a-z]+')

	pattern=re.compile(A)
	if pattern.match(B)is not None:print 'Yes'
	else:print 'No'

