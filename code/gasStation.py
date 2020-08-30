class Solution:
    # @param gas : tuple of integers
    # @param cost : tuple of integers
    # @return an integer

    def canCompleteCircuit(self, gas, cost):
        n, first = len(gas), 0
        petrol = 0
        if sum(gas) < sum(cost):
            return -1

        for i in xrange(n):
            petrol += gas[i] - cost[i]
            if petrol < 0:
                first = i + 1
                petrol = 0

        return first

if __name__ == '__main__':
    print Solution().canCompleteCircuit([3, 2, 6, 0], [2, 4, 3, 1])
