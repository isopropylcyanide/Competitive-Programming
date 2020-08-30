import numpy as np

def main():
	for _ in xrange(input()):
		n=input()
		lis=map(int,raw_input().split())

		print  len(lis) if (sum(lis) % len(lis) == 0) else len(lis) - 1
if __name__ == '__main__':
	main()