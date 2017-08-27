#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#define TIMENOW 20140906

int main()
{
	int N, i, j, k=0, temp, u=0;
	int index[100000]={0};
	int age[100000]={0}, age2[100000]={0};
	int quick_sort(int *a, int left, int right);
	scanf("%d", &N);
	temp = N;
	char *name[100000];//=(char *)malloc(5*sizeof(char));
	char *time[100000];//=(char *)malloc(10*sizeof(char));
	for(i=0;i<N;i++)
	{
		name[i] = (char *)malloc(5*sizeof(char));
		time[i] = (char *)malloc(10*sizeof(char));
		scanf("%s%s", name[i], time[i]);
	}
	for(i=0;i<N;i++)
	{
		for(j=0;j<strlen(time[i]);j++)
		{
			if('/'!=time[i][j])
			{
				age[i] += time[i][j] - '0';
				if(strlen(time[i])-1==j)break;
				age[i] *= 10;
			}
		}
	}
	for(i=0;i<N;i++)
	{
		if(age[i] > TIMENOW || TIMENOW-age[i] > 2000000)
		{
			temp--;
			index[i] = 1;
		}
		else
		{
			age2[u] = age[i];
			u++;
		}
	}
	quick_sort(age2, 0, u-1);
	if(temp)
		printf("%d ", temp);
	else
		printf("%d", temp);
	for(i=0;i<N;i++)
		if(age2[0] == age[i])
			printf("%s ", name[i]);
	for(i=0;i<N;i++)
		if(age2[u-1] == age[i])
			printf("%s", name[i]);
}

int quick_sort(int *a, int left, int right)
{
	int i=left, j=right;
	int k, u=0;
	int	index = a[left];
	while(i<j)
	{
		while(i<j&&a[j]>index)j--;
		if(i<j)a[i++] = a[j];
		while(i<j&&a[i]<index)i++;
		if(i<j)a[j--] = a[i];
		u = 1;
	}
	k = i;
	a[i] = index;
	if(u)
	{
		quick_sort(a, left, k-1);
		quick_sort(a, k+1, right);
	}
	else return 0;
}
