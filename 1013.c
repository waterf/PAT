#include "stdio.h"
int  main(int argc, char *argv[]){
  int m, n;
  int i, j;
  int index=0;
  int p2[20000]={0};
  int *prime(int n, int *p2);
  scanf("%d%d", &m, &n);
  prime(140000, p2);
  for(i=m-1;i<=n-1;i++){
	  index++;
	  printf("%d", p2[i]);
	  if(!(index%10)&&i!=(n-1)){
		  printf("\n");
		  continue;
	  }
	  if(i!=n-1)printf(" ");
  }
  return 0;
}
int *prime(int n, int *p2){
    int p1[150000]={0};
	int i, j, index=0;
	p1[2]=1;
	for(i=3;i<=n;i+=2){
		p1[i]=1;
	}
	for(i=3;i<=n;i+=2)for(j=i+i;j<=n;j+=i)p1[j]=0;
	for(i=2;i<=n;i+=1)
	  if(p1[i]){
		p2[index]=i;
		index++;
		if(index==10001)break;
	  }
	return p2;
}
