def merge(intervals):
    """
    :type intervals: List[List[int]]
    :rtype: List[List[int]]
    """
    intervals.sort(key=lambda x: (x[0], x[1]))
    print (intervals)
    stack = []
    for interval in intervals:
        curX, curY = interval
        if stack == []:
            stack.append((curX, curY))
        else:
            tosX, tosY = stack[-1]
            # complete overlap of new in prev
            # 4 - 6 & 1 - 7
            if tosX <= curX <= tosY and tosX <= curY <= tosY:
                print 'Complete overlap for {0}-{1} in tos: {2}-{3}'.format(
                    curX, curY, tosX, tosY)
                pass
                # its a complete overlap..do nothing

            # 4 - 8 & 1 - 7
            elif tosX <= curX <= tosY and curY > tosY:
                # partial overlap..remove old one and keep this one
                print 'Partial overlap for {0}-{1} in tos: {2}-{3}'.format(
                    curX, curY, tosX, tosY)
                stack.pop()
                stack.append((tosX, curY))
            else:
                # No overlap
                print 'No overlap for {0}-{1} in tos: {2}-{3}'.format(
                    curX, curY, tosX, tosY)
                stack.append((curX, curY))
            print '\nStack looks like ', stack
    return stack


if __name__ == "__main__":
    # print (merge([[8, 10],  [1, 3], [15, 18],  [2, 6]]))
    # print (merge([[1, 4], [4, 5]]))
    print (merge([[1, 5], [3, 7], [4, 6], [6, 8]]))
