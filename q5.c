#include <stdio.h>
#include <stdlib.h>
#include <math.h>
long int power(int s)
{
	long int k=1,i;
	for (i = 0; i < s; ++i)
	{
		k=k*2;
	}
	return k;
}

void main()
{
	int n;
	scanf("%d",&n);
	long int k,i;
	scanf("%ld",&k);
	long int arr[n];
	for (i = 0; i < n; ++i)
	{
		scanf("%ld",&arr[i]);
	}
	long int count=0,j,subset,temp=0;
	subset=power(n)-1;
	for (count = 1; count <= subset; ++count)
	{
		long int pro=1;
		for ( j = 0; j < n; ++j)
		{
			if ((count&(1<<j)))
			{
				pro=pro*arr[j];
			}
		}
		if (pro<=k)
		{
			temp++;
		}
	}
	printf("%ld\n",temp);
}