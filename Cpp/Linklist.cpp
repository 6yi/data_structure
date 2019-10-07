#include<stdio.h>
#include<stdlib.h>
typedef int data_type;

//˫������ 
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

//����ָ��λ�� 
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
			printf("λ�ò��Ϸ�\n");
		}else if(pos==0){
			Node p=list->head;
			p->next->last=NULL;
			list->head=p->next;
			free(p);//�������� 
		}else if(pos==list->length-1){
			Node p=list->tail;
			p->last->next=NULL;
			list->tail=p->last; 
			free(p);//�������� 	
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
	printf("����ڵ�������\n");
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
			printf("%d������ĵ�%d��λ����\n",pos,i);
			return;
		}
		p=p->next;
	}
	printf("���������ڸ�Ԫ��\n");
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
		printf("1. �������Ա�\n");
		printf("2. ����һ��Ԫ�ص�ĩβ\n");
		printf("3. ɾ��ָ��λ��Ԫ��(�±�Ϊ0��ʼ)\n");
		printf("4. ����һ��Ԫ�ص�ָ��λ��(�±�Ϊ0��ʼ)\n");
		printf("5. ����ĳԪ������λ��(�±�Ϊ0��ʼ)\n");
		printf("6. �����������Ԫ��\n");
		printf("7. �����������Ԫ��\n");
		printf("8. �˳�\n");
		scanf("%d",&x);
		switch(x) {
			case 1:
				list=create();
				break;
			case 2:
				printf("��������Ԫ��: ");
				scanf("%d",&y);
				insert(y,list);
				break;
			case 3:
				printf("������Ҫɾ����Ԫ��λ��: ");
				scanf("%d",&z);
				delete_pos(list,z);
				break;
			case 4:
				printf("��������Ԫ���Լ�λ��)\n");
				printf("data:");
				scanf("%d",&y);
				printf("λ��:");
				scanf("%d",&z);
				insert_pos(list,z,y);
				break;
			case 5:
				printf("����Ҫ���ҵ�Ԫ�أ�\n");
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
