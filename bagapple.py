import sys

n=int(sys.stdin.readline())
lis=map(int,raw_input().split())
l=sum(lis)

if l%3==0:
    print l
else:
    hash={}
    for i in xrange(n):
        hash[i]=[k for k in lis]
        hash[i].remove(hash[i][i])
        hash[i]=sum(hash[i])

    print max([i for i in hash.values() if i%3==0])