import numpy as np
mod=1000000007

def main():
	for _ in xrange(input()):
		n,m=map(int,raw_input().split())
		lis=map(int,raw_input().split())

		direct_contact=0
		for i in xrange(1,n+1):
			if i not in lis and ( i-1 in lis or i+1 in lis):
				direct_contact+=1
				print 'dc for: ',i

		print direct_contact
		
if __name__ == '__main__':
	main()