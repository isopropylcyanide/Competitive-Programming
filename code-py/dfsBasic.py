#!/usr/bin/python

"""
You are given a matrix with m rows and n columns of cells, each of which contains either 1 or 0. Two cells are said to be connected if they are adjacent to each other horizontally, vertically, or diagonally. The connected and filled (i.e. cells that contain a 1) cells form a region. There may be several regions in the matrix. Find the number of cells in the largest region in the matrix.
"""


def areAdjacent(n1, s1, n2, s2, lis, visited):
    if n1 in [len(lis), -1] or n2 in [len(lis), -1] or s1 in [len(lis[0]), -1] or s2 in [len(lis[0]), -1]:
        return 0
    else:
        return 1 if lis[n1][s1] == lis[n2][s2] == 1 and not visited[n2][s2] else 0


def dfs(node, start, lis, visited, cur):
    # The element [node][start] is part of a chain.
    part_of_bigger[node][start] = True

    if visited[node][start] == True:
        return cur

    # if this cell is 1, then we can check other constraints
    elif lis[node][start] == 1:
        visited[node][start] = True

        # Recur right
        if areAdjacent(node, start, node, start + 1, lis, visited):
            cur = 1 + dfs(node, start + 1, lis, visited, cur)

        # Recur left
        if areAdjacent(node, start, node, start - 1, lis, visited):
            cur = 1 + dfs(node, start - 1, lis, visited, cur)

        # Recur down
        if areAdjacent(node, start, node + 1, start, lis, visited):
            cur = 1 + dfs(node + 1, start, lis, visited, cur)

        # Recur up
        if areAdjacent(node, start, node - 1, start, lis, visited):
            cur = 1 + dfs(node - 1, start, lis, visited, cur)

        # Recur diag down right
        if areAdjacent(node, start, node + 1, start + 1, lis, visited):
            cur = 1 + dfs(node + 1, start + 1, lis, visited, cur)

        # Recur diag down left
        if areAdjacent(node, start, node + 1, start - 1, lis, visited):
            cur = 1 + dfs(node + 1, start - 1, lis, visited, cur)

        # Recur diag up right
        if areAdjacent(node, start, node - 1, start + 1, lis, visited):
            cur = 1 + dfs(node - 1, start + 1, lis, visited, cur)

        # Recur diag up left
        if areAdjacent(node, start, node - 1, start - 1, lis, visited):
            cur = 1 + dfs(node - 1, start - 1, lis, visited, cur)

        return cur

    else:
        visited[node][start] = True
        return cur


def largest_connected_comp_length(m, n, lis):
    max_connected = 0

    for i in xrange(m):
        for j in xrange(n):
            # Avoid unnecessary computations.
            if not part_of_bigger[i][j]:
                connected = dfs(
                    i, j, lis, [[False for k in xrange(n)] for l in xrange(m)], 0)
                if max_connected < connected:
                    max_connected = connected

    return max_connected


if __name__ == '__main__':
    m = input()
    n = input()
    lis = []
    connected = 0
    for i in xrange(m):
        lis.append(map(int, raw_input().split()))

    # Used to control the recursion. If an element is part of a chain once
    # store this in a table, so we don't recur for that element again
    part_of_bigger = [[False for i in xrange(n)] for j in xrange(m)]
    print largest_connected_comp_length(m, n, lis) + 1

