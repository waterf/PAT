#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int main(int argc, char *argv[])
{
	int i=0, index;
	int N;
	int winc[2]={0}, winj[2]={0}, winb[2]={0};
	char *a, *b;
	int A[3]={0}, B[3]={0};
	int comparision(char *str1, char *str2);
	void output(int s, int d, int f);
	a = (char *)malloc(100000*sizeof(char));
	b = (char *)malloc(100000*sizeof(char));
	scanf("%d", &N);
	for(i=0;i<N;i++)
	{
		scanf("%s%s", a+i, b+i);
	}
	for(i=0;i<N;i++)
	{
		index = comparision(a+i, b+i);
		if(index==1)
		{
			A[0]++;
			B[2]++;
			if(*(a+i)=='C')winc[0]++;
			else if(*(a+i)=='J')winj[0]++;
			else winb[0]++;
		}
		else if(index==0)
		{
			A[1]++;
			B[1]++;
		}
		else
		{
			A[2]++;
			B[0]++;
			if(*(b+i)=='C')winc[1]++;
			else if(*(b+i)=='J')winj[1]++;
			else winb[1]++;
		}
	}
	printf("%d %d %d\n", A[0], A[1], A[2]);
	printf("%d %d %d\n", B[0], B[1], B[2]);
	output(winc[0], winj[0], winb[0]);
	printf(" ");
    output(winc[1], winj[1], winb[1]);
	return 0;
}
int comparision(char *str1, char *str2)
{
	int win;
	switch(*str1)
	{
		case 'C':
			if(*str2=='C')win=0;
			else if(*str2=='J')win=1;
			else win = -1;
			break;
		case 'J':
			if(*str2=='C')win=-1;
			else if(*str2=='J')win=0;
			else win=1;
			break;
		case 'B':
			if(*str2=='C')win=1;
			else if(*str2=='J')win=-1;
			else win=0;
			break;
		default:
			break;
	}
	return win;
}
void output(int s, int d, int f)
{
	if(s==d&&d==f)printf("%c", 'B');
	else if(s!=d&&d!=f)
	{
		if(s>d&&s>f)printf("%c", 'C');
		if(d>s&&d>f)printf("%c", 'J');
		if(f>s&&f>d)printf("%c", 'B');
	}
	else
	{
		if(s==d)
		{
			if(s>f)
			{
				printf("%c", 'C');
			}
			else
			{
				printf("%c", 'B');
			}
		}
		
		if(s==f)
		{
			if(s>d)
			{
				printf("%c", 'B');
			}
			else
			{
				printf("%c", 'J');
			}
		}
		if(d==f)
		{
			if(d>s)
			{
				printf("%c", 'B');
			}
			else
			{
				printf("%c", 'C');
			}
		}
	}
}
