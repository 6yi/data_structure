#include<stdio.h>
#include<stdlib.h>
#define Maxnum 20
typedef int Wt;
typedef int DataType;
typedef int Vertex;
typedef int weightType;//Ȩ�� 

typedef struct Node *ptrNode; 
struct Node{
	int Nv;//������ 
	int Ne;//���� 
 	Wt G[Maxnum][Maxnum];
 	//DataType Data[Maxnum];
};
typedef ptrNode MGraph;

//�� 
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
	graph->G[e->v1][e->v2]=e->weight;//����ͼ
	//graph->G[e->v2][e->v1]=e->weight;//����ͼ�Ļ�˫��Ҫ��ֵ 		
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

//���ģʽ 
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

