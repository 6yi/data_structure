#include <stdio.h>
#include <stdlib.h>
#define max 9999
typedef struct graph *pGraph;
struct graph{
    int **v;
    int max_size;
};
typedef pGraph Graph;

int find_min_pos(Graph graph,int visit[],int local) {
    int pos=-1;
    int min=999;
    for (int i = 0; i < graph->max_size; ++i) {
        if (visit[i]==0&&graph->v[local][i]!=0&&graph->v[local][i]<max&&min>graph->v[local][i]){
            min=graph->v[local][i];
            pos=i;
        }
    }
    return pos;
}
void djs(Graph graph,int local){
    int max_size=graph->max_size;
    int *dist=(int*)malloc(sizeof(int)*max_size);
    int *path=(int*)malloc(sizeof(int)*max_size);
    int *visit=(int*)malloc(sizeof(int)*max_size);
    int min_pos=local;
    for (int i = 0; i < max_size; ++i) {
        dist[i]=graph->v[local][i];
        path[i]=local;
        visit[i]=0;
    }
    visit[local]=1;
    while (1){
        if ((min_pos=find_min_pos(graph,visit,min_pos))==-1){
            break;
        }
        visit[min_pos]=1;
        for (int i = 0; i < max_size; ++i) {
            if (visit[i]==0&&dist[min_pos]+graph->v[min_pos][i]<dist[i]&&graph->v[min_pos][i] < max){
                dist[i]=dist[min_pos]+graph->v[min_pos][i];
                path[i]=min_pos;
            }
        }
    }
    printf("path: ");
    for (int i = 0; i < max_size; i++) {
        printf("%d-> ",path[i]);
    }
    printf("\ndist: ");
    for (int i = 0; i < max_size; i++) {
        printf("%d-> ",dist[i]);
    }
}
int main(){
    Graph graph=(Graph)malloc(sizeof(struct graph));
    graph->v=(int **)malloc(sizeof(int *)*4);
    for (int i = 0; i < 4; ++i)
    {
        graph->v[i] = (int *)malloc(sizeof(int) * 4);
    }
    graph->v[0][0]=0;
    graph->v[0][1]=5;
    graph->v[0][2]=1;
    graph->v[0][3]=max;
    graph->v[1][0]=max;
    graph->v[1][1]=0;
    graph->v[1][2]=3;
    graph->v[1][3]=5;
    graph->v[2][0]=max;
    graph->v[2][1]=max;
    graph->v[2][2]=0;
    graph->v[2][3]=1;
    graph->v[3][0]=max;
    graph->v[3][1]=max;
    graph->v[3][2]=max;
    graph->v[3][3]=0;
    graph->max_size=4;
//    for (int i = 0; i < 4; i++) {
//        for (int j = 0; j < 4; ++j) {
//            printf("%d ",graph->v[i][j]);
//        }
//        printf("666");
//    }
    djs(graph,0);
    system("pause");
}
