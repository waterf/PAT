#include "stdio.h"
#include "string.h"
#include "stdlib.h"

int main(int argc, char *argv[])
{
	int index[3], i;
	int temp=0;//储存指数
	char string;
	char *str = (char *)malloc(11000*sizeof(char));
	scanf("%s", str);
	i=1;
	while(1)
	{
		if(*str=='+')index[0] = 1;//数字正负
		else index[0] = 2;
		if(*(str+i)=='+')
		{
			index[1] = 1;//大于小于1
			index[2] = i;//指数+-位置
			break;
		}
		if(*(str+i)=='-')
		{
			index[1] = 2;
			index[2] = i;
			break;
		}
		i++;
	}
	for (int i=index[2]+1;i<strlen(str);i++)
	{
		temp += *(str+i) - '0';
		if(i==strlen(str)-1)break;
		temp *= 10;
	}//取指数		
	if(2==index[0])printf("-");
	if(1==index[1])
	{
		if(temp<index[2]-4)//小数点有意temp
		{
			for(int j=0;j<temp;j++)
			{
				string = *(str+j+2);
				*(str+j+2) = *(str+j+3);
				*(str+j+3) = string;
			}
			for(int i=1;i<index[2]-1;i++)
			{
				printf("%c", *(str+i));
			}
		}
		else if(temp==index[2]-4)
		{
			*(str+2) = *(str+1);
			for(int j=2;j<index[2]-1;j++)
			{
				printf("%c", *(str+j));
			}
		}
		else
		{
			*(str+2) = *(str+1);
			for(int j=index[2]-1;j<temp+3;j++)
			{
				*(str+j) = '0';
			}
			for(int j=2;j<3+temp;j++)
			{
				printf("%c", *(str+j));
			}
		}
	}
	if(2==index[1])
	{
		*(str+2) = *(str+1);
		for(int i=0;i<temp;i++)
		{
			if(0==i)printf("0.");
			else printf("0");
		}
		for(int i=2;i<index[2]-1;i++)
		{
			printf("%c", *(str+i));
		}
	}
	return 0;
}
