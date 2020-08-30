import sys

t=int(sys.stdin.readline())

while t:
	count,lis=0,raw_input()
	lis=list(lis)
	n=len(lis)-1

	for index,i in enumerate(lis):
		
		if i=='-' and index<n:
			if lis[index+1]=='-':
				count+=1
				lis[index+1]='+'
			
		elif i=='+' and index<n:
			if lis[index+1]=='+':
				count+=1
				lis[index+1]='-'
	
	if not n&1:
		if not lis[n]==lis[0]:
			count+=1			
	print str(count)
	t-=1

