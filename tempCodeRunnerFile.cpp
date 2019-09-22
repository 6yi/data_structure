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

void delete_pos(linklist list,int pos){

		if(pos>list->length){
			printf("位置不合法,大于链表长度");
		}else if(pos==0){
			list->head=list->head->next;
			list->length--;
		}else{
			Node p=list->head;
			for (int i = 0; i < list->length; i++)
			{
					p=p->next;
			}
				Node rubbish=p->next;
				p->next=p->next->next;
				free(rubbish);
		}

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

void Gui() {
	linklist list=NULL;
	data_type x=0,y=0,z=0,po=-1;
	int isprime=1;
	do {
		printf("\n\n     Menu\n");
		printf("1. 创建线性表\n");
		printf("2. 插入一个元素到末尾\n");
		printf("3. 删除指定位置元素\n");
		printf("4. 插入一个元素到指定位置\n");
		printf("5. 查找某元素所在位置\n");
		printf("6. 输出所有元素\n");
		printf("7. 结束\n");
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
				printf("输入插入的元素以及位置\n");
				printf("data:");
				scanf("%d",&y);
				printf("位置:");
				scanf("%d",&z);
				insert_pos(list,z,y);
				break;
			case 7:
				isprime=0;
		}

	} while(isprime==1);
}





int main(){
	Gui();
	return 0;	
} 
