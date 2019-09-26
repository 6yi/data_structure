#include<stdio.h>
#include<stdlib.h>
typedef struct stack{
	int data;
	struct stack* next; 
}stack;

stack CreateStack(){
	stack* s=(stack*)malloc(sizeof(stack));
	s->next=NULL;
	return *s;
}

bool is_empty(stack *s){
	return s->next==NULL;
}

bool push(stack *s,int x){
	stack *p=(stack*)malloc(sizeof(stack));
	p->data=x;
	p->next=s->next;
	s->next=p;
	return true;
}

int pop(stack *s){
	if(is_empty(s)){
		printf("stack is empty");
		return -1;
	}else{
		stack *firstCell=s->next;
		int x=firstCell->data;
		s->next=firstCell->next;
		free(firstCell);
		printf("ջ��Ԫ����ɾ��");
		return x;
	}
}


void getTop(stack *s){
	if(is_empty(s)){
		printf("stack is empty");
	}else{
		printf("ջ��Ԫ��Ϊ��%d",s->next->data);
	}
} 

void Gui(){
	int x=0,y=0,is=0;
	stack s;
	do{
		printf("\n\n     Menu\n");
		printf("1. ��ʼ��˳��ջ\n");
		printf("2. ����һ��Ԫ��\n");
		printf("3. ɾ��ջ��\n");
		printf("4. ȡ��ջ��\n");
		printf("5. �˳�\n");
		scanf("%d",&x);
		switch(x){
			case 1:
				s=CreateStack();
				break;
			case 2:
				printf("data:");
				scanf("%d",&y);	
				push(&s,y);
				break;
			case 3:
				pop(&s);
				break;
			case 4:
				getTop(&s);
				break;
			case 5:
				is=1;	
						
		} 
	}while(is==0);
	
}


int main(){
	
	Gui();
	return 0;
	
}
