
mod = 1000000007


def solve(s):
    stack = []
    for i in s:
        # print 'for i: ', i,
        if i == '*':
            if stack == []:
                return -1
            else:
                topVal, topPow = stack[-1]
                if not topVal == '*':
                    # top is a number
                    # check if power is set, if yes, then do the honours
                    if topPow:
                        stack.pop()
                        stack.pop()  # for mult
                        base, basePow = stack[-1]
                        stack.pop()
                        if base == '*':
                            return -1
                        stack.append([pow(base, topVal, mod), basePow])
                    stack.append(['*', False])
                elif not topPow:
                    stack.pop()
                    stack.append(['*', True])
                else:
                    return -1
        else:
            # is a number
            if stack == []:
                stack.append([int(i), False])
            else:
                topVal, topPow = stack[-1]
                if topVal != '*':
                    # top is a number
                    stack.pop()
                    stack.append([topVal * 10 + int(i), topPow])
                else:
                    # top is a *, may be power may be not
                    stack.append([int(i), topPow])
        # print stack
    if not stack:
        return 0

    while stack:
        topVal, topPow = stack[-1]
        stack.pop()
        if topVal == '*':
            return -1
        else:
            if len(stack) == 0:
                return topVal % mod
            # top is a number
            # now check if it has power set
            stack.pop()  # for mult
            if len(stack) == 0:
                return -1
            base, basePow = stack[-1]
            stack.pop()
            if base == '*':
                return -1
            elif topPow:
                stack.append([pow(base, topVal, mod), basePow])
            else:
                stack.append([(base * topVal) % mod, basePow])
        # print 'L: ', stack


if __name__ == '__main__':
    for _ in xrange(input()):
        s = raw_input()
        n = len(s)
        val = solve(s)
        if val == -1:
            print 'Syntax Error'
        else:
            print int(val)
