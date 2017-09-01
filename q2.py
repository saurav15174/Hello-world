def max(l):
    a=0
    for i in range(0,len(l)):
        if(l[i]>=a):
            a=l[i]
    return a
t=int(input())
for x in range(1,t+1):
    a=int(input())
    b=input()
    c=b.split(" ")
    e=list(map(int,c))
    x=max(e)
    print(a-x)