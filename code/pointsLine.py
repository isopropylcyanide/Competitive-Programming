class Solution:
    # @param points, a list of Points
    # @return an integer

    def maxPoints(self, A, B):
        points = zip(A, B)
        if (len(points) <= 2):
            return len(points)
        m = 0  # result value
        for i in range(0, len(points)):
            l = {}  # every time reset the dict
            dup = 1  # count the duplicates
            for j in range(0, len(points)):
                if (points[i][0] == points[j][0] and points[i][1] == points[j][1] and i != j):
                    dup += 1  # count duplicates
                elif i != j:
                    if (points[i][0] == points[j][0]):  # vertical line
                        l['v'] = l.get('v', 0) + 1
                    elif (points[i][1] == points[j][1]):  # horizontal line
                        l['h'] = l.get('h', 0) + 1
                    else:  # regular slope
                        slope = 1.0 * \
                            (points[i][1] - points[j][1]) / \
                            (points[i][0] - points[j][0])
                        l[slope] = l.get(slope, 0) + 1
            if (len(l) > 0):
                m = max(m, max(l.values()) + dup)
            else:  # if all points are duplicates, l is empty.
                m = max(m, dup)
        return m


if __name__ == '__main__':
    A = map(int, raw_input().split())
    B = map(int, raw_input().split())
    print Solution().maxPoints(A, B)
