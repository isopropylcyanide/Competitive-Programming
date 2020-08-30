
N, M = map(int,raw_input().split())

for i in xrange(1,N,2): 
    print "%s%s%s"%('-'*(((N-i)/2)*3),'.|.'*i,('-')*(((N-i)/2)*3))

print "%s%s%s"%('-'*((M-7)/2),"WELCOME",'-'*((M-7)/2))

for i in xrange(N-2,-1,-2): 
    print "%s%s%s"%('-'*(((N-i)/2)*3),'.|.'*i,('-')*(((N-i)/2)*3))

    