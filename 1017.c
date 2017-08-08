#include "stdio.h"
#include "string.h"
#include "stdlib.h"

int main(int argc, char *argv[])
{
	int i=0, j=0, k;
	int index=0;
	int n, len;
	char *str1 = (char *)malloc(1000*sizeof(char));
	int b;//除数
	int q[1000], r;
	scanf("%s", str1);
	scanf("%d", &b);
	while(1)
	{  
		if(*str1-'0'<b&&strlen(str1)==1)
		{
			q[i] = 0;
			r = *str1-'0';
			break;
			i++;
		}
		if(*str1-'0'>b)
		{
			q[i] = (*str1-'0') / b;
			*str1 = (*str1-'0') % b + '0';
			if(strlen(str1)==1)
			{
				r = *str1 - '0';
				break;
			}
			i++;
		}
		else if(*str1 - '0'==b)
		{
			q[i] = 1;
			if(strlen(str1)==1)
			{
				r = 0;
				break;
			}
			else str1++;
			i++;
		}
		else
		{
			q[i] =  ((*str1-'0')*10 + *(str1+1)-'0') / b;
			index = ((*str1-'0')*10 + *(str1+1)-'0') % b;
			str1++;
			*str1 = index + '0';
			if(strlen(str1)==1)
			{
				r = index;
				break;
			}
			i++;
		}
	}
	for(j=0;j<=i;j++)printf("%d", q[j]);
	printf(" %d", r);
	return 0;
}
