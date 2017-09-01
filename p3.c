#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n;
	scanf("%d",&n);
	int count=0;
	int* arr=(int*)malloc(n*sizeof(int));
	int i;
	for (i = 0; i < n; ++i)
	{
		scanf("%d",&arr[i]);
	}
	for (i = 0; i < n; ++i)
	{
		int j;
		int num=0;
		int sum=0;
		for (j = i+1; j < n; ++j)
		{
			if (arr[j]>arr[i] && num==0)
			{
				num=arr[j];
				sum++;
			}
			else if (arr[j]<num)
			{
				sum++;
				break;
			}

		}
		if (sum==0)
		{
			count+=15;
		}
		else if (sum==1)
		{
			count+=10;
		}
		else if (sum==2)
		{
			count+=5;
		}
	}
	printf("%d\n",count);
	return 0;
}