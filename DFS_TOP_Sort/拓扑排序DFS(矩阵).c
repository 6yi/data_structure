#include<stdio.h>
#include<stdlib.h>
typedef int Graph;
Graph **graph;//AOV��
int *nowVisit;//���ڷ��ʻ���ʹ��Ľ��
int *top;//����������ϵ�����
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
    printf("����������:");
    scanf("%d",&size);
    graph=(Graph**)calloc(size,sizeof(Graph));
    nowVisit=(int*)calloc(size,sizeof(int));
    top=(int*)calloc(size,sizeof(int));
    pos=size-1;

    for(int i=0;i<size;i++){
        graph[i]=(Graph*)calloc(size,sizeof(Graph));
    }

    int col=0,cow=0;
    printf("�뿪ʼ����ߵĹ�ϵ,��0 3,���ʾ���0�����3֮����һ����,����-1 -1��ʾ��������\n");
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
                printf("�л�ͼ,��������ʧ��!");
                return;
            }
        }
    }
    printf("\n\n��������Ϊ: %d",top[0]);
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
        printf("\n\n1.����ͼ\n");
        printf("2.�����������\n");
        printf("3.��ʾͼ\n");
        printf("4.�˳�\n");
        scanf("%d",&select);
        switch (select){
            case 1: create();
                    state=1;
                    system("cls");
                    printf("�����ɹ�");
                    break;
            case 2: if (state==1)
                        topSort();
                    else{
                        system("cls");
                        printf("���ȴ���ͼ\n");
                    }
                    break;
            case 3: if(state==1)
                        show();
                    else{
                        system("cls");
                        printf("���ȴ���ͼ\n");
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