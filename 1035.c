#include "stdio.h"

int insert_sort(int *a, int *c, int n)
{
	int i, flag, index=n;
	for(i=1;i<n;i++)
	{
		flag = 0;
		int x = a[i];
		int j = i-1;
		if(a[i-1]>a[i])
		{
			while(a[j]>x)
			{
				a[j+1] = a[j];
				if(!j)
				{
					j--;
					break;
				}
				else
					j--;
			}
			a[j+1] = x;
		}
		for(int k=0;k<n;k++)
		{
			if(c[k] != a[k])
			{
				flag = 1;
				break;
			}
		}
		if(!flag)index = i;
		if(index+1 == i)
		{
			printf("Insertion Sort\n");
			for(int k=0;k<n;k++)
			{
				printf("%d", a[k]);
				if(n-1 != k)printf(" ");
			}
			return 0;
		}
	}
}

void merge(int *a, int *b, int i, int m, int n)
{
	int j, k;
	for(j=m+1, k=i;i<=m && j<=n;k++)
	{
		if(a[j]<a[i])b[k] = a[j++];
		else b[k] = a[i++];
	}
	while(i<=m)b[k++] = a[i++];
	while(j<=n)b[k++] = a[j++];
}
int merge_sort(int *a, int *b, int *c, int length)
{
	int len = 1;
	int *swp;
	int index=0, flag;
	while(len<length)
	{
		int i=0;
		int s = len;
		len = 2*s;
		flag = 0;
		while(i+len<length)
		{
			merge(a, b, i, i+s-1, i+len-1);
			i += len;
		}
		if(i+s<length)
		{
			merge(a, b, i, i+s-1, length-1);
		}
		for(int k=0;k<length;k++)
		{
			if(b[k] != c[k])
			{
				flag = 1;
				break;
			}
		}
		if(!flag)index = 2;
		if(2==index && flag)
		{
			printf("Merge Sort\n");
			for(int k=0;k<length;k++)
			{
				printf("%d", b[k]);
				if(length-1 != k)printf(" ");
			}
			return 0;
		}
		swp = a;
		a = b;
		b = swp;
	}
}

int main()
{
	int N;
	int a[100], b[100], c[100], aplus[1000];
	scanf("%d", &N);
	for(int i=0;i<N;i++)
	{
		scanf("%d", &a[i]);
		aplus[i]  = a[i];
	}
	for(int i=0;i<N;i++)
		scanf("%d", &c[i]);
	insert_sort(a, c, N);
	merge_sort(aplus, b, c, N);
}
