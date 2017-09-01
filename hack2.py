n=int(input())
t=input()
arr=list(map(int,t.split(" ")))
odd=[]
eve=[]
for i in range(0,len(arr)):
	if(arr[i]%2==0):
		eve.append(arr[i])
	else:
		odd.append(arr[i])
sume=0
sumo=0
eve.sort()
odd.sort()
for i in range(0,len(eve)):
	sume+=eve[i]
for i in range(0,len(odd)):
	sumo+=odd[i]
eve.append(sume)
odd.append(sumo)
eve=eve+odd
print(*eve)