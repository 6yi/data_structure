#include <iostream>
#include "stdio.h"
#include "stdlib.h"
using namespace std;
typedef int Graph;
Graph ** create(int nums){
    Graph **graph=(Graph**)malloc(sizeof(int)*nums);
//    cout<<"开始输入边的权值,自身结点用0表示,无边则用-1表示"<<endl;
    for (int i = 0; i < nums; ++i) {
        graph[i]=(Graph*)malloc(sizeof(int)*nums);
    }
    graph[0][0]=0;
    graph[0][1]=1;
    graph[0][2]=1;
    graph[0][3]=0;
    graph[0][4]=0;

    graph[1][0]=0;
    graph[1][1]=0;
    graph[1][2]=1;
    graph[1][3]=0;
    graph[1][4]=1;

    graph[2][0]=0;
    graph[2][1]=0;
    graph[2][2]=0;
    graph[2][3]=1;
    graph[2][4]=0;

    graph[3][0]=0;
    graph[3][1]=0;
    graph[3][2]=0;
    graph[3][3]=0;
    graph[3][4]=1;

    graph[4][0]=1;
    graph[4][1]=0;
    graph[4][2]=0;
    graph[4][3]=0;
    graph[4][4]=0;

//    for (int j = 0; j < nums; ++j) {
//        for (int i = 0; i < nums; ++i) {
//            cout<<j<<" -> "<<i<<" : ";
//            cin>>graph[j][i];
//        }
//    }
    return graph;
}

int main() {
    int nums=5;
    Graph **graph=create(nums);
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            printf("%d ",graph[i][j]);
        }
        printf("\n");
    }
    return 0;
}