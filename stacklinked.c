
#include<stdio.h>
#include<stdlib.h>

struct node {
	
	int data;
	struct node *next;
};

struct node *temp,*head;

void push();
void display();
void pop();
void top();



void main(){
	
	int choice;
	
	printf("\n*************Stack Using Linked List Operations*************")	;
		
	do{
	
		printf("\n\t 1.Push");
		printf("\n\t 2.Pop");	
		printf("\n\t 3.Top");			
		printf("\n\t 4.display");
		printf("\n\t 5.Exit\n");
		
		scanf("%d",&choice);
		
		switch(choice){
			
			case 1:
					push();
					break;
			case 2:
					pop();
					break;
			case 3:
					top();
					break;

			case 4:
					display();
					break;							
						
			case 5:
					printf("\n *********Exiting**********");
					break;
			default:
					printf("\n Enter the  correct options");
					
					
		}
		
		temp=head;	
		
	}while(choice!=5);
}

void pop(){
	
	struct node *prev;
	
	if(head==NULL)
		printf("Stack Is Empty");
	else if(head->next==NULL){
		printf("\n%d is Deleted ",head->data);
		free(head);
		head=NULL;
	}
	else{	
		while(temp->next!=NULL){
			prev=temp;
			temp=temp->next;
		}
		prev->next=NULL;
		printf("\n%d is Deleted ",temp->data);
		free(temp);	
	}	
}

void top(){

	struct node *tmp;
	
	if(head==0)
		printf("Stack Is Empty");
	else{
	
		while(temp->next!=NULL){
			temp=temp->next;

		}
		printf("\n Top element is %d : ",temp->data);	
	}	
}




void push(){
	
	struct node *newnode;
	int data;
	
	newnode=(struct node*)malloc(sizeof(struct node*));
	
	printf("\n Enter the data want to insert");
	scanf("%d",&data);
	newnode->data=data;
	newnode->next=NULL;
	
	if(head==NULL){
		head=newnode;
		temp=newnode;
	}
	else{
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next=newnode;
		temp=newnode;	
	}	
}

void display(){

	printf("\n******The Stack data****\n");
	
	if(head==NULL)
		printf("Stack is empty");
	else{
	while(temp!=NULL){
		printf("%d->",temp->data);
		temp=temp->next;
	}
	}
}




























