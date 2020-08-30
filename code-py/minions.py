
S=map(str,raw_input().strip())
length=len(S)
cons,vow={},{}
Stuart,Kevin=0,0

def isConsonant(s):
	if s.lower() not in ['a','e','i','o','u']:
		return True
	return False

for index,i in enumerate(S):
	if isConsonant(i):Stuart+=length-index
	else:Kevin+=length-index

if Stuart>Kevin:print 'Stuart',Stuart
elif Kevin>Stuart:print 'Kevin',Kevin
else:print 'Draw'

