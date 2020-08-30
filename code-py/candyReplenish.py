

if __name__ == '__main__':
    n, t = map(int, raw_input().split())
    c = map(int, raw_input().split())
    added = 0
    bowl = n

    for i in xrange(t):
        removal = c[i]
        bowl -= removal
        if i == t - 1:
            break
        else:
            if bowl < 5:
                added += n - bowl
                bowl += n - bowl
            else:
                pass
        print 't = ', i, bowl, added, removal
    print added
