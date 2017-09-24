#include "stdio.h"

int main()
{
	int a[2], b[2], c[2], s[2], sum=0, result[3]={0};
	scanf("%d.%d.%d", &a[0], &b[0], &c[0]);
	scanf("%d.%d.%d", &a[1], &b[1], &c[1]);
	s[0] = a[0]*17*29 + b[0]*29 + c[0];
	s[1] = a[1]*17*29 + b[1]*29 + c[1];
	sum = s[1] - s[0];
	result[0] =  (sum - sum%29 - 29*((sum-sum%29)/29)%17)/(17*29);
	result[1] =  ((sum-sum%29)/29)%17;
	result[2] = sum%29;
	printf("%d.%d.%d", result[0], result[1]<0&&result[0]!=0 ?-result[1]:result[1], result[2]<0&&result[1]!=0 ?-result[2]:result[2]);
	return 0;
}
