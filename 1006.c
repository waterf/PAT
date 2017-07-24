#include "stdio.h"
int main(int argc, char *argv[]){
	int n, i=0, k;
	int a[3];
	scanf("%d", &n);
	while(n){
		a[i] = n%10;
		n /= 10;
		i++;
	}
	for(k=i-1;k>=0;k--){
		while(a[k]){
			if(k==2)printf("B");
			else if(k==1)printf("S");
			else break;
			a[k]--;
		}
	for(i=1;i<=a[k];i++)printf("%d", i);
	}

}
