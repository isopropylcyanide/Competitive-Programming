def solve(a, b):
    if len(set(a).intersection(set(b))) > 0:
        print 'Yes'
    else:
        print 'No'

if __name__ == '__main__':
    for _ in xrange(input()):
        solve(raw_input(), raw_input())
