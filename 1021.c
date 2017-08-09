#include "stdio.h"
#include "stdlib.h"
#include "string.h"
int main(int argc, char argv[])
{
	int a[10]={0};
	int i=0, temp;
	char *str = (char *)malloc(sizeof(char));
	scanf("%s", str);
	while(i<strlen(str))
	{
		a[*(str+i)-'0']++;
		i++;
	}
	for(i=0;i<10;i++)
	{
		if(a[i])printf("%d:%d\n", i, a[i]);
	}
	return 0;
}
