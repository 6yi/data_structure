#include<stdio.h>
#include<stdlib.h>
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

Graph* create(int size){
	Graph *graph=(Graph*)malloc(sizeof(struct Graph));
	graph->node=(Node**)calloc(size,sizeof(struct Node));
	graph->size=size;
	/*
	 * 测试数据
        0->1->3->2->11
        1->2
        2->4->4->6->7
        3->4
        4->6
        5->7
        6
        7
        8->11->9->10
        9->11
        10->5
        11
	*/
   	add(graph,0,1);
   	add(graph,0,3);
   	add(graph,0,2);
   	add(graph,0,11);
   	add(graph,1,2);
   	add(graph,2,4);
	add(graph,2,4);
	add(graph,2,6);
    add(graph,2,7);
    add(graph,3,4);
    add(graph,4,6);
    add(graph,8,11);
    add(graph,8,9);
    add(graph,8,10);
    add(graph,9,11);
    add(graph,10,5);
    add(graph,5,7);
	for(int i=0;i<size;i++){
		Node*p=graph->node[i];
        printf("%d",i);
		while(p){
			printf("->%d",p->col);
			p=p->next;
		}
		printf("\n");
	}
    return graph;
}

void tp(Graph *graph){
    int size=graph->size;
    /*
     * 顶点入度数组
     * */
    int *nums=(int*)calloc(size, sizeof(int));
    /*
     * 已访问节点数组
     * */
    int *visit=(int*)calloc(size, sizeof(int));

    for (int i = 0; i < size; ++i) {
        Node*p=graph->node[i];
        while (p){
            nums[p->col]++;
            p=p->next;
        }
    }
    for(int i=0;i<size;i++){

        int now=-1;
        for(int j=0;j<size;j++){
            if(nums[j]==0&&visit[j]==0){
                now=j;
                visit[j]=1;

                break;
            }
        }
        Node*p=graph->node[now];
        while (p){
            nums[p->col]--;
            p=p->next;
        }
        printf("%d ",now);
    }
}


int main(){
	Graph* graph=create(12);
	tp(graph);
	system("pause");
}








