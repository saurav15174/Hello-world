#include <stdio.h>
#include <stdlib.h>
int dic[10000];
struct subset
{
	int data;
	int rank;
	int parent;
};

int findset(struct subset* s,int d)
{
	int ind=dic[d];
	if (s[dic[d]].parent!=dic[d])
	{
		ind=findset(s,s[s[ind].parent].data);
	}
	return ind;
}

void unionset(struct subset* s,int x,int y)
{
	int xroot=findset(s,x);
	int yroot=findset(s,y);
	if (s[xroot].rank<s[yroot].rank)
	{
		s[xroot].parent=dic[s[yroot].data];
		s[yroot].rank++;
	}
	else if (s[xroot].rank>s[yroot].rank)
	{
		s[yroot].parent=dic[s[xroot].data];
		s[xroot].rank++;
	}
	else
	{
		s[yroot].parent=dic[s[xroot].data];
		s[xroot].rank++;	
	}
}

int main()
{
	struct subset* p=(struct subset*)malloc(10*sizeof(struct subset));
	for (int i = 0; i < 10; ++i)
	{
		scanf("%d",&p[i].data);
		dic[p[i].data]=i;
		p[i].parent=i;
		p[i].rank=0;
	}
	unionset(p,2,3);
	unionset(p,3,4);
	unionset(p,4,5);
	unionset(p,5,6);
	unionset(p,6,7);
	unionset(p,7,8);
	unionset(p,8,9);
	unionset(p,9,10);
	printf("%d\n",findset(p,4));
	printf("%d\n",findset(p,5));
	printf("%d\n",findset(p,6));
	return 0;
}