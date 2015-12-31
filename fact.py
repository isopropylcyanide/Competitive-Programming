#Generate fast ways to implement reduce functions in Python using HCF and factorial

print reduce(lambda x,y:x*y,xrange(1,int(raw_input("\nFactorial for number : "))+1))

def gcd(a,b):
	while a:
		b,a=a,b%a
	return b

x=map(int,raw_input("Enter numbers for finding HCF :").split())
print reduce(lambda x,y:gcd(x,y) ,x)
