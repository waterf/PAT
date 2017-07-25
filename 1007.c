#include "stdio.h"
#include "math.h"
#include "stdbool.h"
int main(int argc, char *argv[]){
	int n, count;
	int prime1(int n);
	int prime2(int n);
	scanf("%d", &n);
	count = prime2(n);	
	printf("%d", count);
	return 0;
}

int prime1(int n){//未优化版
	int i,t=0;
	if(1==n)return 0;
	if(2==n)return 1;
	for(i=2;i<=sqrt(n);i++){
		if(0==n%i)t = 1;
	}
	if(t)return 0;
	else return 1;
}
int prime2(int n){//素数筛法（无2版）
	int  index=0, i, j=0, count=0;
	bool p[100000];//顶多100000当然还可以继续增加
	int p2[50000];
	for(i=2;i<=n;i++){//初始化
	        if(i % 2)p[i]=true;
		else p[i] = false;
	}	
	for(i=3;i<=n;i+=2){//判断是否是素数：优化1
		if(p[i]){
			for(j=i+i;j<=n;j+=i)p[j] = false;
		}
	}
	for(i=2;i<=n;i++){
		if(p[i]==true){
			p2[index] = i;
			index++;
		}
	}
	for(i=0;i<index-1;i++){
		if(p2[i+1]-p2[i]==2)count++;
	}

	return count;
}

