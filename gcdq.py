import sys			#code to find GCD of a list between two numbers
import threading

def gcd(x,y):
	if x<y:
		while x:
			y,x=x,y%x
		return y
	else:
		while y:
			x,y=y,x%y
		return x

def gcd_lis(lis,ans):
    final_ans=lis[0]
     
    for i in xrange(1,len(lis)):
    	final_ans=gcd(final_ans,lis[i])
    
    ans.append(final_ans)
    
    
a=int(sys.stdin.readline())
n,q=0,0
lis=[]

while a:
	
	n,q=map(int,raw_input().split())
	lis=map(int,raw_input().split())
	
	while q:
		l,r=map(int,raw_input().split())
		l-=1
		r-=1		#actual indices
		
		if l>0 and l==r:
			newl=lis[0:l]+lis[l+1:]
			
		elif l==0 and l==r:
			newl=lis[r+1:]
			
		elif l>0 and l!=r:
			newl=lis[0:l]+lis[r+1:]
			
		elif l==0:
			newl=lis[r+1:]
		
		if len(newl)==1:
			print newl[0]
		else:
			l=(len(newl))/2
			ans=[]			
			thread1 = threading.Thread(target=gcd_lis,args=[newl[0:l],ans],)
			thread2 = threading.Thread(target=gcd_lis,args=[newl[l:2*l+1],ans],)
			thread1.start()
			thread2.start()
			
			print gcd(ans[0],ans[1])

		q-=1
	
	a-=1


















		
