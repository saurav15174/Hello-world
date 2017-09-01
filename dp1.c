#include <stdio.h>
#include <stdlib.h>
#define NIL -1

int fib(int n)
{
		if (n<=1)
		{
			printf("%d ",n);
		}
		else
		{
			return fib(n-1)+fib(n-2);
			printf("%d ",fib(n));
		}
}
int main()
{
	fib(7);
	printf("\n");
	return 0;
}