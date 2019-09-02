#include<stdio.h>
#include<stdlib.h>
#define Maxnum 20
typedef int Wt;
typedef int DataType;
typedef int Vertex;
typedef int weightType;//权重 

typedef struct Node *ptrNode; 
struct Node{
	int Nv;//顶点数 
	int Ne;//边数 
 	Wt G[Maxnum][Maxnum];
 	//DataType Data[Maxnum];
};
typedef ptrNode MGraph;

//边 
typedef struct Enode *ptrEnode;
struct Enode{
	Vertex v1,v2;
	weightType weight;
	
};
typedef ptrEnode Edge;

MGraph CreateGraph(int num){
	Vertex V,W;
	MGraph graph;
	graph=(MGraph)malloc(sizeof(struct Node));
	
	graph->Nv=num;
	graph->Ne=0;
	
	for(V=0;V<graph->Nv;V++){
		for(W=0;W<graph->Nv;W++){
			graph->G[V][W]=0;
		}
	}
	return graph;
}

void insertEdge(MGraph graph,Edge e){	
	graph->G[e->v1][e->v2]=e->weight;//有向图
	//graph->G[e->v2][e->v1]=e->weight;//无向图的话双向都要赋值 		
}

MGraph BuildGraph(){
	MGraph graph;
	int Nv,Ne,i;
	Edge e;
	
	Nv=scanf("%d",&Nv);
	graph=CreateGraph(Nv);
	scanf("%d",&(graph->Ne));
	if(graph->Ne!=0){
		e=(Edge)malloc(sizeof(struct Enode));
		for(i=0;i<graph->Ne;i++){
			scanf("%d %d %d",&e->v1,&e->v2,&e->weight);
		}
		
	}
	return graph;
} 

//简洁模式 
int G[Maxnum][Maxnum],nv,ne;
void build(){
	int i,j,v1,v2,w;
	scanf("%d",&nv);
	for(i=0;i<nv;i++){
		for(j=0;j<nv;j++){
			scanf("%d %d %d",&v1,&v2,&w);
			G[v1][v2]=w;
			G[v2][v1]=w;
		}
	}
	for(i=0;i<nv;i++){
		for(j=0;j<nv;j++){
			printf("%d  ",G[i][j]);
		}
		printf("\n");
	}
	
}


int main(){
	
	build();
	return 0;
}

