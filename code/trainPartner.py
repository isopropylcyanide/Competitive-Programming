
m = {1: (4, 'LB'),
     2: (5, 'MB'),
     3: (6, 'UB'),
     4: (1, 'LB'),
     5: (2, 'MB'),
     6: (3, 'UB'),
     7: (8, 'SU'),
     8: (7, 'SL')
     }

if __name__ == '__main__':
    for _ in xrange(input()):
        N = input()
        N -= 1
        block, N = N / 8, N % 8 + 1
        part, val = m[N]
        print '%d%s' % (part + 8 * block, val)
