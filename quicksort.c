#include <stdio.h>
#include <stdlib.h>
int partition(int* a,int l,int r)
{
	int i=l-1;
	int x=a[r];
	int j;
	for (j = l; j <r; ++j)
	{
		if (a[j]>=x)
		{
			i++;
			int temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
	}
	int t=a[i+1];
	a[i+1]=a[r];
	a[r]=t;
	return i+1;
}
int RandRange(int Min, int Max)
{
    int diff = Max-Min;
    return (int) (((double)(diff+1)/RAND_MAX) * rand() + Min);
}
int randpartition(int* a,int p,int r)
{
	int k=RandRange(p,r);
	
}
void quicksort(int* a,int q,int r)
{
	if (q<r)
	{
		int p=partition(a,q,r);
		quicksort(a,q,p-1);
		quicksort(a,p+1,r);
	}
}

int main()
{
	int a[6]={3,1,2,4,6,8};
	quicksort(a,0,5);
	int i;
	for (i = 0; i < 6; ++i)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
	return 0;
}