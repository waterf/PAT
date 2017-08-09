#include "stdio.h"
#include "stdlib.h"
int main(int argc, char *argv[])
{//丢两分 段错误
	int N;
	int de, in;
	int det;
	int *a=(int *)malloc(sizeof(int));
	scanf("%d", &N);
	int *sort(int n, int *a);
	int decrease(int *a);
	int increase(int *a);
	a = sort(N, a);
	de = decrease(a);
	in = increase(a);
	if(de==in)printf("%d - %d = 0000", N, N);
	else
	{
	    while(1)
		{
			printf("%04d - %04d = %04d\n", de, in, de-in);
			if(de-in==6174)break;
			det = de;
			a = sort(de-in, a);
			de = decrease(a);
			in = increase(a);
		}
	}
}
int *sort(int n, int *a)
{
	int i=0, j;
	int temp, sum=0, k=n, index=0;
	while(k)
	{
		a[i] = k%10;
		k /= 10;
		i++;
	}
	while(1)
	{
		index = 0;
		for(j=0;j<3;j++)
		{
			if(a[j]<a[j+1])
			{
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
				index = 1;
			}
		}
		if(!index)break;
	}
	return a;
}
int decrease(int *a)
{
	int sum=0, j=0;
	for(j=0;j<4;j++)
	{
		sum += a[j];
		if(j==3)break;
		sum *= 10;
	}
	return sum;
}
int increase(int *a)
{
	int j=0;
	int sum=0;
	for(j=3;j>=0;j--)
	{
		sum += a[j];
		if(j==0)break;
		sum *= 10;
	}
	return sum;
}

