#include <stdio.h>
#include <stdlib.h>
int left(int i)
{
	return 2*i+1;
}
int right(int i)
{
	return 2*i+2;
}
int parent(int i)
{
	return i/2;
}
void maxheapify(int *a,int i,int len)
{
	int l=left(i);
	int r=right(i);
	int largest;
	if (l<=len && a[l]>=a[i])
	{
		largest=l;
	}
	else
	{
		largest=i;
	}
	if (r<=len && a[r]>=a[largest])
	{
		largest=r;
	}
	if (largest!=i)
	{
		int temp=a[i];
		a[i]=a[largest];
		a[largest]=temp;
		return maxheapify(a,largest,len);
	}
}
void buildmaxheap(int *a,int s)
{
	int i;
	for (i = ((s/2)-1); i>=0; --i)
	{
		maxheapify(a,i,(s-1));
	}
}
int height(int * a,int n,int i)
{
	if (i>=n)
	{
		return -1;
	}
	else
	{
		int left_height=height(a,n,left(i));
		int right_height=height(a,n,right(i));
		if (left_height>=right_height)
		{
			return left_height+1;
		}
		else
		{
			return right_height+1;
		}
	}
}
int max(int* a)
{
	return a[0];
}
void increasekey(int *a,int i,int k)
{
	a[i]=k;
	while(i>=1 && a[parent(i)]<=a[i])
	{
		int temp=a[parent(i)];
		a[parent(i)]=a[i];
		a[i]=temp;
		i=parent(i);
	}
}
void heapsort(int *a,int s)
{
	buildmaxheap(a,s);
	int n=s-1;
	while(n>=1)
	{
		int temp=a[n];
		a[n]=a[0];
		a[0]=temp;
		n--;
		maxheapify(a,0,n);
	}
}
void heapinsert(int* a,int k,int s)
{
	int size=s+1;
	a[size]=-253655585;
	increasekey(a,size,k);
}
void main()
{
	int a[1]={1};
	buildmaxheap(a,9);
	int i;
	printf("Height = %d\n",height(a,1,0));
}