import sys
import math

# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.

n = int(raw_input())  # Number of elements which make up the association table.
q = int(raw_input())  # Number Q of file names to be analyzed.
h = {}

for i in xrange(n):
    # ext: file extension
    # mt: MIME type.
    ext, mt = raw_input().split()
    # print >> sys.stderr, '\next: ', ext
    # print >> sys.stderr, 'mt: ', mt
    h[ext.lower()] = mt


for i in xrange(q):
    fname = raw_input()  # One file name per line.
    ext = fname.split('.')[-1].lower()
    print >> sys.stderr, '\next: ', ext

    if ext in h and '.' in fname:
        print h[ext]
    else:
        print 'UNKNOWN'

# Write an action using print
# To debug: print >> sys.stderr, "Debug messages..."

# For each of the Q filenames, display on a line the corresponding MIME
# type. If there is no corresponding type, then display UNKNOWN.
