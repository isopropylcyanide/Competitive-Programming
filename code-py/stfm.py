import sys
from math import factorial

def look_up(i,n,m):
	global temp,k
	if i<=0:
		return 0
	if k[i]!=0:
		temp+=k[i]
	else:
		temp=i*(factorial(i)+n)
		k[i]=look_up(i-1,n,m)
		temp+=k[i]
	
	return temp%m

n,m=map(int,raw_input().split());
tsum,lis,temp=0,map(int,raw_input().split()),0

k=[0 for i in range(max(lis)+1)]
k[0],k[1]=0,2%m

for i in lis:
	temp=0
	tsum+=look_up(i,n,m)

print tsum%m


			
