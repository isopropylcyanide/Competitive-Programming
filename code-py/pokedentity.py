
# Build a directed graph. In the end do, dfs. The first node whose dfs covers
# all the input, is the answer


def addEdge(G, u, v):
    # Adds a directed edge from u to v
    if u not in G:
        G[u] = set()
    G[u].add(v)


def dfs(node, curNodes, path, G):
    if curNodes == N:
        print path
        return
    if node not in G:
        return
    for neigh in G[node]:
        newPath = path[:] + neigh
        dfs(neigh, curNodes + 1, newPath, G)


def findName(G):
    # Given a directed graph, find first node that covers all inputs
    for i in G:
        dfs(i, 1, i, G)

if __name__ == '__main__':
    N = input()
    G = {}

    for _ in xrange(N):
        A = raw_input().split()
        # Create a directed edge from u to v for u in A
        addEdge(G, A[0], A[1])
        addEdge(G, A[1], A[2])

    findName(G)
