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
		printf("stack is full��");
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
		printf("ջ��Ԫ����ɾ��");
		return s->data[(s->top)--]; 
	}
	
}

void getTop(stack *s){
	if(is_empty(s)){
		printf("stack is empty!");
	}else{
		printf("ջ��Ԫ��Ϊ��%d",s->data[s->top]);
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
				s=CreateStack(100);
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
