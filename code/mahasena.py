
if __name__ == '__main__':
    N = input()
    A = map(int, raw_input().split())
    even = sum([1 for i in A if i % 2 == 0])
    odd = N - even
    if even > odd:
        print 'READY FOR BATTLE'
    else:
        print 'NOT READY'
