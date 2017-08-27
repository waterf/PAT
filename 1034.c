#include "stdio.h"
#include "math.h"
#include "stdlib.h"

long gcd(long x, long y)
{
	long z;
	if(x<0)x = -x;
	while(y) 	
	{
		z = x%y;
		x = y;
		y = z;
	}
	return x;
}
void output(long a, long b)
{
	long k=0;
	long temp=gcd(a, b);
	if(!b)
	{
		printf("Inf");
	}
	else
	{
		if(0==a)
		{
			printf("0");
		}
		else
		{
			a /= temp;
			b /= temp;
			if(a<0)
			{
				k = 1;
				a = -a;
			}
			if(a<b)
			{
				if(k)printf("(-");
				printf("%ld/%ld", a, b);
				if(k)printf(")");	
			}
			else if(a==b)
			{
				if(k)printf("(-1)");
				else printf("1");
			}
			else
			{
				if(!(a%b))
				{
					if(k)printf("(-%ld)", a);
					else printf("%ld", a);
				}
				else
				{
					if(k)printf("(-%ld %ld/%ld)", a/b, a%b, b);
					else printf("%ld %ld/%ld", a/b, a%b, b);
				}
			}	
		}
	}
}

int main()
{
	long num[4], result[2];
	scanf("%ld/%ld %ld/%ld", &num[0], &num[1], &num[2], &num[3]);
	//+
	result[0] = num[0]*num[3]+num[1]*num[2];
	result[1] = num[1]*num[3];
	
	output(num[0], num[1]);
	printf(" + ");
	output(num[2], num[3]);
	printf(" = ");
	output(result[0], result[1]);
	printf("\n");
	
	result[0] = num[0]*num[3]-num[1]*num[2];
	result[1] = num[1]*num[3];

	output(num[0], num[1]);
	printf(" - ");
	output(num[2], num[3]);
	printf(" = ");
	output(result[0], result[1]);
	printf("\n");

	result[0] = num[0]*num[2];
	result[1] = num[1]*num[3];
	output(num[0], num[1]);
	printf(" * ");
	output(num[2], num[3]);
	printf(" = ");
	output(result[0], result[1]);
	printf("\n");

	result[0] = num[0]*num[3];
	result[1] = num[1]*num[2];
	if(result[1]<0)
	{
		result[0] = -result[0];
		result[1] = -result[1];
	}
	output(num[0], num[1]);
	printf(" / ");
	output(num[2], num[3]);
	printf(" = ");
	output(result[0], result[1]);
	printf("\n");
	return 0;
}
