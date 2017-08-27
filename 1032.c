#include "stdio.h"

int main()
{
	int n, a[100000][2], b[100000]={0};
	int i, max=0, c=0, d;
	scanf("%d", &n);
	for(i=0;i<n;i++)
	{
		scanf("%d%d", &a[i][0], &a[i][1]);
		if(max<a[i][0])max = a[i][0];
		b[a[i][0]-1] += a[i][1]; 
	}
	for(i=0;i<max;i++)
	{
		if(b[i]>c)
		{
			c = b[i];
			d = i+1;
		}
	}
	printf("%d %d", d, c);
	return 0;
}
