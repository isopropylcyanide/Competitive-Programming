import sys			#minimum bombs to explode given points

t=int(sys.stdin.readline())
a,b,n,flag=0,0,0,0

while t:
	n=int(raw_input())
	
	x_l=[]
	y_l=[]
	for _ in xrange(n):
		a,b=map(int,raw_input().split())
		x_l.append(a)
		y_l.append(b)
	
	incl=[0 for i in  xrange(n)]
	prange=[0 for i in xrange(n)]

	lis= sorted(zip(x_l,y_l))
	x_l=(zip(*lis))[0]
	y_l=(zip(*lis))[1]
	bombs=0

	for index  in xrange(len(x_l)):
		if incl[index]==0:						#true for first_pair for sure

			if index==n-1:						#check if its the end of the list
				break							#we are done
			
			else:
				if y_l[index]>=x_l[index+1]:				#if overlaps the next pair:
					incl[index],incl[index+1]=1,1			#mark the newly formed unit
					prange[index+1]=min(y_l[index],y_l[index+1])	#store minimum range in next pair for further inclusions
				else:
					incl[index],incl[index+1]=0,0			#we require one bomb for the pair as it is isolated
		
		elif incl[index]==1:							#if already marked before by some action
			
			if index==n-1:
				bombs+=1						#last group has to be isolated						
				break
							

			else:
				if prange[index]>=x_l[index+1]:				#check if can accomodate in the same group
					incl[index],incl[index+1]=1,1			#mark the newly formed unit of three
					prange[index+1]=min(prange[index],y_l[index+1])	#for further accomodation bomb has to be the min

				elif prange[index]<x_l[index+1]:
					
					incl[index+1]=0					#we can't include it as of now
					bombs+=1					#one bomb for the isolated unit
					
	for i in xrange(len(incl)):							#no. of bombs = unincluded indexed + earlier
		if incl[i]==0:						
			bombs+=1

	print bombs	

	t-=1











	
