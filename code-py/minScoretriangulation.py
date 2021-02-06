"""
/*
 * Given Given N, consider a convex N-sided polygon with vertices labelled A[0], A[i], ..., A[N-1] in clockwise order.
 * Suppose you triangulate the polygon into N-2 triangles.  For each triangle, the value of that triangle is the
 * product of the labels of the vertices, and the total score of the triangulation is the sum of these
 * values over all N-2 triangles in the triangulation.
 * 
 * Return the smallest possible total score that you can achieve with some triangulation of the polygon.
 */
"""


def f(A):
    print(A)
    if len(A) == 4:
        f1 = A[0] * A[1] * A[2] + A[2] * A[3] * A[0]
        f2 = A[0] * A[1] * A[3] + A[2] * A[3] * A[1]
        return min(f1, f2)

    if len(A) == 3:
        return A[0] * A[1] * A[2]
        # Base case triangle

    if len(A) < 3:
        return 0
    # return A[0] * A[1] * A[2]
    # Else we have to make a cut
    # We can cut either with the next clock or against the clock
    # We just need to store the offsets properly

    f1 = A[0] * A[1] * A[2] + f(A[2:] + [A[0]])
    f2 = A[0] * A[-1] * A[-2] + f(A[:-1])
    # return f2
    return min(f1, f2)


def minScoreTriangulation(A):
    # Idea is tt=hat whenever you make a cut you have a score for this triangle
    # Plus the score for whatever the polygon is left
    return f(A)


if __name__ == "__main__":
    # print (minScoreTriangulation([3, 7, 4, 5]))
    # print (minScoreTriangulation([1,3, 1, 4, 1, 5]))
    print (minScoreTriangulation([2, 1, 4, 4]))
