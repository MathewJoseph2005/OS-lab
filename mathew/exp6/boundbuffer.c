#include <stdio.h>

#include <stdlib.h>

int mutex =1;
int full=0;
int empty,x=0;

void producer(){
	--mutex;
	++full;
	--empty;
	x++;
	printf("\nProuducer produes iteam %d" ,x);
	++mutex;
}
void consumer(){
	--mutex;
	--full;
	++empty;
	printf("consumer comsumes iteam %d",x);
	x--;
	++mutex;
}
int main(){
	int n,i,k;
	printf("Enter the buffer size:");
	scanf("%d",&k);
	empty=k;
	printf("\n press 1 for producer\n press 2 for consumer\n press 3 for exit");
	for(i = 1;i>0;i++){
		printf("\n Enter your choice :");
		scanf("%d",&n);
		switch(n){
			case 1:
				if ((mutex==1)&&(empty !=0)){
					producer();

				}else{
					printf("Buffer is full!");

				}
				break;
			case 2:
				if((mutex == 1)&& (full !=0)){
					consumer();

				}else{
					printf("buffer is empty !");

				}
				break;
			case 3:
				printf("Buffer is empty !");
				exit(0);
				break;
		}

	}

}
