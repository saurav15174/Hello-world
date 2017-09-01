#include <stdio.h>
#include <stdlib.h>
#include <math.h>
long int check(long int* a,long int* b,long int n,long int m)
{
	long int i;
	while(m!=0)
	{
		long int max=0;
		 max=(a[0]/(b[0]+1))+1;
		for (i = 1; i < n; ++i)
		{
			if ((((a[i])/(b[i]+1))+1)>=max)
			{
				max=((a[i])/(b[i]+1))+1;
			}
		}
		
		for (i = 0; i < n; ++i)
		{
			if (a[i]>max)
			{
				b[i]++;
				m--;
			}
			else if (m<1)
			{
				break;
			}
		}
	}
	long int  max2=0;
	long int  j;
	for (j = 0; j < n; ++j)
	{
		if ((a[j]/b[j])>=max2)
		{
			max2=a[j]/b[j];
		}
	}
	return max2;
}
long int  main(){
	long int  n,m;
	scanf("%ld%ld",&n,&m);
	m=m-n;
	long int * arr1=(long int *)malloc(n*sizeof(long int ));
	long int * arr2=(long int *)malloc(n*sizeof(long int ));
	long int  i;
	for (i = 0; i < n; ++i)
	{
		scanf("%ld",&arr1[i]);
		arr2[i]=1;
	}
	printf("%ld\n",check(arr1,arr2,n,m));
	return 0;

}