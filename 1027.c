#include "stdio.h"

void putstr(int n, char str)
{
	int k=0;
	for(int i=n;i>=1;i-=2)
	{
		for(int j=0;j<k;j++)
			putchar(' ');
		for(int j=i;j>=1;j--)
			printf("%c", str);
		putchar('\n');
		k++;
	}
	k -= 2;
	for(int i=2;i<=n;i+=2)
	{
		for(int j=0;j<k;j++)
			putchar(' ');
		for(int j=0;j<=i;j++)
			printf("%c", str);
		putchar('\n');
		k--;
	}
}
int main()
{
	int N, n=0;//1000=>n>=1
	char str;
	scanf("%d", &N);
	getchar();
	scanf("%c", &str);
	while(1)
	{
		if(N==2*n*n-1)break;
		else if(2*n*n-1<N)n++;
		else
		{
			n -= 1;
			break;
		}
	}
	putstr(2*n-1, str);
	printf("%d", N-2*n*n+1);
	return 0;
}
