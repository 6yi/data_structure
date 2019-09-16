#include<stdio.h>
#include<stdlib.h>
typedef int data_type;

typedef struct node *ptrNode;
struct node{
	data_type data;
	ptrNode next;	
};
typedef ptrNode Node;

typedef struct list *ptrlist;
struct list{
	Node head;
	Node tail;
	int length;
};
typedef ptrlist linklist;

void insert(data_type data,linklist list){
	Node p=(Node)malloc(sizeof(struct node));
	p->data=data;
	p->next=NULL;
	if(list->head==NULL){
		list->head=p;
		list->tail=p;
		list->length++;
	}else{
		list->tail->next=p;
		list->tail=p;
		list->length++;
	}
}

void show(linklist list){
	Node p=list->head;
	while(p){
		printf("%d  ",p->data);
		p=p->next;
	}
	printf("\n");
}

//插入指定位置 
void insert_pos(linklist list,int postion,data_type data){
	Node p=(Node)malloc(sizeof(struct node));
	p->data=data;
	if(postion>list->length){
		list->tail->next=p;
		list->tail=p;
		p->next=NULL;
	}else if(postion==0){
		p->next=list->head;
		list->head=p;
	}else{
		Node Nodep=list->head;
		for(int i=0;i<postion-1;i++){
			Nodep=Nodep->next;
		}
		p->next=Nodep->next;
		Nodep->next=p;
	}
	list->length++;	
}

int main(){
	linklist list=(linklist)malloc(sizeof(struct list));
	list->head=NULL;
	list->tail=NULL;
	list->length=0;
	for(int i=0;i<10;i++){
		insert(i,list);
	}
	show(list);
	insert_pos(list,2,99);
	show(list);
	return 0;	
} 
