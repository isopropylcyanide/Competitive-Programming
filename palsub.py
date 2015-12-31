import sys

def is_palin(s):
	return s==s[::-1]

def main():
	for _ in xrange(input()):
		n=input()
		string=raw_input()

		P=[[False]*n]*n
		C=[0]*n

		for i in xrange(n-1):
			for j in xrange(i+1,n):
				if is_palin(string[i:j+1]):
					P[i][j]=True

		for i in xrange(n):
			for j in xrange(n):
				print string[i:j+1],P[i][j],
			print


		for i in xrange(n):
			if P[0][i]==True:
				C[i]=0

			else:
				C[i]=10
				for j in xrange(i):
					if P[j+1][i] == True and C[j]+1<C[i]:
						C[i] = C[j] + 1

		print C[n-1]	

if __name__ == '__main__':
	main()
