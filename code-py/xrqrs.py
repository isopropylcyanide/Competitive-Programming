import sys		#Solve Queries
import bisect

n=int(sys.stdin.readline())

lis=[]

def binS(tlis,x,n):

	first,last=0,n-1
	mid=(first+last)/2 
    
        while first<=last:
		if x==tlis[mid]:
			return mid+1

      		elif x>tlis[mid]:
			first=mid+1
		else:
			last=mid-1
    	 
        	mid=(first + last)/2
	
	if first>last:
		return mid+1


def count_lessthan(tlis,x,n):
	
	if x<tlis[0]:
		print 0
	elif x>tlis[n-1]:
		print n
	else:
		print binS(tlis,x,n)
	
def kthsmall(tlis,k):
	
	pivot= tlis[len(tlis)/2]
	
	smlis,lalis=[],[]
	for i in tlis:
		if i<pivot: 
			smlis.append(i)
		else:
			lalis.append(i)
	print smlis,lalis
	
	if k<len(smlis):
		return kthsmall(smlis,k)
	elif len(lalis)<k<len(tlis):
		return kthsmall(lalis,k-len(tlis)-len(lalis))
	else:
		return pivot


while n:
	query=map(int,raw_input().split())
	
	if query[0]==0:			#Add the integer number x at the end of the array. 
		lis.append(query[1])
		
	elif query[0]==1:		#On the interval L..R find a number y, to maximize (x xor y).

		y,x,xmax=0,query[3],0
		tlis=lis[query[1]-1:query[2]]

		for i in tlis:
			if x^i >xmax:
				xmax=x^i
				y=i
		print y

	elif query[0]==2:		#Delete last k numbers in the array
		
		lis=lis[:len(lis)-query[1]]

	elif query[0]==3:		#On the interval L..R, count the number of integers less than or equal to x
		tlis=[]
		for i in xrange(query[1]-1,query[2]):
			bisect.insort_left(tlis,lis[i])
		#print tlis
		x=query[3]

		count_lessthan(tlis,x,len(tlis))


	elif query[0]==4:		#On the interval L..R, find the kth smallest integer (kth order statistic).
		
		tlis=[]
		for i in xrange(query[1]-1,query[2]):
			bisect.insort_left(tlis,lis[i])
	
		k=query[3]
		print tlis[k-1]
		#print kthsmall(tlis,k)	
	
	n-=1



























