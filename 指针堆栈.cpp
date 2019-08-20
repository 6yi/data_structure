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
		return x;
	}
}

int main(){
	
	stack s=CreateStack();
	push(&s,3);
	push(&s,4);
	printf("%d",pop(&s));
		printf("%d",pop(&s));
			printf("%d",pop(&s));
				printf("%d",pop(&s));
	
}
