#include "stdio.h"
#include "stdlib.h"
#include "string.h"	
typedef struct stu
{
	int id;
	int sgrade;
	int vgrade;
	struct stu *next;
}student;
int n=0;//是否是全局变量
//void clear_one_node()算啦先把链表所有基础操作写一遍
student *create(int N)
{
	int i;
	student *p=NULL, *pd=NULL, *phead=NULL;
	pd = p;
	for(i=0;i<N;i++)
	{
		p = (student *)malloc(sizeof(student));//还是要分配内存，struct只是一个类型
		scanf("%d%d%d", &p->id, &p->vgrade, &p->sgrade);
		n++;
		if(NULL==phead)phead=p;
		else pd->next = p;
		pd = p;
	}
	p->next = NULL;//单向链表
	return phead;
}
student *insert(student *phead, int id, student *pnode)//插入指定id后面
{
	student *p1;
	while(phead==NULL)
	{
		phead = pnode;
		pnode->next = NULL;
		n++;
		return phead;
	}
	p1 = phead;
	while(p1->next!=NULL&&p1->id!=id)
	  p1 = p1->next;
	if(p1->id==id)
	{
		pnode->next = p1->next;
		p1->next = pnode;
		n++;
	}
	else printf("p is NOT FOUND");
	return phead;
}
student *del(student *phead, int id)
{
	student *p1;
	student *p2;
	if(phead==NULL)
	{
		printf("NULL!\n");
		return phead;
	}
	p1 = phead;
	while(p1->next!=NULL&&p1->id!=id)
	{
		p2 = p1;
		p1 = p1->next;
	}
	if(p1->id==id)
	{
		if(p1==phead)
		{
			phead=phead->next;
			n--;
		}
		else
		{
			p2->next = p1->next;
			n--;
		}
	}
	else printf("NOt FOUND\n");
	return phead;
}
student *reverse(student *phead)
{
	student *p1=phead, *p2=NULL, *p;
	while(p1!=NULL)//p1用于遍历
	{
		p = p1->next;//储存了与原来p1中的所有的p->next
		p1->next = p2;
		p2 = p1;//储存reverse后的‘链表’
		p1 = p;
	}
	phead = p2;
	return phead;
}
student *insertsort(student *phead)//插入排序（从小到大）
{
	student *p, *q;
	student *first;
	student *t;

	first = phead->next;
	phead->next = NULL;
	
	while(first!=NULL)
	{
		for(q=phead,t=first;(q!=NULL)&&(q->id<t->id);p=q,q=q->next);//核心部分
		first = first->next;
		if(q==phead)
		  phead = t;
		else
		  p->next = t;
		t->next = q; 
	}
	return phead;
}
student *bubblesort(student *phead)//改进后的冒泡排序(从小到大)
{
	student *p, *p1, *p2, *p3, *endpt;//每次遍历之后都会下沉一个较大的后面不需要再遍历
	p1 = (student *)malloc(sizeof(student));

	p1->next = phead;
	phead = p1;
	for(endpt=NULL;endpt!=phead;endpt=p)
	{
		for(p=p1=phead;p1->next->next!=endpt;p1=p1->next)
		{
			if(p1->next->id > p1->next->next->id)
			{//交换
				p2 = p1->next->next;//这些只是理解起来都很酸爽
				p1->next->next = p2->next;
				p2->next = p1->next;
				p1->next = p2;

				p = p1->next->next;//记录本次交换的最后一个
			}
		}
	}
	p1 = phead;
	phead = phead->next;
	free(p1);
	p1 = NULL;
	return phead;
}

int main(int argc, char *argv[])
{
	int N, L, H;
	scanf("%d%d%d", &N, &L, &H);

	student *create(int N);
	student *insert(student *phead, int id, student *pnode);
	student *del(student *phead, int id);
	student *reverse(student *phead);
	student *insertsort(student *phead);
	student *bubblesort(student *phead);

	student *phead=create(N), *pnode;

	//pnode = (student *)malloc(sizeof(student));
	//scanf("%d%d%d", &pnode->id, &pnode->vgrade, &pnode->sgrade);
	//insert(phead, 1001, pnode);//insert将phead作为参数 并不改变phead本身及其指向的值

	//phead = del(phead, 1001);//而del在phead->next为NULL时需要改变phead地址指向的变量注意
    //phead = reverse(phead);
    //phead = insertsort(phead);
	phead = bubblesort(phead);
	while(phead!=NULL)
	{
		printf("%d %d %d %d\n",phead->id, phead->vgrade, phead->sgrade, n);
		phead = phead->next;
	}
	return 0;
}
