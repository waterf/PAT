#include "stdio.h"
#include "stdlib.h"
/*来自大佬：https://github.com/a254476321/PAT-Basic/blob/master/1030.c*/
int cmp(const void *a, const void *b)
{
	return *(int *)a-*(int *)b;
}
int main()
{
	int i, j, N, p, *s;
	int temp=0;
	scanf("%d%d", &N, &p);
	s = (int *)malloc(N*sizeof(int));
	for(i=0;i<N;i++)
	{
		scanf("%d", &s[i]);
	}
	qsort(s, N, sizeof(s[0]), cmp);//常常和bsearch(const void *k, const void *s, size_t n, size_t size, int cmp())
	for(i=0;i+temp<N;i++)//每一次都只测试比上一次大的 提高算法效率
	{
		for(j=temp+i;j<N;j++)
		{
			if(s[i]<1.0*s[j]/p)break;//这里不能适合用乘法的原因：10^9*10^9=10^18--int类型2^32->10^10-10^11
			else temp=j-i+1;
		}
	}
	free(s);
	printf("%d", temp);
	return 0;
}
