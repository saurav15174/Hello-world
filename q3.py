
def rotate(lst,x):
    copy = list(lst)
    for i in range(len(lst)):
        if x<0:
            lst[i+x] = copy[i]
        else:
            lst[i] = copy[i-x]
def maxsum(l,k):
	if(len(l)==1):
		return l[0]
	else:
		if(k>=len(l)):
			s=0
			for p in range(0,len(l)):
				s+=l[p]
			return s
		else:
			sum=0;
			max=0;
			for i in range(0,k):
				sum+=l[i]
			max=sum
			for j in range(0,(len(l)-k)):
				sum+=l[j+k]-l[j]
				if(sum>=max):
					max=sum
			return max
a=input()
b=list(map(int,a.split(" ")))
c=input()
d=list(map(int,c.split(" ")))
e=input()
f=list(e)
for i in range(0,len(f)):
	if(f[i]=='!'):
		rotate(d,1)
	elif(f[i]=='?'):
		print(maxsum(d,b[1]))

			

	