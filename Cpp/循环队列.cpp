#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 20

typedef int datatype;

typedef struct{ 
	datatype data[MAXSIZE];
	int front;
	int rear;
}SeqQueue;


SeqQueue *InitQueue(){
	SeqQueue *p;
	p = (SeqQueue*)malloc(sizeof(SeqQueue));
	p->front = p->rear = 0;
	return p;
}


int QueueEmpty(SeqQueue *Q){
	return(Q->front == Q->rear);
}


int EnQueue(SeqQueue *Q,datatype x){
	if((Q->rear+1)%MAXSIZE == Q->rear){
		printf("\nError:循环队列满!\n");
		return false;
	}
	Q->data[Q->rear] = x;
	Q->rear = (Q->rear+1) % MAXSIZE;
	return true;
} 



datatype DeQueue(SeqQueue *Q){
	datatype x ;
	if(Q->front == Q->rear){
		printf("\nError:循环队列为空!不能做删除操作!\n");
		return false;
	}
	x = Q->data[Q->front];
	Q->front = (Q->front+1) % MAXSIZE;
	return x;
} 


void display(SeqQueue *Q){
	int s;
	s = Q->front;
	if(Q->front == Q->rear){
		printf("\nError:循环队列为空!\n");
	}else{
		while(s != Q->rear){
			printf("->%d",Q->data[s]);
			s = (s+1) % MAXSIZE;
		}
	}
	printf("\n");
} 




int main(int argc,const char *argv[]){
	SeqQueue *Q;
	int count;
	int choice,number;
	int i;
	
		printf("循环队列基本操作--主菜单\n");
		printf("1、构造空循环队列\n");
		printf("2、判断队空\n");
		printf("3、入队\n");
		printf("4、出队\n");
		printf("5、显示循环队列\n");
		printf("6、结束程序运行\n");
		printf("======================\n");
		printf("请选择:");
		scanf("%d",&choice);
		if(choice == 6){
			return 0;
		}
		printf("\n");
	do{
		switch(choice){
			case 1:
				 Q = InitQueue();
				break;
			case 2:
				i = QueueEmpty(Q);
				if(i == 1){
					printf("队列为空!\n");
				}else{
					printf("队列不为空!\n");
				}
				break;
			case 3:
				printf("请输入要插入的元素的个数:");
				scanf("%d",&number);
				for(count=1 ; count <= number ; count++){
					printf("请依次输入要插入的元素:");
					fflush(stdin);
					scanf("%d",&i);
					EnQueue(Q,i);	
				}
				display(Q);
				break;
			case 4:
				i = DeQueue(Q);
				printf("出队的元素为:%d\n",i);
				display(Q);	
				break;
			case 5:
				display(Q);
				break;
		}
	printf("循环队列基本操作--主菜单\n");
	printf("1、构造空循环队列\n");
	printf("2、判断队空\n");
	printf("3、入队\n");
	printf("4、出队\n");
	printf("5、显示循环队列\n");
	printf("6、结束程序运行\n");
	printf("======================\n");
	printf("请选择:");
	scanf("%d",&choice);
	printf("\n");	
	}while(choice != 6);
}

