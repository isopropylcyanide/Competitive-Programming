N,Q=map(int,raw_input().split())

sets = [set() for _ in xrange(N)]
for i in xrange(1,N+1):
	sets[i-1].add(i)

while Q:
	code,a,b,k="",0,0,0
	code,a,b=raw_input().split()
	if code=="GET":k=b
	
	if code=="UNION":
		a,b,new=int(a)-1,int(b)-1,len(sets)
		sets.insert(new,set())
		sets[new]=set(sets[a].union(sets[b]))
		sets[a].clear()
		sets[b].clear()

	elif code=="GET":
		a,k=int(a)-1,int(b)-1
		new_list=sorted(list(sets[a]))
		print new_list[k]
	Q-=1


















