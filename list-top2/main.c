#include<stdio.h>
#include<stdlib.h>
int *nowVisit;//正在访问或访问过的结点
int *top;//拓扑排序完毕的数组
int pos=0;

typedef struct Node{
	int col;
	struct Node* next;
}Node;

typedef struct Graph{
	Node** node;
	int size;
}Graph;

/*
 * 邻接表
 *
 * */
void add(Graph* graph,int cow,int col){
	if(graph->node[cow]!=NULL){
		Node *p=graph->node[cow];
		while(p->next){
			p=p->next;
		}
        Node* x=(Node*)malloc(sizeof(struct Node));
        x->col=col;
        x->next=NULL;
        p->next=x;
	}else{
		graph->node[cow]=(Node*)malloc(sizeof(struct Node));
		graph->node[cow]->col=col;
		graph->node[cow]->next=NULL;
	}

}




Graph* create(){
    int size=0;
    printf("输入节点数量:");
    scanf("%d",&size);
    Graph *graph=(Graph*)malloc(sizeof(struct Graph));
    graph->node=(Node**)calloc(size,sizeof(struct Node));
    graph->size=size;
    nowVisit=(int*)calloc(size,sizeof(int));
    top=(int*)calloc(size,sizeof(int));
    pos=size-1;
    printf("开始输入边,3 1则表示结点3到结点1之间有一条边,输入-1 -1表示结束\n");
    int cow=0,col=0;
    scanf("%d %d",&cow,&col);
    do{
        add(graph,cow,col);
        scanf("%d %d",&cow,&col);
    }while (cow!=-1&&col!=-1);
    return graph;
}

int DFS(int u,Graph *graph){
    nowVisit[u]=-1;
    Node*p=graph->node[u];
    while (p){
        if(nowVisit[p->col]==-1){
            return 0;
        }
        if (nowVisit[p->col]==0){
            if (DFS(p->col,graph)==0){
                return 0;
            }
        }
        p=p->next;
    }
    nowVisit[u]=1;
    top[pos--]=u;
    return 1;
}

void topSort(Graph *graph){
    for(int i=0;i<graph->size;i++){
        if(nowVisit[i]==0){
            if(DFS(i,graph)==0){
                printf("有环图,拓扑排序失败!");
                return;
            }
        }
    }
    printf("\n\n拓扑排序为: %d",top[0]);
    for (int j = 1; j < graph->size; ++j) {
        printf("->%d",top[j]);
    }
}


void showAov(Graph* graph){
    for (int i = 0; i < graph->size; ++i) {
        Node*p=graph->node[i];
        printf("%d",i);
        while (p){
            printf("->%d",p->col);
            p=p->next;
        }
        printf("\n");
    }
    printf("\n\n\n");
}

void gui(){

    int select=4;
    int state=0;
    do {
        printf("\n\n1.创建图\n");
        printf("2.拓扑排序并输出\n");
        printf("3.显示图\n");
        printf("4.退出\n");
        scanf("%d",&select);
        Graph* graph;
        switch (select){
            case 1: graph=create();
                state=1;
                system("cls");
                printf("创建成功");
                break;
            case 2: if (state==1)
                    topSort(graph);
                else{
                    system("cls");
                    printf("请先创建图\n");
                }
                break;
            case 3: if(state==1)
                    showAov(graph);
                else{
                    system("cls");
                    printf("请先创建图\n");
                }
                break;
            default:
                select=4;
        }

    }while (select!=4);

}
int main(){
	gui();
	printf("\n");
	system("pause");
    return 0;
}








