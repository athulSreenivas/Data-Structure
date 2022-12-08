#include<stdio.h>

#define size 5

int queue[size];int f=-1,r=-1;

void enqueue();
void display();
void dequeue();


void main(){
	
	int choice;
	
	
	printf("\n*************Circular Queue Using Array*************")	;
		
	do{
	
		printf("\n\t 1.Enqueue");
		printf("\n\t 2.Dequeue");				
		printf("\n\t 3.display");
		printf("\n\t 4.Exit\n");
		
		scanf("%d",&choice);
		
		switch(choice){
			
			case 1:
					enqueue();
					break;
			case 2:
					dequeue();
					break;
			case 3:
					display();
					break;							
						
			case 5:
					printf("\n *********Exiting**********");
					break;
			default:
					printf("\n Enter the  correct options");		
		}
		
	}while(choice!=4);
}


void enqueue(){
	
	int data;
	if(f==(r+1)%size)
		printf("Queue is full");
	else{
			
		if(f==-1) f=0;
		r=(r+1)%size;
		
		printf("Enter the data");
		scanf("%d",&data);
		queue[r]=data;
	}
}

void display(){
		
	int i=f;
	
	if(f==-1 && r==-1)
		printf("Queue is empty");
	else{
	
		printf("Queue Element are");
		
		for(i=f;i<=r;i++){
		
			printf("%d\t",queue[i]);	
		}
	}
	
}

void dequeue(){

	if(f==-1 && r==-1){
		
		printf("Queue is empty");
		
	}else{
		
		printf("Deleted Element is %d :" ,queue[f]);
		
		if(f==r){
			f=-1;r=-1;
			}
		else
			f=(f+1)%size;
	}

}
















