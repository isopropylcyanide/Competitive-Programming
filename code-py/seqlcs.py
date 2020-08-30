import itertools

def LCS(a, b):
    dp = [[0] * (len(b) + 1) for _ in xrange(len(a) + 1)]
    for i, x in enumerate(a, 1):
        for j, y in enumerate(b, 1):
            dp[i][j] = (
                dp[i - 1][j - 1] + 1 if x == y else
                max(dp[i][j - 1], dp[i - 1][j]))
    return dp[-1][-1]

for i in xrange(input()):
	N,K,L=map(int,raw_input().split())
	lis=map(int,raw_input().split())
	side=[i for i in xrange(1,K+1)]

	ans=0
	for i in list(itertools.product(side,repeat=K)):
		if LCS(lis,i)==L:ans+=1
	print ans

	