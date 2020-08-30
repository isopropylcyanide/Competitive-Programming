
def main():
	for _ in xrange(input()):
		n=input()
		b=map(int,raw_input().strip().split())

		guard=0
		for i in xrange(n-1):
			if b[i+1]!=1 and b[i]!=1:
				guard+=1
				b[i+1]=1

		print guard


if __name__ == '__main__':
	main()