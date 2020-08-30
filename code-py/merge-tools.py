from collections import OrderedDict

def split(lis,split,N):
	ans,i=[],0
	while i<N-1:
		ans=''.join(OrderedDict.fromkeys(lis[i:i+split]).keys())
		print ans
		i+=split
	return ans

S=map(str,raw_input().strip())
N,K=int(len(S)),input()

if K==1:
	for i in S:print i
else:
	split(S,K,N)