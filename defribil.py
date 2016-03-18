import sys
import math

# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.

lon = float(raw_input().replace(',', '.'))
lat = float(raw_input().replace(',', '.'))
n = int(raw_input())


def calcDist(lon, lat, dlat, dlon):
    map(lambda x: math.radians(x), [lon, lat, dlat, dlon])
    x = (dlon - lon) * math.cos((lat + dlat) / 2)
    y = dlat - lat
    return pow(x ** 2 + y ** 2, 0.5)

closestDefib = ""
minDist = sys.maxint

for i in xrange(n):
    defib = raw_input().split(';')
    print >> sys.stderr, ' line: ', defib
    name = defib[1]
    dLat = float(defib[-2].replace(',', '.'))
    dLon = float(defib[-1].replace(',', '.'))

    curDist = calcDist(lat, lon, dLat, dLon)
    if curDist < minDist:
        minDist = curDist
        closestDefib = name


# Write an action using print
# To debug: print >> sys.stderr, "Debug messages..."

print closestDefib
