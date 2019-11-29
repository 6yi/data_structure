#include<stdio.h>
#include<stdlib.h>
typedef int Graph;

Graph** create(int size){
	Graph** graph=(Graph**)malloc(sizeof(Graph)*size);
	for(int i=0;i<size;i++){
		graph[i]=(Graph*)malloc(sizeof(Graph)*size);
		for(int j=0;j<size;j++){
			graph[i][j]=0;
		}
	}
	/**
		�������� 
	*/
	graph[0][0]=0;
	graph[0][1]=1;
	graph[0][3]=1;
	graph[1][6]=1;
	graph[3][6]=1;
	graph[2][1]=1;
	graph[2][4]=1;
	graph[4][5]=1;
	graph[5][6]=1;
	return graph;
}

void tp(Graph** graph,int size){
	/**
		����������� 
	**/
	int nums[size]={0,};
	int visit[size]={0,}; 
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			if(graph[i][j]!=0){
				nums[j]++;
			}
		}
	}
	for(int i=0;i<size;i++){
		printf("%d ",nums[i]);
	}
		printf("\n\n\n ");
	for(int i=0;i<size;i++){
		int now=-1;
		for(int j=0;j<size;j++){
			if(nums[j]==0&&visit[j]==0){
				now=j;
				visit[j]=1;
				break;
			}
		}
		for(int i=0;i<size;i++){
			if(graph[now][i]!=0){
				graph[now][i]=0;
				nums[i]--;
			}	
		}
		printf("%d ",now);
	}
}


int main(){
	int size=0;
	scanf("%d",&size);
	Graph** graph=create(size);
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			printf("%d ",graph[i][j]);
		}
		printf("\n");
	}
	printf("\n\n\n\n");
	tp(graph,size);
	return 0;
}




