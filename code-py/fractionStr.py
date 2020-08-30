class Solution:

    def myfunc():
        pass

    def fractionToDecimal(self, n, d):
        if n == 0:
            return "0"
        if d == 0:
            return ""
        ans = ""
        if(((n < 0) ^ (d < 0)) > 0):
            ans = ans + "-"
        n = abs(n)
        d = abs(d)
        ans = ans + str(n / d)
        r = (n % d) * 10
        if(r == 0):
            return ans
        dic = {}
        ans = ans + "."
        while r != 0:
            if r in dic:
                c = dic[r]
                ans = ans[:c] + "(" + ans[c:len(ans)] + ")"
                return ans
            dic[r] = len(ans)
            t = r / d
            ans = ans + str(t)
            r = (r % d) * 10
        return ans


if __name__ == '__main__':
    print Solution().fractionToDecimal(input(), input())
