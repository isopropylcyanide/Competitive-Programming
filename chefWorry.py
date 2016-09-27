from collections import defaultdict as dd
from copy import deepcopy
# find if there exists a bridge in the graph whose destruction
# leads to two completely connected components


class graph:

    def __init__(self, n):
        self.numNodes = n
        self.adj = dd(set)

    def bridgeUtil(self, u, V, disc, low, par, ans, time):
        # Utility method for bridge finding
        time += 1
        V[u] = True
        disc[u] = low[u] = time

        for i in self.adj[u]:
            if not V[i]:
                par[i] = u
                self.bridgeUtil(i, V, disc, low, par, ans, time)
                low[u] = min(low[u], low[i])
                if low[i] > disc[u]:
                    ans.append([u, i])
            elif i != par[u]:
                low[u] = min(low[u], disc[i])

    def bridge(self):
        # Return the bridges in the graph
        n = self.numNodes + 1
        V = [False] * n
        disc = [0] * n
        low = [0] * n
        par = [-1] * n
        ans = []

        time = 0
        for i in self.adj:
            if not V[i]:
                self.bridgeUtil(i, V, disc, low, par, ans, time)
        return ans


def isCompleteGraph(graph):
    # Check if a graph is complete
    nodes = len(graph)
    # Check if each node is connected to n -1
    for i in graph.itervalues():
        if len(i) != nodes - 1:
            return False
    return True


def splitGraph(G):
    def dfs(comp, i, v, h):
        if v[i]:
            return
        comp.append(i)
        v[i] = 1
        for u in h[i]:
            if not v[u]:
                dfs(comp, u, v, h)

    for bridge in G.bridge():
        # Remove this bridge and create two graphs
        u, v = bridge[0], bridge[1]

        nG = deepcopy(G.adj)
        nG[u].remove(v)
        nG[v].remove(u)

        left = {k: v for k, v in G.adj.iteritems()}
        right = {}

        # Now right has to be disjoint
        # All nodes in dfs of v are in right
        visited = [0] * (G.numNodes + 1)
        comp = []
        dfs(comp, v, visited, nG)

        for i in comp:
            right[i] = nG[i]
            if i in left:
                left.pop(i)
        left[u] = nG[u]

        if isCompleteGraph(left) and isCompleteGraph(right):
            return 'YES'
    return 'NO'

if __name__ == '__main__':
    for _ in xrange(input()):
        n, m = map(int, raw_input().split())
        G = graph(n)

        for __ in xrange(m):
            u, v = map(int, raw_input().split())
            G.adj[u].add(v)
            G.adj[v].add(u)

        if isCompleteGraph(G.adj):
            print 'YES'
        else:
            print splitGraph(G)
