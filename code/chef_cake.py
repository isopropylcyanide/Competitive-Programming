from fractions import gcd

"""
Chef arranges the N robots in a row, in the (increasing) order of their indices. Then, he chooses the first M robots and
 moves them to the end of the queue. Now, Chef goes to the robot at the first position in the row and hands it one cake. 
 He then notes this robot's index (say k) in his notebook, and goes to the kth position in the row. If the robot at this 
 position does not have a cake, he give him one cake, notes his index in his notebook, and continues the same process. 
 If a robot visited by Chef already has a cake with it, then he stops moving and the cake assignment process is stopped.
 """

def main():
	for _ in xrange(input()):
		N,M = map(int,raw_input().split())

		if N == 1:
			print 'Yes'

		elif M == 0:
 			print 'No',1

 		elif M == N-1 or M == 1:
 			print 'Yes'

 		else:
 			M = min(M,N-M)

 			if N % M != 0:
 				ans = gcd(N,M)

 				if ans == 1:
 					print 'Yes'
 				else:
 					print 'No',N/ans
 			
 			else:
 				print 'No',N/M


def brute():
	for n in xrange(10):
		# n,m = map(int,raw_input().split())
		m = 3
		l=range(m+1,n+1)+range(1,m+1)
		cake = [0]*n
		over=False
		start=0

		print 'For ',n,m,
		while not over:
			if cake[start]!=1:
				cake[start] = 1
				start = l[start]-1

			else:
				over = True

		ans = cake.count(1)
		if ans == n:
			print 'Yes'
		else:
			print 'No',ans


if __name__ == '__main__':
	main()
	# brute()