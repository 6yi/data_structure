#include<stdio.h>
#include<stdlib.h>
typedef int data_type;

struct Node{
	Node* next;
	data_type data;
};

struct Queue{
	Node* head;
	Node* tail;
};


Queue create(){
	Queue* q=(Queue*)malloc(sizeof(Queue));
	//哨兵 
	Node* p=(Node*)malloc(sizeof(Node));
	p->data=999999;
	p->next=NULL;
	q->head=p;
	q->tail=p;
	return *q;	
}


void add(Queue* q,data_type data){
	Node* p=(Node*)malloc(sizeof(Node));
	p->data=data;
	p->next=NULL;
	q->tail->next=p;
	q->tail=p;
}


int pop(Queue* q){
	Node* p=q->head->next;
	if(p==NULL){
		printf("Queue is empty\n");
		return NULL;
	}else{
		q->head->next=p->next;
		return p->data;
	}
}

void show(Queue* q){
	
	Node* p=q->head->next;
	while(p){
		printf("%d  ",p->data);
		p=p->next;
	}
	printf("\n");
}



int main(){
	int x=1;
	Queue q;
	int z=0,c=NULL;
	while(x!=5){
		printf("1.创建队列\n");
		printf("2.入队\n");
		printf("3.出队\n");		
		printf("4.显示队列元素\n");		
		scanf("%d",&x);
		switch(x){
			case 1:
					q=create();
					break;
			case 2:
					printf("输入元素: "); 
					scanf("%d",&z);
					add(&q,z);
					break;
					
			case 3:			
				   c=pop(&q);
				   if(c!=NULL){
				   		printf("%d\n",c);
				   }				
					break;
			case 4:
					show(&q);		
			
		} 
	}
}
