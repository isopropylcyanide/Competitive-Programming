import sys

t=int(sys.stdin.readline())

while t:
	L1=list(raw_input().strip())
	L2=list(raw_input().strip())
	assert len(L1)==len(L2)	
	distance=len(L1)	

	if L1[0]=='#'==L2[0] or L1[distance-1]=='#'==L2[distance-1]:
		print 'No'

	else:
		curr_pos,curr_lis,swaps=1,0,0
		L=[L1,L2]
		if L1[0]=='#':curr_lis=1

		while curr_pos!=distance:

			if L[curr_lis][curr_pos]=='#':
				
				if L[(curr_lis+1)%2][curr_pos]=='#':
					print 'No'
					break
				else:	
					curr_lis=(curr_lis +1)%2
					curr_pos+=1
					swaps+=1

			else:curr_pos+=1

		if curr_pos==distance:
			print "Yes"
			print swaps
	t-=1