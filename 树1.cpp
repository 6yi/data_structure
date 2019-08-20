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
//µÝ¹é±éÀú 
void pt(Node* tree){
	if(tree){
		pt(tree->left_node);
		printf("%d   ",tree->data);
		pt(tree->right_node);
	}
}
//¶ÑÕ»±éÀú
 


int main(){
	Node tree;
	tree.data=NULL;
	tree.left_node=NULL;
	tree.right_node=NULL;
 	int number[]={2,11,9,2,3,45,22,100};
 	for(int i=0;i<sizeof(number)/4;i++){
 		add_node(&tree,number[i]);
	 }
	pt(&tree); 
	 
}
