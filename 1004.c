#include "stdio.h"
#include "string.h"
#include "stdlib.h"
int main(int argc, char *argv[]){
	int i, n;
	long index1[1000], index2[1000];//储存所有grade
	struct student{
	char name[11];
	char id[11];
	int grade;
	struct student *next;
	}*p;
	char *minname=(char *)malloc(10*sizeof(char));//最小的学生信息要最后输出
	char *minid = (char *)malloc(10*sizeof(char));	//用与储存最小学生信息
	struct student *phead=NULL, *pb=NULL, *pmin=NULL, *pmax=NULL;	
	scanf("%d", &n);
	for(i=0;i<n;i++){
		p = (struct student *)malloc(sizeof(struct student));
		p->next = NULL;//尾节点指针初始化
		scanf("%s%s%d", p->name, p->id, &(p->grade));
		index1[i] = p->grade;
		index2[i] = p->grade;
		if(NULL==phead)phead = p;
		else pb->next = p;
		pb = p;
	}
	p->next = phead;//单循环链表
	for(i=1;i<n;i++){
		if(index1[i-1]>=index1[i])index1[i]=index1[i-1];//max
		if(index2[i-1]<=index2[i])index2[i]=index2[i-1];//min		
	}
	for(i=0;i<n;i++){
		if(index1[n-1]==p->grade)printf("%s %s\n", p->name, p->id);
		if(index2[n-1]==p->grade){
			minname = p->name;
			minid = p->id;
		}
		p = p->next;
	}
	printf("%s %s", minname, minid);
	return 0;
}
