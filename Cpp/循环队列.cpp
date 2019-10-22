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
		printf("\nError:ѭ��������!\n");
		return false;
	}
	Q->data[Q->rear] = x;
	Q->rear = (Q->rear+1) % MAXSIZE;
	return true;
} 



datatype DeQueue(SeqQueue *Q){
	datatype x ;
	if(Q->front == Q->rear){
		printf("\nError:ѭ������Ϊ��!������ɾ������!\n");
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
		printf("\nError:ѭ������Ϊ��!\n");
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
	
		printf("ѭ�����л�������--���˵�\n");
		printf("1�������ѭ������\n");
		printf("2���ж϶ӿ�\n");
		printf("3�����\n");
		printf("4������\n");
		printf("5����ʾѭ������\n");
		printf("6��������������\n");
		printf("======================\n");
		printf("��ѡ��:");
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
					printf("����Ϊ��!\n");
				}else{
					printf("���в�Ϊ��!\n");
				}
				break;
			case 3:
				printf("������Ҫ�����Ԫ�صĸ���:");
				scanf("%d",&number);
				for(count=1 ; count <= number ; count++){
					printf("����������Ҫ�����Ԫ��:");
					fflush(stdin);
					scanf("%d",&i);
					EnQueue(Q,i);	
				}
				display(Q);
				break;
			case 4:
				i = DeQueue(Q);
				printf("���ӵ�Ԫ��Ϊ:%d\n",i);
				display(Q);	
				break;
			case 5:
				display(Q);
				break;
		}
	printf("ѭ�����л�������--���˵�\n");
	printf("1�������ѭ������\n");
	printf("2���ж϶ӿ�\n");
	printf("3�����\n");
	printf("4������\n");
	printf("5����ʾѭ������\n");
	printf("6��������������\n");
	printf("======================\n");
	printf("��ѡ��:");
	scanf("%d",&choice);
	printf("\n");	
	}while(choice != 6);
}

