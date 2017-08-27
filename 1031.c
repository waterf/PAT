#include "stdio.h"
#include "stdlib.h"
#include "ctype.h"
//atoi isdigit
char sw(int sum)
{
	if(0==sum)return '1';
	else if(1==sum)return '0';
	else if(2==sum)return 'X';
	else if(3==sum)return '9';
	else if(4==sum)return '8';
	else if(5==sum)return '7';
	else if(6==sum)return '6';
	else if(7==sum)return '5';
	else if(8==sum)return '4';
	else if(9==sum)return '3';
	else  return '2';
}
int main()
{
	int n, i, j, sum=0, flag=0;
	char *s[n];
	int a[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
	scanf("%d", &n);
	for(i=0;i<n;i++)
	{
		s[i] = (char *)malloc(18*sizeof(char));
		scanf("%s", s[i]);
	}
	for(i=0;i<n;i++)
	{
		sum = 0;
		for(j=0;j<17;j++)
		{
			if(s[i][j]<'0'&&s[i][j]>'9')
			{
				flag = 1;
				printf("%s\n", s[i]);
				break;
			}
			sum += (s[i][j]-'0')*a[j];
		}
		sum %= 11;
		if(s[i][17]!=sw(sum))
		{
			flag = 1;
			printf("%s\n", s[i]);
		}
	}
	if(!flag)printf("All passed");
	return 0;
}
