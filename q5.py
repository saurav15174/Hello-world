a=input()
b=list(map(int,a.split(" ")))
c=input()
d=list(map(int,c.split(" ")))
subset=(2**b[0])
count=0
for i in range(1,subset):
	pro=1
	for x in range(0,len(d)):
		if(i&(1<<x)):
			pro=pro*d[x]
	if(pro<=b[1]):
		count+=1;
print(count)	