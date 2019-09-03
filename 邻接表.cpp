#include<stdio.h>
#include<stdlib.h>
#define MaxNum 10
typedef int vertex;
typedef int weight;

typedef struct AdjVnode *ptrVNode;
struct AdjVNode{
	vertex adjv;
	weight weight;
	ptrVNode next;
};


typedef struct Vnode{
	ptrVNode firstEdge;
}AdjList[MaxNum];


typedef struct GNode *ptrNode;
struct GNode{
	int Nv;
	int Ne;
	AdjList G;
};
typedef ptrNode LGraph;

LGraph Create(){
	vertex v=0;
	LGraph graph;
	graph=(LGraph)malloc(sizeof(struct GNode));
	scanf("%s",&v);
	graph->Nv=v;
	graph->Ne=0;
	for(int i=0;i<v;i++){
		graph->G[i].firstEdge=NULL;
	}
	
	return graph;	
}

struct 


void insertEdge(LGraph graph,Edge e){
	ptrVNode node;
	node=(ptrVNode)malloc(sizeof(struct AdjVnode));
	node->adjv=e->v2;
	node->weight=e->weight;
	
	graph->G[e->v1].firstEdge=node;
}
