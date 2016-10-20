def p(x):
    return x & (x + 1)
 
 
def solve(N):
    L = 0
    while N > 0:
        N = p(N) - 1
        L += 1
    print L
 
if __name__ == '__main__':
    for _ in xrange(input()):
        L1, L2, L3, c = map(str, raw_input().split())
        N = int(L1 + L2 * int(c) + L3, 2)
        solve(N)
 

