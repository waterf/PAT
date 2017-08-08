#include "stdio.h"
#include "stdlib.h"
typedef struct cake
{
	float numprice;
	float num;
	float price;
	struct cake *next;
}mooncake;
mooncake *create(int n)
{
	int i;
	void output(mooncake *phead);
	mooncake *phead=NULL, *p=NULL, *p1=NULL;
	p1 = p;
	for(i=0;i<n;i++)
	{
		p = (mooncake *)malloc(sizeof(mooncake));
		scanf("%f", &p->num);
		if(phead==NULL)phead=p;
		else p1->next=p;
		p1 = p;
	}
	p1->next = NULL;
	mooncake *p2=phead;
	while(p2!=NULL)
	{
		scanf("%f", &p2->numprice);
		p2->price = p2->numprice/p2->num;
		p2 = p2->next;
	}
	return phead;
}
void output(mooncake *phead)
{
	while(phead!=NULL)
	{
		printf("%f%f%f", phead->num, phead->numprice, phead->price);
		phead = phead->next;
	}
}
mooncake *bubblesort(mooncake *phead)
{
	mooncake *pfirst, *p2;
	mooncake *p1, *endpt, *p;
	p1 = (mooncake *)malloc(sizeof(mooncake));

	p1->next = phead;
	phead = p1;
	for(endpt=NULL;endpt!=phead;endpt=p)
	{
		for(p=p1=phead;p1->next->next!=endpt;p1=p1->next)
		{
			if(p1->next->price<p1->next->next->price)
			{
				p2 = p1->next->next;
				p1->next->next = p2->next;
				p2->next = p1->next;
				p1->next = p2;
				p = p1->next->next;
			}
		}
	}
	p1 = phead;
	phead = phead->next;
	return phead;
}
int main(int argc, char *argv[])
{
	int N, D;
	float sumprice=0.0, sumnum=0.0;
	float tempprice, tempnum;
	mooncake *create(int n);
	mooncake *bubblesort(mooncake *phead);
	scanf("%d%d", &N, &D);
	mooncake *phead;
	phead = create(N);
	phead = bubblesort(phead);
	while(sumnum<D&&phead!=NULL)
	{
		sumnum += phead->num;
		sumprice += phead->numprice;
		tempnum = phead->num;
		tempprice = phead->numprice;
		phead = phead->next;
	}
	if(phead==NULL)//if下面的bug改了好长时间！！
	{
		if(sumnum<=D)printf("%.2f", sumprice);
		else
		{
			sumprice -= tempprice;
			sumprice += tempprice*(tempnum-(sumnum-D))/tempnum;
			printf("%.2f", sumprice);
		}
	}
	else
	{
		if(sumnum==D)printf("%.2f", sumprice);
		else
		{
			sumprice -= tempprice;
			sumprice += tempprice*(tempnum-(sumnum-D))/tempnum;
			printf("%.2f", sumprice);
		}
	}
	return 0;
}

