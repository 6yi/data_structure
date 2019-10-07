#include<stdio.h>
#include<stdlib.h>
#define MaxNum 10
typedef int vertex;
typedef int weight;

typedef struct AdjVNode *ptrVNode;
struct AdjVNode{
	vertex ad;
	weight weight;
	ptrVNode next;
};

typedef struct Vnode{
	ptrVNode firstEdge;
}AdjList;

typedef struct GNode *ptrNode;
struct GNode{
	int Nv;
	int Ne;
	AdjList* G;
};
typedef ptrNode LGraph;

LGraph Create(){
	vertex v=0;
	LGraph graph;
	graph=(LGraph)malloc(sizeof(struct GNode));
	scanf("%s",&v);
	graph->Nv=v;
	graph->Ne=0;
	graph->G=(AdjList*)malloc(sizeof(struct Vnode)*MaxNum);
	for(int i=0;i<v;i++){
		graph->G[i].firstEdge=(ptrVNode)malloc(sizeof(struct Vnode));
	}
	printf("create  ok\n");	
	return graph;	
}

typedef struct enode *Enode;
struct enode{
	vertex v1;
	vertex v2;
	weight weight;
};
typedef Enode Edge;


void insertEdge(LGraph graph,Edge e){
	ptrVNode node;
	printf("insert ready\n");
	node=(ptrVNode)malloc(sizeof(struct AdjVNode));
	node->ad=e->v2; 
	node->weight=e->weight;
	node->next=graph->G[e->v1].firstEdge;
	graph->G[e->v1].firstEdge=node;
	printf("insert ok\n");
}

int main(){
	LGraph graph=Create();
	Edge e=(Edge)malloc(sizeof(struct enode));
	e->v1=0;
	e->v2=1;
	e->weight=1;
	Edge h=(Edge)malloc(sizeof(struct enode));
	h->v1=1;
	h->v2=0;
	h->weight=1;
	 
	insertEdge(graph,e);
	insertEdge(graph,h);
	
	return 0;
}









