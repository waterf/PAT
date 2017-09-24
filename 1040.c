#include "stdio.h"
#include "stdlib.h"
/*https://github.com/a254476321/PAT-Basic/blob/master/1040.c*/
typedef struct pat
{
	char ele;
	struct pat* next;
} PAT;
int main()
{
	int p=0, a=0, t=0;
	long sum=0;
	char x;
	PAT *phead=NULL, *p1=NULL, *p2=NULL;
	if((x=getchar())!='\n')
	{
		if('T'==x)t++;
		phead = (PAT *)malloc(sizeof(PAT));
		phead->ele = x;
		p1 = phead;
		while((x=getchar())!='\n')
		{
			if('T'==x)t++;
			p2 = (PAT *)malloc(sizeof(PAT));
			p2->ele = x;
			p1->next = p2;
			p1 = p2;
		}
		p1->next = NULL;
	}
	while(phead!=NULL)
	{
		if('P'==phead->ele)p++;
		else if('T'==phead->ele)t--;
		else
		{
			sum += p*t;
		}
		phead = phead->next;
	}
	printf("%ld", sum%1000000007);
	free(phead);
	phead = NULL;
	return 0;
}