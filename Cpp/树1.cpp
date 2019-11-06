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
	return s->top==s->max_size;
}

bool push(stack *s,Node x){

	s->data[++(s->top)]=x;
	return true;
	
}

bool is_empty(stack *s){
	return s->top==-1;
}

Node* pop(stack *s){
	return &s->data[(s->top)--]; 	
}
//=================================================================================


//递归遍历 
void pt(Node* tree){
	if(tree){
		pt(tree->left_node);
		printf("%d   ",tree->data);
		pt(tree->right_node);
	}
}
//
////堆栈遍历
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



Node Create(int maxsize){
	Node tree;
	tree.data=NULL;
	tree.left_node=NULL;
	tree.right_node=NULL;
	printf("请依次输入节点:\n");
	int y=0;
	for(int i=0;i<maxsize;i++){
		scanf("%d",&y);
		add_node(&tree,y); 
	} 
	 return tree;
} 


int main(){

	int x=0;
	Node tree; 
 	do{
		printf("\n1.建立二叉树\n");
		printf("\n2.中序递归遍历\n"); 
		printf("\n3.中序堆栈遍历\n"); 
	 	printf("\n4.退出\n"); 
	 	scanf("%d",&x);
		int maxsize=0;
		switch(x){
			case 1: 
					
					printf("输入结点数量:");
					scanf("%d",&maxsize);
					tree=Create(maxsize);
					break;
			case 2:	pt(&tree);
					break;
			case 3:	stackpt(&tree,maxsize);
					break;
			case 4:x=-1;			
		}  			
	 
	}while(x>0); 
	return 0;
//	pt(&tree);
//	printf("\n");
//	stackpt(&tree,sizeof(number)/4);
//	printf("%d",find_pos(&tree,11)->data);
//	insert_node(&tree,900);
//	printf("%d",find_max(&tree)->data);
//	pt(&tree);
//	return 0;	 
}


