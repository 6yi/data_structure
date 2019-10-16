#include<stdio.h>
#include<stdlib.h>
#define max 999
int m[][7]={
		{2,3,0,5,5,6,0},
		{0,0,0,1,0,0,7},
		{3,0,8,5,1,4,0},
		{7,3,2,1,0,0,0},
};

struct Mat{
	int cow,col;
	int value;
};

typedef struct{
	int max_cow,max_col,ef_value;
	Mat *mats;
}spmartix;


//统计有效的坐标
int get_ef_value(int cow,int col){
	int sum=0;
	for(int i=0;i<cow;i++){
		for(int j=0;j<col;j++){
			if(m[i][j]!=0){
				sum++;
			}
		}
	}
	return sum; 
}
//创建三元组表 
spmartix create(){
	spmartix spm;
	spm.max_col=7;
	spm.max_cow=4;			
	spm.ef_value=get_ef_value(4,7);
	spm.mats=(Mat*)malloc(sizeof(struct Mat)*spm.ef_value);
	int number=0;
		for(int i=0;i<spm.max_cow;i++){
		for(int j=0;j<spm.max_col;j++){
			if(m[i][j]!=0){
				spm.mats[number].value=m[i][j];
				spm.mats[number].col=j;
				spm.mats[number].cow=i;
				number++; 
			}
		}
	}
	return spm;
}	

//打印三元组表 
void show(spmartix *spm){
		printf("cow   col   ef_value\n");
		for(int i=0;i<spm->ef_value;i++){
				printf("%d       %d      	  %d\n",spm->mats[i].cow,spm->mats[i].col,spm->mats[i].value); 
		}
	
}




int main(){
	spmartix spm=create();
	show(&spm);
	return 0;
}
 
