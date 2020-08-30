
class Edge:

    def __init__(self, dest, _id):
        self.dest = dest
        self.id = _id

    def __repr__(self):
        return '%d : %d' % (self.dest, self.id)


def createGraph():
    for _ in xrange(m):
        u, v = map(int, raw_input().split())
        if u not in g:
            g[u] = []
        g[u].append(Edge(v, _ + 1))
        if v not in g:
            g[v] = []
        g[v].append(Edge(u, _ + 1))

if __name__ == '__main__':
    g = {}
    n, m = map(int, raw_input().split())
    createGraph()

    for i in g:
        print i, g[i]
