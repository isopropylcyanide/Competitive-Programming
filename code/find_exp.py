from sys import stdin
			#smallest positive integral exponent E such that the decimal expansion of X^E begins with Y
a=int(stdin.readline())
count=0

while a:
	count+=1
	
	X,Y=map(int,raw_input().split())
	e=2
	
	while e:
		lis= map(int,str(X**e))[0:len(str(Y))]
		new_str= ''.join([str(i) for i in lis])
		
		if new_str==str(Y):
			print "Case %d: %d"%(count,e)
			break
		e+=1
	
	a-=1
