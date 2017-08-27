#include "stdio.h"
#include "ctype.h"
//感谢大佬：https://github.com/a254476321/PAT-Basic/blob/master/1029.c
int main()
{
	int i=0, n=0, flag;
	char a[80]={0}, b[80]={0}, x;
	scanf("%s\n", a);
/*
------
scanf("%s", a);
键入enter,自动生成'\n'发现是空白符，而且缓存区非空，忽略并结束
x = getchar();收入缓存区'\n'
scanf("%s\n", a);键入'\n'的作用
An '\n' - or any whitespace character - in the format string consumes an entire (possibly empty) sequence of whitespace characters in the input. So the scanf only returns when it encounters the next non-whitespace character, or the end of the input stream  --stack overflow
------
*/
	x = getchar();
	while(a[i]!='\0')
	{
		if(x==a[i])
		{
			i++;
			x = getchar();
			continue;
		}
		flag = 0;
		for(int j=0;j<n;j++)
		{
			if(toupper(a[i]) == b[j])
			{
				flag = 1;
			}
		}
		if(!flag)
		{
			b[n] = toupper(a[i]);
			n++;
		}
		i++;
	}
	printf("%s", b);
	return 0;
}
