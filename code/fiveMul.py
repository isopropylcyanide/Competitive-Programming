from collections import deque


def numPossibilities(s):
    i, n = 0, len(s)
    q = deque()
    q.append(('', 0))
    counter = 0

    while True:
        # get from where the next sequence of chars will be read
        e, i = q.popleft()
        if i >= n:
            break
        # print '\n\n Got e: %s and start at %d' % (e, i)

        if s[i] == '(':
            end = i + 1
            while end < n and s[end] != ')':
                end += 1
                # Assumption: end will always exist
            # print '\n\t For ( at %d , found end: %d ' % (i, end)
            for char in xrange(i + 1, end):
                # print '\t\tAppending : ', e + s[char]
                q.append((e + s[char], end + 1))
                if e + s[char] in A:
                    counter += 1

        else:
            while i < n and s[i] != '(':
                # Continuous char dfa until )
                e += s[i]
                i += 1
            q.append((e, i))
            if e in A:
                counter += 1

    return counter

if __name__ == '__main__':
    L, D, N = map(int, raw_input().split())
    A = set()
    for _ in xrange(D):
        A.add(raw_input())

    for _ in xrange(N):
        s = raw_input()
        print numPossibilities(s)
