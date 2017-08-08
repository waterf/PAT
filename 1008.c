#include "stdio.h"//不是这是谁出的弱智题？？？！！
#define N 200//不要带分号
int main(int argc, char *argv[]){
	int a[N];
	int i,j,m, n;
	scanf("%d%d", &n, &m);
	for(i=0;i<n;i++){
		scanf("%d", &a[i]);
	}
	for(j=0;j<m;j++){
		for(i=n+j-1;i>=0;i--){
			a[i+1] = a[i];
		}
	a[0] = a[n];
	}
	for(i=0;i<n;i++){
		printf("%d", a[i]);
		if((n-1)!=i)printf(" ");		
	}

	return 0;
}
