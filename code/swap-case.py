
S=map(str,raw_input().strip());
length=len(S)

correct=[0 for i in xrange(length)]
for index,i in enumerate(S):
	if i.isupper():S[index]=i.lower()
	elif i.islower():S[index]=i.upper()
	
print ''.join(S)
