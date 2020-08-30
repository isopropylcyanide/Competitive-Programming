from math import degrees, acos, sqrt


def dist(X, Y):
    """Dist from center to X, Y <= 50"""
    return True if pow(X - 50, 2) + pow(Y - 50, 2) <= 2500 else False


def angle(x, y):
    num = y - 50
    if num == 0 and x - 50 == 0:
        return 360
    den = sqrt(pow(x - 50, 2) + pow(y - 50, 2))
    a = degrees(acos(num / den))
    if x < 50:
        return 360 - a
    else:
        return a

if __name__ == '__main__':
    for _ in xrange(input()):
        P, X, Y = map(int, raw_input().split())
        ans = 'white'

        angle_cov = (P * 360.0) / 100
        angle_point = angle(X, Y)
        if angle_point <= angle_cov and dist(X, Y):
            ans = 'black'

        print 'Case #%d: %s' % (_ + 1, ans)
