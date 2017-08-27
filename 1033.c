#include "stdio.h"
#include "ctype.h"

int main()
{
	char a[256]={0}, x;
	int index=0, n=0, flag=0, temp;
	x = getchar();
	while(x!='\n')
	{
		a[x] = 1;
		if('+'==x)flag = 1;
		x = getchar();
	}
	x = getchar();
	while(x!='\n')
	{
		temp = 0;
		if(!flag)
		{
			for(int i=0;i<256;i++)
			{
				if(a[i]&&toupper(x)==i)temp = 1;
			}
			if(!temp)printf("%c", x);
		}
		else
		{
			if(isupper(x))temp = 1;
			else
			{
				for(int i=0;i<256;i++)
				{
					if(a[i]&&toupper(x)==i)temp=1;
				}
				if(!temp)printf("%c", x);
			}
		}
		x = getchar();
	}
	printf("\n");
	return 0;
}
