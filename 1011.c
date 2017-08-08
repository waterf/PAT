#include "stdio.h"
int main(int argc, char *argv[]){
   int n, i, j;
   long A[10], B[10], C[10];
   scanf("%d", &n);
	   for(j=0;j<n;j++){
		   scanf("%ld%ld%ld", &A[j], &B[j], &C[j]);
	   }
	   for(i=0;i<n;i++){
		   if(A[i]+B[i] > C[i])printf("Case #%d: true\n", i+1);
		   else printf("Case #%d: false\n", i+1);
	   }
   return 0;

}
