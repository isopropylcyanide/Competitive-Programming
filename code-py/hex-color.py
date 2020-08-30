
N=input()
color=[]

def valid_util(i):
	for index,j in enumerate(i[1:]):
		if index>5 :return
		if j.isdigit() or 65<=ord(j)<=70 or 97<=ord(j)<=102:pass
		else:return
	print i	

def valid(i,index,check_for_brace):

	l,flag=len(i),0

	if check_for_brace==True:
		if color[index+1]=='{':return
		else:flag=1
	else:flag=1

	if flag==1:
		if len(i)==1:return
		elif len(i)>4:
			while i[-1].isalnum()==False:
				i=i[:len(i)-1]
				
		valid_util(i)
		
	else:return	
	
while N:
	lis=map(str,raw_input().split())
	text=[i for i in lis if '#' in i and '{}' not in i or '{' in i and '{}' not in i]
	for i in text:
		counts=i.count('#')
		while counts:
			f=i.find('#')
			s=i.replace('#','-1',1).find('#')-1

			if s<0:
				color.append(i[f:])
			else:
				color.append(i[f:s])
				i=i[s:]
			counts-=1
		
		if  i.startswith('{'):
				color.append(i)
	N-=1


for index,i in enumerate(color):
	if i=='{':continue

	if index==len(color)-1:
		valid(i,index,False)
	else:
		valid(i,index,True)


