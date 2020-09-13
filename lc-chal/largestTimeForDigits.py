from itertools import permutations
import re


class Solution(object):
    pattern_1 = re.compile('[0-1][0-9][0-5][0-9]')
    pattern_2 = re.compile('2[0-3][0-5][0-9]')

    def isInfeasible(self, arr):
        # If smallest value is > 2, no answer
        if min(arr) > 2:
            return True
        return False

    def largestTimeFromDigits(self, arr):
        # Need to fix positions of each character
        # Find if there's a 0, 1, 2
        if self.isInfeasible(arr):
            return ''

        perm = [i for i in permutations(arr, 4)
                if self.isCombinationValid(i)]

        if len(perm) == 0:
            return ''
        maxTimePerm = max(perm, key=lambda x: self.minuteValue(x))
        return '{0}{1}:{2}{3}'.format(maxTimePerm[0], maxTimePerm[1], maxTimePerm[2], maxTimePerm[3])

    def minuteValue(self, arr):
        return ((arr[0] * 10 + arr[1]) * 60) + arr[2] * 10 + arr[3]

    def isCombinationValid(self, arr):
        string = ''.join([str(i) for i in arr])
        return self.pattern_1.match(string) is not None or self.pattern_2.match(string) is not None


if __name__ == "__main__":
    s = Solution()
    print (s.largestTimeFromDigits([0, 0, 1, 0]))
    print (s.largestTimeFromDigits([1, 2, 3, 4]))
    print (s.largestTimeFromDigits([5, 5, 5, 5]))
    print (s.largestTimeFromDigits([2, 1, 9, 9]))
    print (s.largestTimeFromDigits([4, 2, 4, 4]))
