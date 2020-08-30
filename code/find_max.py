from random import randint			#from random array find max and 2nd max

def get_max2(lis):
	x=max(lis)
	ind=0
	for index,i in enumerate(lis):
		if i==x:
			ind=index
	del(lis[ind])
	y=max(lis)
	return x,y

while 1:
	print "Enter the size of list : ",
	n=raw_input();
	a,b=map(int,raw_input("Enter the range of numbers : ").split())
	print

	lis=[]

	for _ in range(int(n)):
		lis.append(randint(a,b))

	print 'Your random list looks like :\n',lis
	print
	a,b=get_max2(lis)
	print 'First Maximum : %d\nSecond Maximum %d\n'%(a,b)


	
