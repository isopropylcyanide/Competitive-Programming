import sys

t=int(sys.stdin.readline());
unused_side={0:1,1:0,2:3,3:2,4:3,5:4}

def preprocess(lis):
	x=max(lis.count(i) for i in lis) 
	if x<3:return False
	return True

while t:

	lis=map(str,raw_input().split())
	if preprocess(lis):
			for ix,i in enumerate(lis):
				ans,flag,exception_list=1,0,[unused_side[ix]]
				for jx,j in enumerate(lis):		
					if i==j and ix!=jx and jx not in exception_list:
						ans+=1
						exception_list.append(unused_side[jx])
						if ans>=3:
							flag=1
							break 	
				if flag:break
			if flag:
				print "YES"
			else:print "NO"
	else:print "NO"
	t-=1

