#include<stdio.h>

int main(){
	
	int number[11]={0,};
	
	int x=0;
	scanf("%d",&x);
	

	int i=0;
	while(x>0){
		
		number[i]=x%10;
		x/=10;
		i++;
	}

	for(i-=1;i>=0;i--){
		printf("%d\n",number[i]);
	}
	
	return 0;
} 
