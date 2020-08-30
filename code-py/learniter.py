from itertools import *
name=['A','B']
surname=[1,2]

for i in chain(name,surname):
	print i

for i in izip(name,surname):
	print ''.join(list(str(x) for x in i))
	print i

lis=[range(100)]
for i in islice(count(),10):
	print i,
