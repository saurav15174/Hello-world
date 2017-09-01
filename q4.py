n=input()
q=list(map(int,n.split(" ")))
p=input()
d=list(map(int,p.split(" ")))
count=0;
for i in range(0,len(d)):
	j=i
	temp=1
	while(j<len(d)):
		temp=temp*d[j]
		if(temp>=q[1]):
			count+=1
		j+=1
print(((2**q[0])-1)-count)
