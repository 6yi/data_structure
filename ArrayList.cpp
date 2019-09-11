#include<stdio.h>
#include<stdlib.h>
typedef struct Node *ptrNode;
typedef int data_type;
struct Node{
	data_type *number;
	int max_lenght;
	int now_lenght;
};
typedef ptrNode ArrayList;

ArrayList create(){
	ArrayList list=(ArrayList)malloc(sizeof(struct Node));
	printf("输入节点数量:\n");
	scanf("%d",&(list->max_lenght));
	list->number=(data_type*)malloc(sizeof(data_type)*list->max_lenght);
	list->now_lenght=-1;
	
	for(int i=0;i<list->max_lenght;i++){
		printf("data: ");
		scanf("%d",&(list->number[i]));
		list->now_lenght++;
	}
	return list;	
} 

bool is_full(ArrayList list){
	return (list->max_lenght-1)==(list->now_lenght);
}
bool is_empty(ArrayList list){
	
	return list->now_lenght==-1;
	
}

void insert(ArrayList list,data_type number){
	if(!is_full(list)){
		list->number[++list->now_lenght]=number;
		printf("insert success!\n"); 
	}else{
		printf("list is full!\n");
	}
}


void insert_postion(ArrayList list,data_type number,int postion){
	if(!((postion-1)>(list->now_lenght+1)||postion<=0)){
		if(!is_full(list)){
		for(int i=(list->now_lenght+1);i>(postion-1);i--){
			list->number[i]=list->number[i-1];
		}
		list->number[postion-1]=number;
		list->now_lenght+=1;
		printf("\nsuccess!!\n");
	}else{
		printf("\nlist is full!\n");
	}
	}else{
		printf("\nThe postion is wrong!\n");
	}
	
}

void delete_postion(ArrayList list,int postion){
	if(!(postion-1>list->now_lenght||postion<=0)){
	if(!is_empty(list)){
		for(int i=(postion-1);i<list->now_lenght;i++){
			list->number[i]=list->number[i+1];
		}
		list->now_lenght--;
		printf("delete success!\n"); 
	}else{
		printf("\nlist is empty!\n");
	}
	}else{
		printf("\nThe postion is wrong!\n");
	}
}

void show_list(ArrayList list){
	printf("\n");
	for(int i=0;i<=list->now_lenght;i++){
		printf("%d  ",list->number[i]);
	}
	printf("\n");
}

int find(ArrayList list,data_type number){
	for(int i=0;i<=list->now_lenght;i++){
		if(list->number[i]==number){
			return ++i;
		}
	}
	return -1;
}

void Gui(){	
	ArrayList list=NULL;
	int x=0,y=0,z=0,po=-1;
	int isprime=1;
	do{
		printf("     Menu\n"); 
		printf("1.创建线性表\n");
		printf("2. 插入一个元素到末尾\n");  
		printf("3. 删除指定位置元素\n");
		printf("4. 插入一个元素到指定位置\n");
		printf("5. 查找某元素所在位置\n");
		printf("6. 输出所有元素\n");
		printf("7. 结束\n");
		scanf("%d",&x);	
		switch(x){
			case 1:
					list=create();
					break;
			case 2:
					printf("输入插入的元素: ");
					scanf("%d",&y);
					insert(list,y);
					break;
			case 3:
					printf("输入所要删除的元素位置: ");
					scanf("%d",&z);	
					delete_postion(list,z);	
					break;
			case 4:
					printf("输入插入的元素以及位置\n");
					printf("data:");
					scanf("%d",&y);
					printf("位置:");
					scanf("%d",&z);
					insert_postion(list,y,z);
					break;
			case 5:
					printf("输入要查找的元素：");
					scanf("%d",&y);
					po=find(list,y);
					if(po!=-1){
						printf("在线性表的第%d号位置\n",po);
					}else{
						printf("不存在此元素\n");
					}
					break;
			case 6:
					show_list(list);
					break;		
			case 7:
					isprime=0;		 														
		} 
		      
	}while(isprime==1);		
}

int main(){
	
	Gui();
	return 0;
	
}
 
