from collections import OrderedDict
import operator

S=map(str,raw_input().strip())

def top_three(freq):
	sort=sorted(freq.items(),key=operator.itemgetter(1),reverse=True)
	curr_max_key,curr_max_val='',0

	toPrint,insert_at,last_value=[],0,0
	for i,j in sort:
		if insert_at==3 and j<toPrint[insert_at-1]:break

		if j==curr_max_val:
			last_value=j

			if insert_at<=2:
				toPrint.append(i)
				if toPrint[insert_at-1]>toPrint[insert_at]:
					toPrint[insert_at],toPrint[insert_at-1]=toPrint[insert_at-1],toPrint[insert_at]
				insert_at+=1
				
			else:
				if toPrint[insert_at-1]>i:
					toPrint.pop()
					toPrint[insert_at-1]=i
				insert_at+=1

		else:
			curr_max_key=i
			curr_max_val=j
			toPrint.append(curr_max_key)
			insert_at+=1
			
	for i in toPrint:
		print i,freq[i]

ans=OrderedDict.fromkeys(S).keys()
count=[S.count(i) for i in ans]
freq=dict(zip(ans,count))
top_three(freq)
