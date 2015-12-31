from collections import Counter

"""
Given a prime number X, you need to give the count of all numbers
 in range 1 to 106 inclusive which have minimum prime factor X.
"""
def seq_sieve(n):
	F = [0]*(n + 1)
	i = 2

	while i*i <= n:
		if F[i] == 0:	
			k = i*i

		while k <= n:
			if F[k] == 0:
				F[k] = i;

			k += i
		i += 1

	return F

def main():
	L=Counter(seq_sieve(10**6))
	# print L
	for testcases in xrange(input()):
		print L[input()]+1

if __name__ == '__main__':
	main()