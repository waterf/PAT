#include "stdio.h"
#include "stdlib.h"
#include "string.h"
int main(int argc, char *argv[]){
	int n, count=0, j=0, i, k, t;
	int one = 0;
	int *ele[100];
	int index[100];//储存所有的输入的数字1-100
	int *temp;//储存关键数
	int *list_all(int n);
	int *_sort(int *temp);
	for(j=0;j<100;j++){
		ele[j] = (int *)malloc(100*sizeof(int));
		temp = (int *)malloc(100*sizeof(int));
	}
	scanf("%d", &n);
	for(i=0;i<n;i++){
		scanf("%d", &index[i]);
		ele[i] = list_all(index[i]);
	}
for(k=0;k<n;k++){
	t = 0;
	for(i=0;i<n;i++){ 
		j = 0;
		while(ele[i][j]!=0){
			if(ele[i][j]==index[k])t = 1;
			j++;
		}
	}
	if(!t){
	temp[one] = index[k];
	one++;
	}
}
_sort(temp);
i = 0;
while(i<one){
printf("%d", temp[i]);
if(i!=one-1)printf(" ");
i++;
}
	return 0;
}
int *list_all(int n){
        int count=0, i=0;
	int *ele = (int *)malloc(100*sizeof(int));
	for(i=0;;i++){
		if(0==n%2){
		n /= 2;
		count += 1;
		}
		else{
		n = (3*n+1)/2;
		count += 1;
		}
		if(1==n)break;
		ele[i] = n;
	}
	
return ele;
}

int *_sort(int *temp){
	int count;
	int i=0;
 	while(temp[i]!=0){
		if(temp[i]<temp[i+1]){
			count = temp[i];
			temp[i] = temp[i+1];
			temp[i+1] = count;
		}
		i++;
	}	 
	 return temp;
}
