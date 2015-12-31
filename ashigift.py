import sys

t=int(sys.stdin.readline())

while t:

	x=int(raw_input())
	lis=map(int,raw_input().split())
	tri=map(int,raw_input().split())
	tri=list(tri)
	
	lis,b,count,l=list(lis),lis[0],0,len(lis)-1
	
	if tri[0]==0:
		lis=lis[1:]
		for index,l in enumerate(lis):
			if index%2!=0: count+=l 
				
		print count+1
	
	else:
		n1,n2=len(lis),len(tri)
		people,offset=0,1

		while b:
			if people<tri[2*offset]:
				people=tri[2*offset]

			people+=tri[3*offset]
			if people<=lis[2*offset]:
				people=lis[2*offset]+1
			
			if b-1==0:
				break
			people-=lis[2*offset]
			b-=1
			offset+=1

		print people
	t-=1




















	
