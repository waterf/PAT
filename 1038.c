#include "stdio.h"

int main()
{
	int n;
	scanf("%d", &n);
	int a[101]={0}, x;
	while(n--)
	{
		scanf("%d", &x);
		a[x]++;
	}
	scanf("%d", &n);
	while(n--)
	{
		scanf("%d", &x);
		printf("%d", a[x]);
		if(0!=n)printf(" ");
	}
}
