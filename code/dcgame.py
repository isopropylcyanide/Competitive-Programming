
N,M=map(int,raw_input().split())
lis=map(int,raw_input().split())
winner=[]

def reverse(start):
	if start=='C':return 'D'
	else:return 'C'

def op_greater(K,lis):
	return sum(i > K for  i in lis)


def op_equal(K,lis):
	return sum(i == K for i in lis)

def op_lesser(K,lis):
	return sum(i < K for  i in lis)

while M:
	op,K,start=raw_input().split()
	instances=0
	K=int(K)

	lis=sorted(lis)
	lis2=[]
	for i in xrange(0,len(lis)):
		maxx=lis[i]
		
		for j in xrange(i,len(lis)):
			if lis[j]>maxx:
				maxx=lis[j]
			lis2.append(maxx)
	
	if op=='<':
		instances=op_lesser(K,lis2)
	elif op=='>':
		instances=op_greater(K,lis2)
	elif op=='=':
		instances=op_equal(K,lis2)

	if instances%2==0:
		winner.append(reverse(start))
	else:
		winner.append(start)

	M-=1

print ''.join(winner)