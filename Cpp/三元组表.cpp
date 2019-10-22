#include<stdio.h>
#include<stdlib.h>
int m[][7]={
	{0,0,0,0,0,0,0},
	{0,3,0,0,0,0,0},
	{0,0,12,0,0,0,0},
	{1,4,0,0,0,0,0},
	{0,0,7,0,0,0,0},
	{0,0,0,0,0,5,0},
	{0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0}
};

struct Mat{
	int row,col;
	int value;
};

typedef struct{
	int max_row,max_col,ef_value;
	Mat *mats;
}spmartix;

//统计有效的坐标 
int get_ef_value(int row,int col){
	int sum=0;
	for(int i=0;i<row;i++){
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
	spm.max_row=9;			
	spm.ef_value=get_ef_value(9,7);
	spm.mats=(Mat*)malloc(sizeof(struct Mat)*spm.ef_value);
	int number=0;
		for(int i=0;i<spm.max_row;i++){
			for(int j=0;j<spm.max_col;j++){
			if(m[i][j]!=0){
				spm.mats[number].value=m[i][j];
				spm.mats[number].col=j;
				spm.mats[number].row=i;
				number++; 
			} 
		}
	}
	return spm;
}	

//打印三元组表 
void print_data(spmartix *spm){
		printf("row   col   ef_value\n");
		for(int i=0;i<spm->ef_value;i++){
				printf("%d       %d      	  %d\n",spm->mats[i].row,spm->mats[i].col,spm->mats[i].value); 
		}
		printf("======================\n");
}

//矩阵快速转置 
void fast_transmat(spmartix *spm){
	int num[spm->max_col]={0,};
	
	for(int i=0;i<spm->max_col-1;i++){
		num[spm->mats[i].col]++;
		//printf("%d\n",spm->mats[i].col);
	} 
	int cpot[spm->max_col]={0,};
	
	for(int i=1;i<spm->max_col;i++){
		cpot[i]=num[i-1]+cpot[i-1];
	}
	Mat *mats=(Mat*)malloc(sizeof(struct Mat)*spm->ef_value);
	int index=0;
	for(int i=0;i<spm->ef_value;i++){
		index=cpot[spm->mats[i].col];
		mats[index].col=spm->mats[i].row;
		mats[index].row=spm->mats[i].col;
		mats[index].value=spm->mats[i].value;
		cpot[spm->mats[i].col]++;
	}
	free(spm->mats);
	spm->mats=mats;	 
}



int main(){
	spmartix spm=create();
	printf("原始矩阵\n");
	for(int i=0;i<9;i++){
		for(int j=0;j<7;j++){
			printf("%d  ",m[i][j]);
		}
		printf("\n");
	}
	printf("压缩矩阵为三元组表\n"); 
	print_data(&spm);
	printf("快速逆置三元组表\n");
	fast_transmat(&spm);
	//逆置后输出 
	print_data(&spm);
	return 0;
}
 
