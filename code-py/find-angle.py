import math
# -*- coding: utf-8 -*-

s1=input()
s2=input()
s1,s2=float(s1),float(s2)
lis=range(2)
lis[0]=int(round(math.atan(s1/s2)*180/(math.pi),0))
lis[1]='°'
print ''.join([str(i) for i in lis])
