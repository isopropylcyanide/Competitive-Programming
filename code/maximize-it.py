import itertools

K,M=map(int,raw_input().split())
lists=[]

while K:
	lis=map(int,raw_input().split())
	lis=[ i*i for i in lis[1:] ]
	
	lists.append(lis)
	K-=1

ans=0

for i in list(itertools.product(*lists)):
	temp=sum(i)%M
	if temp>ans:
		ans=temp
print (ans+M)%M