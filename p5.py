n=int(input())
a=input();
b=list(map(int,a.split(" ")))
b.sort()
c=[]
i=0
j=len(b)-1
if len(b)==1:
	print("Impossible")
else:
	if len(b)%2==0:
		while i!=j-1:
			c.append(b[i])
			c.append(b[j])
			i+=1
			j-=1
		c.append(b[i])
		c.append(b[j])
		for x in c:
			print(x,end=" ")
		print()
	else:
		while i!=j:
			c.append(b[i])
			c.append(b[j])
			i+=1
			j-=1
		c.append(b[i])
		for y in c:
			print(y,end=" ")
		print()
	