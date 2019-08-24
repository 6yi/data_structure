#include<stdio.h>
#include<stdlib.h>
#define type_data int

typedef struct heap{
	type_data* data;
	int maxSize;
	int size;
}heap;


heap create_heap(int maxSize){
	heap* p=(heap*)malloc(sizeof(heap));
	p->data=(type_data*)malloc(sizeof(type_data)*(maxSize+1));
	p->size=0;
	p->maxSize=maxSize;
	p->data[0]=100000;//из╠Ь 
	return *p; 
}

bool isFull(heap* p){
	return p->maxSize==p->size;
}

void insert(heap* p,type_data data){
	int i;
	if(isFull(p)){
		printf("heap is full");
		return;
	}
	i=++p->size;
	
	for(;p->data[i/2]<data;i/=2){
		p->data[i]=p->data[i/2];
	}
	p->data[i]=data;
}

void show(heap* p){
	
	for(int i=0;i<p->maxSize;i++){
		printf("%d  ",p->data[i]);
	}
	
}



int main(){
	heap max_heap=create_heap(10);
	int i[]={23,4,124,53,523,12,41,2,7};
	
	for(int z=0;z<9;z++){
		insert(&max_heap,i[z]);
	}
	show(&max_heap);
	
	return 0;
} 
