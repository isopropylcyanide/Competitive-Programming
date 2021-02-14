def eraseOverlapIntervals(intervals):
    if len(intervals) == 0:
        return 0
    intervals = sorted(intervals, key=lambda x: x[1])
    end, cnt = intervals[0][1], 0
    for s, e in intervals[1:]:
        if s >= end:
            end = e
        else:
            # overlap
            cnt += 1
    return cnt


if __name__ == "__main__":
    # print (merge([[8, 10],  [1, 3], [15, 18],  [2, 6]]))
    # print (merge([[1, 4], [4, 5]]))
    # print (eraseOverlapIntervals([[1, 2], [2, 3], [3, 4], [1, 3]]))
    # print (eraseOverlapIntervals([[1, 2], [1, 2], [1, 2]]))
    print (eraseOverlapIntervals([[1, 2], [2, 3]]))
