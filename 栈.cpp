#include<stdio.h>
#include<stdlib.h>
typedef struct stack{
	int* data;
	int top;
	int max_size; 
}stack;

stack CreateStack(int max_size){
	stack* s=(stack*)malloc(sizeof(stack));
	s->data=(int*)malloc(max_size*sizeof(int));
	s->top=-1;
	s->max_size=max_size;
	return *s;
}

bool is_full(stack *s){
	return s->top==s->max_size ;
}

bool push(stack *s,int x){
	if(is_full(s)){
		printf("stack is full£¡");
		return false; 
	}else{
		s->data[++(s->top)]=x;
		return true;
	}
}

bool is_empty(stack *s){
	return s->top==-1;
}

int pop(stack *s){
	
	if(is_empty(s)){
		printf("stack is empty!");
		return -1;
	}else{
		return s->data[(s->top)--]; 
	}
	
}

int main(){
	stack s=CreateStack(3);
	push(&s,1);
	push(&s,2);
	push(&s,5);
	printf("%d",pop(&s));
	printf("%d",pop(&s));
	
	
} 
