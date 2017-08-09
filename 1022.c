#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int main(int argc, char argv[])
{
	long A, B, D;
	long sum;
	int i=0, j=0;
	int a[100];
	scanf("%ld%ld%ld", &A, &B, &D);
	sum = A+B;
	if(10==D)printf("%ld", A+B);
	else
	{
		if(0==sum)printf("%ld", sum);
		else
		{
			while(0!=sum)
			{
				a[i] = sum%D;
				sum = sum/D;
				i++;
			}
			for(j=i-1;j>=0;j--)
				printf("%d", a[j]);
		}
	}
	return 0;
}

