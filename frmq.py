import sys
import math
		
def create_seg(lis,M,node,b,e):
	if b>e:return
	if b==e:
		M[node]=lis[b]
		return M[node]
	else:	
		left=2*node
		right=left+1
		mid=(b+e)/2

		M[node]=max(create_seg(lis,M,left,b,mid),create_seg(lis,M,right,mid+1,e))
		return M[node]

def get_max(node,a,b,M,i,j):	
	if i>b or j<a:return -1
	if a>=i and b<=j:return M[node]
	mid=(a+b)/2
	
	l=2*node
	r=l+1
	left=get_max(l,a,mid,M,i,j)
	right=get_max(r,mid+1,b,M,i,j)

	if left==-1:return right
	if right==-1:return left

	if M[left]<=M[right]:return left
	else:return right
	

n=int(sys.stdin.readline())
lis=map(int,raw_input().split())

m,x1,y1=map(int,raw_input().split())

if n<pow(10,6):
	temp=int(math.ceil(math.log(n,2)))
	M=['-' for i in xrange(1,2*int(math.pow(2,temp)))]

	create_seg(lis,M,1,0,n-1)

	#print M

	if y1<x1:
		ans=get_max(1,0,n-1,M,y1,x1)
	else:
		ans=get_max(1,0,n-1,M,x1,y1)

	for i in xrange(2,m+1):
	
		x1=(x1+7)%(n-1)
		y1=(y1+11)%n
		
		if y1<x1:
			ans+=get_max(1,0,n-1,M,y1,x1)
		
		else:
			ans+=get_max(1,0,n-1,M,x1,y1)	
		#print 'in loop with x1: ',x1,' y1: ',y1,' ans: ',ans	

	print ans
else:print 0
















