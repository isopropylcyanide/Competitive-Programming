
t=int(raw_input())
   
while 1<=t<=20000:
	a,b,d1,d2,dl,dist=0,0,0,0,0,0 

    	a,b=raw_input().split()
    	a=int(a) 
    	b=int(b)
    	c=a 
    	d=b
    
    	if a==b:
    		dist=0
    	else:
    		 
    		while c!=1:		#dist ROOT-A
  	 		c/=2 
  	  		d1+=1 
  	  	while d!=1:		#dist ROOT-B
  	 		d/=2 
  	  		d2+=1 
  	 
  	 
  	  	while a!=b and a!=1:	#gives LCA
  	 
  	 		if a==(b*2) or b==(a*2):	     break
  	  		elif a==(b*2 +1) or b==(a*2 +1):     break
  	 		a/=2 
  	  		b/=2 
  	  
  	  	while a!=1: 		#dist ROOT-LCA
		  	  a/=2 
  	  		  dl+=1 
  	  
	dist=d1+d2-(dl*2)
	print dist
	t-=1

