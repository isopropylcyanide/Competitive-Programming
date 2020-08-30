
def divisors():
    div = [1]
    for (p, r) in fact:
        div = [d * p**e for d in div for e in xrange(r + 1)]
        print p, r, div
    return div


def addEdge(u, v):
    if u not in g:
        g[u] = [v]
    else:
        g[u].append(v)
    if v not in g:
        g[v] = [u]
    else:
        g[v].append(u)


def dfs(i, visited, p):
    if i in visited:
        return
    visited.add(i)
    p.append(i)
    for neigh in g[i]:
        if neigh not in visited:
            dfs(neigh, visited, p)
    return p


def createGraph():
    divs = divisors()
    n = len(divs)
    for i in xrange(n):
        for j in xrange(i + 1, n):
            if (divs[i] % divs[j] == 0 or divs[j] % divs[i] == 0):
                addEdge(divs[i], divs[j])
    return len(divs)

if __name__ == '__main__':
    N = input()
    fact = []
    for _ in xrange(N):
        a, b = map(int, raw_input().split())
        fact.append((a, b))

    # Create a graph where two divisors are connected if they divide
    # Do a dfs from any node
    g = {}
    numDivs = createGraph()
    print g
    path = dfs(1, set(), [])
    if len(path) != numDivs:
        print 'No'
    else:
        for i in path:
            print i,
