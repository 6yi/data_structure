#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int x;
	struct node* next;
}node;
typedef struct list{
	node* plist;
	node* last;
}list;
void add(int x,list *plist){
	node* p=(node*)malloc(sizeof(node));
	p->x=x;
	p->next=NULL;
	if(plist->last!=NULL){
		plist->last->next=p;
		plist->last=p;
	}else if(plist->plist==NULL){
		plist->plist=p;
		plist->last=p;
	}
}
void show(list *plist){
	node* foo;
	foo=plist->plist;
	while(foo!=NULL){
		printf("%d  ",foo->x);
		foo=foo->next;
	}
	printf("\n");
}
void insert(int number,node* foo,list *plist){
	number--;
	if(number==-1){
		foo->next=plist->plist;
		plist->plist=foo;
		return;
	}
	if(plist->plist==NULL){
		plist->plist=foo;
		plist->last=foo;
		foo->next=NULL;
	}else{
		node* p;
		p=plist->plist;
		int x=0;
		while(x!=number){
			p=p->next;
			x++;
		}
		foo->next=p->next;
		p->next=foo;
	}

}


int main(){
	
	list linklist;
	linklist.last=NULL;
	linklist.plist=NULL;
	
//	node newnode0;
//	newnode0.x=12;
//	insert(3,&newnode0,&linklist);
	
	for(int i=0;i<10;i++){
		add(i,&linklist);
	}
	node* foo;
	foo=linklist.plist;
//	while(foo!=NULL){
//		printf("%d",foo->x);
//		foo=foo->next;
//	}
	
	show(&linklist);
	
	node newnode;
	newnode.x=11;
	insert(0,&newnode,&linklist);
	
	show(&linklist);
} 
