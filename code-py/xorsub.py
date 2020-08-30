a=int(raw_input())

while 1<=a<=10:
	n,k=map(int,raw_input().split())
	
	lis=[]
	lis=map(int,raw_input().split())
				
	counter,tem=0,0
	print lis
	
	temp=[[0 for x in range(n)]for x in range(2**n)]

	for counter in range(2**n):
		for j in range(n):
			if counter & 1<<j:
				tem^=lis[j]^k
				temp[counter].append(tem)
	
	print max(max(temp))
	
	a-=1
