#include<stdio.h>
#include<stdlib.h>
typedef int Graph;
Graph **graph;//AOV网
int *nowVisit;//正在访问或访问过的结点
int *top;//拓扑排序完毕的数组
int pos=0;
int size=0;

int dfs(int u){
    nowVisit[u]=-1;
    for(int i=1;i<size;i++){
        if(graph[u][i]==1){
            if(nowVisit[i]==-1){
                return 0;
            }
            if(nowVisit[i]==0){
                if(dfs(i)==0){
                    return 0;
                }
            }
        }
    }
    nowVisit[u]=1;
    top[pos--]=u;
    return 1;
}


void create(){
    printf("输入结点数量:");
    scanf("%d",&size);
    graph=(Graph**)calloc(size,sizeof(Graph));
    nowVisit=(int*)calloc(size,sizeof(int));
    top=(int*)calloc(size,sizeof(int));
    pos=size-1;

    for(int i=0;i<size;i++){
        graph[i]=(Graph*)calloc(size,sizeof(Graph));
    }

    int col=0,cow=0;
    printf("请开始输入边的关系,如0 3,则表示结点0到结点3之间有一条边,输入-1 -1表示结束输入\n");
    scanf("%d %d",&col,&cow);
    do{
        graph[col][cow]=1;
        scanf("%d %d",&col,&cow);
    }while (col!=-1&&cow!=-1);

}

void topSort(){
    for(int i=0;i<size;i++){
        if(nowVisit[i]==0){
            if(dfs(i)==0){
                printf("有环图,拓扑排序失败!");
                return;
            }
        }
    }
    printf("\n\n拓扑排序为: %d",top[0]);
    for (int j = 1; j < size; ++j) {
        printf("->%d",top[j]);
    }
}

void show(){
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            printf("%d  ",graph[i][j]);
        }
        printf("\n");
    }

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
        switch (select){
            case 1: create();
                    state=1;
                    system("cls");
                    printf("创建成功");
                    break;
            case 2: if (state==1)
                        topSort();
                    else{
                        system("cls");
                        printf("请先创建图\n");
                    }
                    break;
            case 3: if(state==1)
                        show();
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

    system("pause");

}