
def fact(num):
 pro=1 
 
 if num < 0 or num == 0:
   return 1
   
 else:
  for i in range(1,num+1):
   pro=pro*i
  
 return pro

t=int(input())

while 1<=t<=100:
 	a = int(input())
 	print fact(a)
 	t-=1
