#include "stdio.h"
#include "math.h"
#define CLK_TCK 100
int main()
{
	int c1, c2;
	int hour=0, minute=0, second=0;
	int time;
	scanf("%d%d", &c1, &c2);
	time = floor(1.0*(c2-c1)/CLK_TCK+0.5);
	hour = time / 3600;
	time -= hour*3600;
	minute = time / 60;
	time -= minute*60;
	second = time;
	printf("%02d:%02d:%02d", hour, minute, second);
	return 0;
}
