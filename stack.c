#include<stdio.h>

int stack[100],top=0,n;

void push(void);
void pop(void);
void display();

void main(){
	
	int choice;	

	top=-1;
	
	printf("Enter the size of the stack");
	scanf("%d",&n);
	printf("\n Enter The Options Below :");
	do{	
		
		printf("\n \t1:Push\n\t2:Pop\n\t3:Display\n\t4:Exit\n");			
		scanf("%d",&choice);
		switch(choice){
	
			case 1:
				 push();
				break;
			case 2:
				 pop();
				break;
			case 3:
				 display();
				break;	
			case 4:
				printf("\nExiting....................................");
				break;	
			default:
				printf("\n Enter the correct options");
			
		}	
		
	}while(choice!=4);

	
}

void push(){

	int a;	
	if(top==n-1)
		printf("\n Stack Overflow");
	else{
		
		printf("\n Enter the number To Push :");
		scanf("%d",&a);	
		top++;
		stack[top]=a;
		
	}
}

void pop(){

		
	if(top==-1)
		printf("\n Stack Unerflow");
	else{
		
		printf("\n The poped Element : %d",stack[top]);
		top--;
	}
}

void display(){

	int i;
	for(i=top;i>=0;i--){
		printf("\n%d",stack[i]);	
	}
}




































