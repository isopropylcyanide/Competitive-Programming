
""" Samu is initially standing at (1, 1). Also she is having a deck of K
cards. Cards have a number written on top and a number written on bottom too.
These numbers tell the direction to move. It means if she is currently at some
coordinate (X, Y) and value on top of card is A and on bottom of the card is B
then she jumps to (X+A, Y+B).

Game is played with following rules : 1. She looks all cards in the order from
1 to K and consecutively chooses each card as the current one. 2. After she
had chosen a current card , she makes the maximally possible number of valid
jumps with the chosen card.

She had been jumping for so long that she completely forgot how many jumps she
had made. Help her count how many jumps she had made. """

def main():
	for _ in xrange(input()):
		N,M = map(int,raw_input().split())

		lis=[]
		for _ in xrange(input()):
			a,b = map(int,raw_input().split())
			lis.append((a,b))

		my_x,my_y=1,1
		total_jumps=0

		for a,b in lis:
			while 1<=a+my_x<=N and 1<=b+my_y<=M:
				total_jumps+=1
				my_x+=a
				my_y+=b

		print total_jumps

if __name__ == '__main__':     main()
