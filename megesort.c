#include <stdio.h>
#include <stdlib.h>
void merge(int *a,int p,int q,int r)
{
	int n=(r-p)+1;
	printf("n=%d\n",n);
	int *temp=(int*)malloc(n*sizeof(int));
	int i=0;
	int L=p;
	int R=q+1;
	while(L<=q && R<=r)
	{
		if (a[L]<=a[R])
		{
			temp[i]=a[L];
			L++;
		}
		else
		{
			temp[i]=a[R];
			R++;
		}
		i++;
	}
	while(L<=q)
	{
		temp[i]=a[L];
		L++;
		i++;
	}
	while(R<=r)
	{
		temp[i]=a[R];
		R++;
		i++;
	}
	for (i = 0; i < n; ++i)
	{
		a[i]=temp[i];
	}
}

void mergesort(int *a,int p,int q)
{
	if (p<q)
	{
		int mid=(p+q)/2;
		mergesort(a,p,mid);
		mergesort(a,mid+1,q);
		merge(a,p,mid,q);
	}
}

int main()
{
	int a[]={6,3,2,5,4};
	mergesort(a,0,4);
	int i;
	for (i = 0; i < 5; ++i)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
	return 0;
}