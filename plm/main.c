#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int col;//结点
    int v;  //权值
    struct Node* next;
}Node;

typedef struct Graph{
    Node** node;

    int size;
}Graph;

//往图中插入结点
void add(Graph* graph,int cow,int col,int v){
    if(graph->node[cow]!=NULL){
        Node *p=graph->node[cow];
        while(p->next){
            p=p->next;
        }
        Node* x=(Node*)malloc(sizeof(struct Node));
        x->col=col;
        x->v=v;
        x->next=NULL;
        p->next=x;
    }else{
        graph->node[cow]=(Node*)malloc(sizeof(struct Node));
        graph->node[cow]->col=col;
        graph->node[cow]->v=v;
        graph->node[cow]->next=NULL;
    }

}

void plm(Graph* graph){
    int *nums=(int *)calloc(graph->size, sizeof(int));
    int *plms=(int *)calloc(graph->size, sizeof(int));
    int *rootpos=(int *)calloc(graph->size, sizeof(int));
    int tree[999]={0};
    rootpos[0]=1;
    plms[0]=0;
    int count=1;
    nums[0]=1;
    while (count<graph->size){
        int min=9999;
        int pos=-1;
        for (int j = 0; j < graph->size; ++j) {
            if (nums[j] == 1) {
                Node *p = graph->node[j];
                while (p) {
                    if (p->v < min && nums[p->col] != 1) {
                        min = p->v;
                        pos = p->col;
                    }
                    p = p->next;
                }
            }
        }
        if (pos!=-1){
            rootpos[]
            nums[pos]=1;
            plms[count++]=pos;
        }
    }
    for (int k = 0; k < graph->size; ++k) {
        printf("%d->",plms[k]);
    }

}


Graph* create(){
    int size=6;
//    printf("输入节点数量:");
//    scanf("%d",&size);
    Graph *graph=(Graph*)malloc(sizeof(struct Graph));
    graph->node=(Node**)calloc(size,sizeof(struct Node));
    graph->size=size;
//    printf("开始输入边,3 1则表示结点3到结点1之间有一条边,输入-1 -1表示结束\n");
    int cow=0,col=0,v=0;
//    scanf("%d %d %d",&cow,&col,&v);
//    do{
//        add(graph,cow,col,v);
//        scanf("%d %d",&cow,&col);
//    }while (cow!=-1&&col!=-1);
    add(graph,0,1,6);
    add(graph,0,2,1);
    add(graph,0,3,5);
    add(graph,1,2,5);
    add(graph,1,4,3);
    add(graph,2,4,6);
    add(graph,2,5,4);
    add(graph,2,3,5);
    add(graph,3,5,2);
    add(graph,4,5,6);
    plm(graph);
    return graph;
}

int main() {
    create();
    system("pause");
    return 0;
}