#include<stdio.h>
#include<stdlib.h>

typedef struct node *ptrGraph;
typedef struct node{
	int Nv;//±ß 
	int Ne;//µã 
	int **v;
};
typedef ptrGraph Graph; 

int main(){
	int nv;
	int ne;
	Graph graph=(Graph)malloc(sizeof(struct node));
	scanf("%d %d",&ne,&nv);
	graph->Nv=nv;
	graph->Ne=ne;
	graph->v=(int**)malloc(sizeof(int)*ne);
	
	int newv1,newv2,newW;
	for(int i=0;i<nv;i++){
		scanf("%d %d %d",&newv1,&newv2,&newW);
		graph->v[newv1]=(int*)malloc(sizeof(int)*ne);
		graph->v[newv1][newv2]=newW;
	}
	
	return 0;
	
} 
