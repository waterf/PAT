#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int main(int argc, char *argv[])
{
	int a, da;
	int b, db;
	int pa, pbi;
	int j=0, k=0;
	int index[2];//储存m
	int outputsum(int n, int m);
	scanf("%d%d%d%d", &a, &da, &b, &db);
	while(a)
	{
		index[0] = a % 10;
		if(index[0]==da)j++;
		a /= 10;
	}
	while(b)
	{
		index[1] = b % 10;
		if(index[1]==db)k++;
		b /= 10;
	}
	index[0] = outputsum(da, j);
	index[1] = outputsum(db, k);
	printf("%d", index[0]+index[1]);
	return 0;
}
int outputsum(int n, int m)
{
	int i;
	int sum=n;
	if(!m)return 0;
	else
	{
		for(i=1;i<m;i++)
		{
			sum *= 10;
			sum += n;
		}
	return sum;
	}
}

