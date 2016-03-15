class Solution:
    # @param A : list of integers
    # @return a list of integers

    def equal(self, A):
        if len(A) < 4:
            return []

        h = {}  # hashmap

        sol, n = [], len(A)
        for a in xrange(n):
            for b in xrange(a + 1, n):
                sumA = A[a] + A[b]
                if sumA not in h:
                    h[sumA] = (a, b)
                else:
                    c, d = h[sumA]
                    if c not in [a, b] and d not in [a, b]:
                        ans = [c, d, a, b]
                        if len(sol) == 0:
                            sol = ans
                        else:
                            repl = False
                            for i in xrange(len(sol)):
                                if sol[i] < ans[i]:
                                    break
                                if sol[i] > ans[i]:
                                    repl = True
                                    break
                            if repl:
                                sol = ans

        return sol

if __name__ == '__main__':
    print Solution().equal(map(int, raw_input().split()))
