#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
	int t;
	scanf("%d",&t);
	int i;
	for (i = 0; i < t; ++i)
	{
		int n,b;
		scanf("%d",&n);
		scanf("%d",&b);
		double n1=n;
		double b1=b;
		double x,y,z;
		x=n1/(2*b1);
		y=(n1-(b1*x))*x;
		printf("%.f\n",floor(y));
	}
	return 0;
}