#include "stdio.h"

int main()
{
	int a[123]={0}, b[123]={0}, flag=0, index[2]={0}, lack=0;
	char x;
	while(1)
	{
		x = getchar();
		if('\n'==x)break;
		index[0]++;
		a[x]++;
	}
	while(1)
	{
		x = getchar();
		if('\n'==x)break;
		index[1]++;
		b[x]++;
	}
	for(int i=0;i<123;i++)
	{
		if(b[i]&&b[i]>a[i])
		{
			flag=1;
			lack += b[i]-a[i];
		}
	}
	if(flag) printf("No %d", lack);
	else printf("Yes %d", index[0]-index[1]);
	return 0;
}