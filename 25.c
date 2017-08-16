#include "stdio.h"
#include "string.h"
#include "stdlib.h"
//T1025:不准确的答案 写的很多不舍得扔
typedef struct ad
{
	int addr;
	int data;
	int nextone;
	struct ad *next;
}address;

int n=0;
address *create(int N)
{
	address *phead=NULL, *p1=NULL, *p=NULL;
	p1 = (address *)malloc(sizeof(address));
	p1 = p;
	n=N;
	for(int i=0;i<N;i++)
	{
		p = (address *)malloc(sizeof(address));//每一次重新分配内存 地址p被毁掉 而p1不能被毁掉 用于储存
		scanf("%d%d%d", &p->addr, &p->data, &p->nextone);
		if(NULL==phead)phead=p;//写成NULL==phead好习惯受益一生
		else p1->next = p;
		p1 = p;
	}
	p1->next = NULL;
	return phead;
}
address *sort(address *phead)
{//n>=3 顺序是错误的
	address *p1=(address *)malloc(sizeof(address));
	address *p2=(address *)malloc(sizeof(address));
	address *p3=(address *)malloc(sizeof(address));
	address *p4=(address *)malloc(sizeof(address));
	p1 = phead;
	p2 = phead->next;
	while(p1->next->next!=NULL)
	{
		while(p2!=NULL)
		{
			if(p1->nextone == p2->addr)
			{
				if(p1->next->next==p2)
				{
					p1->next->next = p2->next;
					p2->next = p1->next;
					p1->next = p2;
				}
				if(p1->next->next!=p2&&p1->next!=p2)
				{
					p4 = p1->next->next;
					p1->next->next = p2->next;
					p3->next = p1->next;
					p1->next = p2;
					p2->next = p4;
				}
			}
			p3 = p2;
			p2 = p2->next;
		}
		p1 = p1->next;
		p2 = p1->next;
	}
	return phead;
}
address *exchange(address *phead, int ADDR)
{
	address *p1=NULL, *p2=NULL, *p3=NULL;
	p3 = (address *)malloc(sizeof(address));
	p2 = (address *)malloc(sizeof(address));
	p1 = (address *)malloc(sizeof(address));
	p1 = phead;
	while(p1!=NULL)
	{
		if(ADDR == p1->addr)
		{
			if(phead == p1)break;
			else if(phead->next == p1)
			{
				phead->next = p1->next;
				p1->next = phead;
				break;
			}
			else
			{
				p3 = phead->next;
				phead->next = p1->next;
				p1->next = p3;
				p2->next = phead;
				break;
			}
		}
		p2 = p1;
		p1 = p1->next;
	}
	phead = p1;	
	return phead;
}
address *reverse(address *phead, int k)
{
	address *p1=(address *)malloc(sizeof(address));
	address *p2=(address *)malloc(sizeof(address));
	address *p3 = (address *)malloc(sizeof(address));
	address *p4 = (address *)malloc(sizeof(address));
	p1 = phead;
	if(1==k)return phead;
	else
	{
		for(int i=0;i<k;i++)
		{
			p4 = p1;
			p1 = p1->next;
		}
		p4 = p1;
		p2 = phead;
		while(1)
		{
			p3 = p2->next;
			p2->next = p4;
			if(p3==p1)break;
			p4 = p2;
			p2 = p3;
		}
	}
	return p2;
}

void output(address *phead, int k)
{
	address *p1 = (address *)malloc(sizeof(address));
	p1 = phead;
	for(int i=0;i<k;i++)
	{
		p1->nextone = p1->next->addr;
		p1 = p1->next;
	}
	p1 = phead;
	while(p1!=NULL)
	{
		if(-1!=p1->nextone)
			printf("%05d %d %05d\n", p1->addr, p1->data, p1->nextone);
		else
			printf("%05d %d %d\n", p1->addr, p1->data, p1->nextone);
		p1 = p1->next;
	}
	free(p1);
	p1 = NULL;
}
int main(int argc, char *argv[])
{
	address *create(int n);
	void output(address *phead, int k);
	address *exchange(address *phead, int ADDR);
	address *sort(address *phead);
	address *reverse(address *phaed, int k);
	int ADDR, N, k;
	scanf("%d%d%d", &ADDR, &N, &k);
	address *phead = create(N);
	phead = exchange(phead, ADDR);
	phead = sort(phead);
	phead = reverse(phead, k);//返回值：带上句柄
	output(phead, k);
	return 0;
}
