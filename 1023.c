#include "stdio.h"

int main(int argc, char *argv[])
{
	int a[10], i=0, j=0, k=0;
	int index = 0;
	for(i=0;i<10;i++)
		scanf("%d", &a[i]);
	for(i=0;i<10;i++)
	{
		if(a[i])
		{
			if(a[i]&&i!=0)
			{
				for(j=0;j<a[i];j++)
				{
					printf("%d", i);
					if(!index&&j==0)
					{
						for(k=0;k<a[0];k++)printf("%d", 0);
					}
				}
				index = 1;
			}
		}
		else
		{
			if(a[i])
			{
				for(j=0;j<a[i];j++)printf("%d", i);
			}
		}
	}
	return 0;
}
