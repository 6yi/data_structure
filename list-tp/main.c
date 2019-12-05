#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
	int col;
	struct Node* next;
}Node;

typedef struct Graph{
	Node** node;
	int *nums;//记录各节点初始的入度情况
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

Graph* createTest(){
    int size=12;
	Graph *graph=(Graph*)malloc(sizeof(struct Graph));
	graph->node=(Node**)calloc(size,sizeof(struct Node));
	graph->size=size;
    graph->nums=(int*)calloc(size, sizeof(int));
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
   	graph->nums[1]++;
   	add(graph,0,3);
    graph->nums[3]++;
   	add(graph,0,2);
    graph->nums[2]++;
   	add(graph,0,11);
    graph->nums[11]++;
   	add(graph,1,2);
    graph->nums[2]++;
   	add(graph,2,4);
    graph->nums[4]++;
	add(graph,2,6);
    graph->nums[6]++;
    add(graph,2,7);
    graph->nums[7]++;
    add(graph,3,4);
    graph->nums[4]++;
    add(graph,4,6);
    graph->nums[6]++;
    add(graph,8,11);
    graph->nums[11]++;
    add(graph,8,9);
    graph->nums[9]++;
    add(graph,8,10);
    graph->nums[10]++;
    add(graph,9,11);
    graph->nums[11]++;
    add(graph,10,5);
    graph->nums[5]++;
    add(graph,5,7);
    graph->nums[7]++;
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


Graph* create(){
    int size=0;
    printf("输入节点数量:");
    scanf("%d",&size);
    Graph *graph=(Graph*)malloc(sizeof(struct Graph));
    graph->node=(Node**)calloc(size,sizeof(struct Node));
    graph->size=size;
    graph->nums=(int*)calloc(size, sizeof(int));
    printf("开始输入边,3 1则表示节点3到节点1之间有一条边,输入-1 -1表示结束\n");
    int cow=0,col=0;
    scanf("%d %d",&cow,&col);
    do{
        add(graph,cow,col);
        graph->nums[col]++;
        scanf("%d %d",&cow,&col);
    }while (cow!=-1&&col!=-1);
    printf("AOV网生成成功\n");
    return graph;
}


void tp(Graph *graph){
    int size=graph->size;
    /*
     * 顶点入度数组
     * */
    int *nums=graph->nums;
    /*
     * 已访问节点数组
     * */
    int *visit=(int*)calloc(size, sizeof(int));
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

int main(){

	Graph* graph=createTest();
	showAov(graph);
	tp(graph);
	printf("\n");
	system("pause");

}








