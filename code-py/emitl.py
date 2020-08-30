from collections import Counter

"""
Is it possible to reorder the characters in this string to get a string with prefix "LTIME" and suffix "EMITL
"""

def main():
	for _ in xrange(input()):
		s=raw_input()
		S=dict(Counter(s))

		try:
			if S['L']>=2 and S['T']>=2 and S['I']>=2 and S['M']>=2 and S['E']>=2:
				print "YES"
			else:
				if len(s)==9 and S['L']==2 and S['T']==2 and S['I']==2 and S['M']==2 and S['E']==1:
					print "YES"
				else:
					print "NO"

		except KeyError:
			print "NO"


if __name__ == '__main__':
	main()