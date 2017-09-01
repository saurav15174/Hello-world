#include <stdio.h>
#include <stdlib.h>
void selection_sort(int *a,int n)
{
	int i,min,temp;
	for (i = 0; i < n-1; ++i)
	{
		min=i;
		int j;
		for (j = i+1; j < n; ++j)
		{
			if (a[j]<=a[min])
			{
				min=j;
			}
		}
		int temp=a[i];
		a[i]=a[min];
		a[min]=temp;
	}
}

int main()
{
	int b[]={3,4,5,2,1,7};
	selection_sort(b,6);
	int i;
	for (i = 0; i < 6; ++i)
	{
		printf("%d ",b[i]);
	}
	printf("\n");
	return 0;
}