import sys

a=int(raw_input())		#determine which player wins and by how much
lis=[]
a1,a2=0,0
while a:
	b,c= map(int,sys.stdin.readline().split())
	a1+=b
	a2+=c
	lis.append(a1-a2)
	a-=1

if max(lis)>abs(min(lis)):
	print '1 ',max(lis)
else:
	print '2',abs(min(lis))
