#include<stdio.h>
#include<stdlib.h>
#define type_data int
typedef struct Node{
	type_data data;
	struct Node* left_node;
	struct Node* right_node;
}Node;
void add_node(Node* tree,type_data data){
	if(tree->data==NULL){
		tree->data=data;
	}else{
		if(tree->data>data){
			if(tree->left_node==NULL){
	  			tree->left_node=(Node*)malloc(sizeof(Node));
				tree->left_node->data=data;
				tree->left_node->left_node=NULL;
				tree->left_node->right_node=NULL;
			}else{
				add_node(tree->left_node,data);
			}
		}else{
			if(tree->right_node==NULL){
				tree->right_node=(Node*)malloc(sizeof(Node));
				tree->right_node->data=data;
				tree->right_node->right_node=NULL;
				tree->right_node->left_node=NULL;
			}else{
				add_node(tree->right_node,data);
			}
		}
	}
}

//=================================================================================
typedef struct stack{
	Node* data;
	int top;
	int max_size; 
}stack;

stack CreateStack(int max_size){
	stack* s=(stack*)malloc(sizeof(stack));
	s->data=(Node*)malloc(max_size*sizeof(Node));
	s->top=-1;
	s->max_size=max_size;
	return *s;
}

bool is_full(stack *s){
	return s->top==s->max_size ;
}

bool push(stack *s,Node x){
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

Node* pop(stack *s){
	return &s->data[(s->top)--]; 	
}
//=================================================================================


//µÝ¹é±éÀú 
void pt(Node* tree){
	if(tree){
		pt(tree->left_node);
		printf("%d   ",tree->data);
		pt(tree->right_node);
	}
}

//¶ÑÕ»±éÀú
void stackpt(Node* tree,int max_size){
	stack s=CreateStack(max_size);
	while(tree||!is_empty(&s)){
		while(tree){
			push(&s,*tree);
			tree=tree->left_node;
		}
		if(!is_empty(&s)){
			tree=pop(&s);
			printf("%d   ",tree->data);
			tree=tree->right_node;
		}
	}
} 
//=========================================================================================


Node* find_pos(Node* tree,type_data data){
	while(tree){
		if(tree->data==data){
			return tree;
		}else if(tree->data<data){
			tree=tree->right_node;
		}else{
			tree=tree->left_node;
		}
	}
	return NULL;
}


Node* find_max(Node* tree){
	if(tree==NULL){
		return NULL;
	}
	
	while(tree->right_node){
		tree=tree->right_node;
	}
	return tree;
}


Node* insert_node(Node* tree,type_data data){
	if(tree==NULL){
		tree=(Node*)malloc(sizeof(Node));
		tree->data=data;
		tree->left_node=tree->right_node=NULL;
	}else{
		if(data>tree->data){
			tree->right_node=insert_node(tree->right_node,data);
		}else{
			tree->left_node=insert_node(tree->left_node,data);
		}
	}
	return tree;
}
int main(){
	Node tree;
	tree.data=NULL;
	tree.left_node=NULL;
	tree.right_node=NULL;
 	int number[]={2,11,9,2,3,45,22,100};
 	for(int i=0;i<sizeof(number)/4;i++){
 		add_node(&tree,number[i]);
	 }
//	pt(&tree);
//	printf("\n");
//	stackpt(&tree,sizeof(number)/4);
//	printf("%d",find_pos(&tree,11)->data);
	insert_node(&tree,900);
//	printf("%d",find_max(&tree)->data);
	pt(&tree);
	return 0;	 
}

