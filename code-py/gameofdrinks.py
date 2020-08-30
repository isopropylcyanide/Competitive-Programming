from math import sqrt,ceil

def odd_divisors(a):
	fact_lis=[(i,a/i) for i in xrange(1,int(ceil(sqrt(a)))+1) if a%i ==0]
	my_fact=set()
	for i,j in fact_lis:
		if i%2!=0:my_fact.add(i)
		if j%2!=0:my_fact.add(j)

	print my_fact
	return len(my_fact)

def main():
	for _ in xrange(input()):
		wine_in_first = input()

		if wine_in_first==1:
			print 'Jaime Won'
			continue

		on_table = [wine_in_first]
		ways=odd_divisors(wine_in_first)-1
		
		if ways==0:
			print 'Jaime Won'

		else:
			print 'Tyrion Won'
			print ways+1



if __name__ == '__main__':
	main()