#include<stdio.h>
#include<stdlib.h>
typedef int data_type;

//双向链表 
typedef struct node *ptrNode;
struct node{
	data_type data;
	ptrNode next;
	ptrNode last;	
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
	p->last=NULL;
	if(list->head==NULL){
		list->head=p;
		list->tail=p;
	}else{
		p->last=list->tail;
		list->tail->next=p;
		list->tail=p;
	}
	list->length++;
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
	p->next=NULL;
	p->last=NULL;
	
	if(postion>=list->length){
		p->last=list->tail;
		list->tail->next=p;
		list->tail=p;
	}else if(postion==0){
		p->next=list->head;
		list->head->last=p;
		list->head=p;
	}else{
		Node n=list->head;
		for(int i=0;i<postion-1;i++){
			n=n->next;
		}
		p->last=n;
		n->next->last=p;
		p->next=n->next;
		n->next=p;
	}
	
	list->length++;	
}

void delete_pos(linklist list,int pos){
		
		
		if(pos>list->length-1){
			printf("位置不合法\n");
		}else if(pos==0){
			Node p=list->head;
			p->next->last=NULL;
			list->head=p->next;
			free(p);//回收垃圾 
		}else if(pos==list->length-1){
			Node p=list->tail;
			p->last->next=NULL;
			list->tail=p->last; 
			free(p);//回收垃圾 	
		}else{
			Node p=list->head;
			for(int i=0;i<pos-1;i++){
				p=p->next;
			}
			Node n=p->next;
			n->next->last=p;
			p->next=n->next;
			free(n); 
		}	
		list->length--;
}


linklist create(){
	linklist list=(linklist)malloc(sizeof(struct list));
	list->head=NULL;
	list->tail=NULL;
	list->length=0;
	printf("输入节点数量：\n");
	int sum=0,x=0;
	scanf("%d",&sum);
	for(int i=0;i<sum;i++){
		printf("data: ");
		scanf("%d",&x);
		insert(x,list);
	}
	return list;
}

void find(linklist list,int pos){
	Node p=list->head;
	for (int i = 0; i < list->length; i++)
	{
		if (p->data==pos)
		{
			printf("%d在链表的第%d号位置上\n",pos,i);
			return;
		}
		p=p->next;
	}
	printf("此链表不存在该元素\n");
}

void show2(linklist list){
		Node p=list->tail;
		while(p){
			printf("%d  ",p->data);
			p=p->last;
		}
}

void Gui() {
	linklist list=NULL;
	data_type x=0,y=0,z=0,po=-1;
	int isprime=1;
	do {
		printf("\n\n     Menu\n");
		printf("1. 创建线性表\n");
		printf("2. 插入一个元素到末尾\n");
		printf("3. 删除指定位置元素(下标为0开始)\n");
		printf("4. 插入一个元素到指定位置(下标为0开始)\n");
		printf("5. 查找某元素所在位置(下标为0开始)\n");
		printf("6. 正向输出所有元素\n");
		printf("7. 逆向输出所有元素\n");
		printf("8. 退出\n");
		scanf("%d",&x);
		switch(x) {
			case 1:
				list=create();
				break;
			case 2:
				printf("输入插入的元素: ");
				scanf("%d",&y);
				insert(y,list);
				break;
			case 3:
				printf("输入所要删除的元素位置: ");
				scanf("%d",&z);
				delete_pos(list,z);
				break;
			case 4:
				printf("输入插入的元素以及位置)\n");
				printf("data:");
				scanf("%d",&y);
				printf("位置:");
				scanf("%d",&z);
				insert_pos(list,z,y);
				break;
			case 5:
				printf("输入要查找的元素：\n");
				scanf("%d",&y);
				find(list,y);
				break;	
			case 6:
				show(list);
				break;	
			case 7:
				show2(list);
				break;
			case 8:
				isprime=0;	
		}

	} while(isprime==1);
}


int main(){
	Gui();
	return 0;	
} 
