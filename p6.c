#include <stdio.h>
#include <stdlib.h>
struct corr
{
	int x;
	int y;
};
 
int check(struct corr corr1,struct corr corr2)
{	
	
	if (corr1.x==corr2.x || corr1.y==corr2.y)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	int count=0;
	struct corr* arr=(struct corr*)malloc(n*sizeof(struct corr));
	int i;
	for (i = 0; i < n; ++i)
		{
			scanf("%d %d",&(arr[i].x),&(arr[i].y));
		}
	
	for (i = 0; i < n; ++i)
		{
			int j;
			for (j = i+1; j < n; ++j)
			{
					if (check(arr[i],arr[j])==1)
					{
						count++;
					}
			}
		}
		printf("%d\n",count);	
	return 0;
}