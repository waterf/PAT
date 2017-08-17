/*
=========================
参考这个哥们的答案完善的：
https://github.com/a254476321/PAT-Basic/blob/master/1025.c
=========================
*/
#include "stdio.h"
typedef struct addr
{
	int address, data, next;
}list;
void swap(list *a, list *b)
{
	list temp = *a;
	*a = *b;
	*b = temp;
}
int main()
{
	void swap(list *a, list *b);
	int ADDR, N, k;
	int temp=0;
	scanf("%d%d%d", &ADDR, &N, &k);
	list p[N];
	for(int i=0;i<N;i++)
		scanf("%d%d%d", &p[i].address, &p[i].data, &p[i].next);
	for(int i=0;i<N;i++)
	{
		if(ADDR==p[i].address)
		{
			swap(&p[0],&p[i]);//找到head并交换
			break;
		}
	}
	for(int j=0;j<N-1;j++)
	{
		if(-1==p[j].next)//(1)所以是说，给定的单链表可能有多余的元素 呵呵
		{
			N = j+1;
			break;
		}
		for(int i=j+1;i<N;i++)
		{
			if(p[j].next==p[i].address)
			{
				swap(&p[j+1], &p[i]);//排序
				break;
			}
		}
	}
	for(int j=0;j+k<=N;j+=k)//(2)交换前k个
	{
		for(int i=j;i-j<k/2;i++)
		{
			swap(&p[i], &p[k-i+j+j-1]);
		}
	}
	for(int i=0;i<N-1;i++)
	{
		p[i].next = p[i+1].address;
	}
	for(int i=0;i<N-1;i++)
		printf("%05d %d %05d\n", p[i].address, p[i].data, p[i].next);
	printf("%05d %d -1", p[N-1].address, p[N-1].data);
	return 0;
}
