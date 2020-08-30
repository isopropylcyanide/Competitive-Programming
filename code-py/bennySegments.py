def merge(times):
    saved = list(times[0])
    for st, en in sorted([sorted(t) for t in times]):
        if st <= saved[1]:
            saved[1] = max(saved[1], en)
        else:
            yield saved[1] - saved[0]
            saved[0] = st
            saved[1] = en
    yield saved[1] - saved[0]

if __name__ == '__main__':
    from itertools import combinations as ce
    for _ in xrange(input()):
        N, L = map(int, raw_input().split())
        roads = []
        for _ in xrange(N):
            a, b = map(int, raw_input().split())
            roads.append((a, b))

        found = False

        for i in xrange(1, N + 1):
            for subRoad in ce(roads, i):
                if i == 1:
                    # subroad must be a single interval
                    if subRoad[0][1] - subRoad[0][0] == L:
                        found = True
                        break

                for roadLength in merge(subRoad):
                    if roadLength == L:
                        found = True
                        break
                if found:
                    break

            if found:
                break

        if not found:
            print 'No'
        else:
            print 'Yes'
