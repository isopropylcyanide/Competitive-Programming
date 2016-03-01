
class Solution:
    # @param A : string
    # @return an integer

    def matches(self, c, s):
        if c == ')':
            return True if s[-1] == '(' else False
        elif c == '}':
            return True if s[-1] == '{' else False
        elif c == ']':
            return True if s[-1] == '[' else False

    def braces(self, A):
        braces = 0
        for char in A:
            if char == '(':
                braces += 1
            elif char in "*/+-":
                braces -= 1
            if braces < 0:
                braces = 0
        if braces == 0:
            return 0
        else:
            return 1


if __name__ == '__main__':
    a = '((a + b))'
    b = '(a + (a + b))'
    print Solution().braces(a)
    print Solution().braces(b)
