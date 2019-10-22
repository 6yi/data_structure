#include<stdio.h>
#include<stdlib.h>


void Merge(int *x,int *temp,int L,int R,int RightEnd){
	int LeftEnd,nums,tmp;
	LeftEnd=R-1;
	tmp=L;
	nums=RightEnd-L+1;
	while(L<=LeftEnd&&R<=RightEnd){
		if(x[L]<=x[R]){
			temp[tmp++]=x[L++];
		}else{
			temp[tmp++]=x[R++];
		}
	}
	while(L<=LeftEnd){
		temp[tmp++]=x[L++];
	}
	while(R<=RightEnd){
		temp[tmp++]=x[R++];
	}
	for( int i = 0; i < nums; i++, RightEnd -- )
         x[RightEnd] = temp[RightEnd];
} 

void Msort(int *x,int *temp,int L,int RightEnd){
	int center;
	if(L<RightEnd){
		center=(L+RightEnd)/2;
		Msort(x,temp,L,center);
		Msort(x,temp,center+1,RightEnd);
		Merge(x,temp,L,center+1,RightEnd);
	}
}

void MergeSort(int* x,int N){
	int* temp=(int*)malloc(sizeof(int)*N);
	if(temp!=NULL){
		Msort(x,temp,0,N-1);
		free(temp);
	}else{
		printf("error");
	}
	for(int i=0;i<N;i++){
		printf("%d  ",x[i]);
	}
}

int main(){
	
	int x[10]={9,54,1,34,5,123,543,7,13,53};
	MergeSort(x,10);

}



