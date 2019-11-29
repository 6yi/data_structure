#include<stdio.h>
#include<stdlib.h>
struct Node{
	int col;
	Node* next;
};
struct Graph{
	Node** node;
	int size;
};

void add(Graph* graph,int cow,int col){
	if(graph->node[cow]!=NULL){
		Node*p=graph->node[cow];
//		printf("%d->%d",cow,col);
		while(p){
			p=p->next;
		}
		p=(Node*)malloc(sizeof(struct Node));
		p->col=col;
		p->next=NULL;
//		printf("%d->%d\n",cow,p->col);
	}else{
		graph->node[cow]=(Node*)malloc(sizeof(struct Node));
		graph->node[cow]->col=col;
		graph->node[cow]->next=NULL;
//		printf("%d",graph->node[cow]->col);
	}

}

void create(int size){
	Graph *graph=(Graph*)malloc(sizeof(struct Graph));
	graph->node=(Node**)calloc(size,sizeof(struct Node));
//	for(int i=0;i<size;i++){
//		graph->node[i]=NULL;
//	}
	graph->size=size;
	/*
	graph[0][1]=1;
	graph[0][3]=1;
	graph[1][6]=1;
	graph[3][6]=1;
	graph[2][1]=1;
	graph[2][4]=1;
	graph[4][5]=1;
	graph[5][6]=1;
	²âÊÔÊý¾Ý 
	*/
   	add(graph,0,1);
   	add(graph,0,3);
   	add(graph,1,6);
   	add(graph,3,6);
   	add(graph,2,1);
   	add(graph,2,4);
	add(graph,4,5);
	add(graph,5,6);
//	printf("%d->%d  ",0,graph->node[0]->next->col);
	for(int i=0;i<size;i++){
		Node*p=graph->node[i];
		while(p){
			printf("%d->%d  ",i,p->col);
			p=p->next;
		} 
		printf("\n");
	}
}


void tp(Graph *graph){
	
	
	
}

int main(){
	create(5);
}
