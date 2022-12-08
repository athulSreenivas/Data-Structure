
#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *next;
};

struct node *temp,*head;

void enqueue();
void display();
void dequeue();


void main(){
	
	int choice;
	
	printf("\n*************Circular Queue Using Linked List*************")	;
		
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

void dequeue(){
	
	struct node *prev;
	
	if(head==NULL)
		printf("Queueu Is Empty");
	else if(head->next==NULL){
		printf("\n%d is Deleted ",head->data);
		free(head);
		head=NULL;
	}
	else{
	
		temp=head;
		
		do{
			prev=temp;
			temp=temp->next;	
		}while(temp!=head);
		
		prev->next=head;
		printf("\n%d is Deleted ",temp->data);
		free(temp);	
	}	
}



void enqueue(){
	
	struct node *newnode;
	int data;
	
	newnode=(struct node*)malloc(sizeof(struct node*));
	
	printf("\n Enter the data want to insert : ");
	scanf("%d",&data);
	newnode->data=data;
	newnode->next=NULL;
	
	if(head==NULL){
		head=newnode;
		newnode->next=head;
		temp=newnode;
	}
	else{
	
		temp=head;
	
		do{
			printf("%d->mm",temp->data);
			temp=temp->next;
				
		}while(temp!=head);
	
		temp->next=newnode;
		newnode->next=head;
	}	
}

void display(){

	printf("\n******The Queue data****\n");
	
	if(head==NULL)
		printf("Queue is empty");
	else{
	
	temp=head;
		
	do{
		printf("%d->",temp->data);
		temp=temp->next;
		
	}while(temp!=head);

	}
}




























