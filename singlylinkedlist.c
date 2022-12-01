	
#include<stdio.h>
#include<stdlib.h>

struct node {
	
	int data;
	struct node *next;
};

struct node *temp,*head;

void create();
void display();
void insertatend();
void insertbegining();
void insertposition();
void deleteend();
void deletebegining();
void deleteposition();



void main(){
	
	int choice;
	
	printf("\n*************Singly Linked List Operations*************")	;
		
	do{
	
		printf("\n\t 1.create");
		printf("\n\t 2.Insert At End");
		printf("\n\t 3.Insert At Begining");
		printf("\n\t 4.Insert At Particular Position");
		printf("\n\t 5.Delete At End");
		printf("\n\t 6.Delete At Begining");
		printf("\n\t 7.Delete At Particular Position");				
		printf("\n\t 8.display");
		printf("\n\t 9.Exit\n");
		
		scanf("%d",&choice);
		
		switch(choice){
			
			case 1:
					create();
					break;
			case 2:
					create();
					break;
					
			case 3:
					insertbegining();
					break;
			case 4:
					insertposition();
					break;	
			case 5:
					deleteend();
					break;
					
			case 6:
					deletebegining();
					break;
			case 7:
					deleteposition();
					break;								
			
			case 8:
					display();
					break;							
						
			case 9:
					printf("\n *********Exiting**********");
					break;
			default:
					printf("\n Enter the  correct options");
					
					
		}
		
		temp=head;	
		
	}while(choice!=9);
}

void deleteend(){
	
	struct node *prev;
	
	if(head==0)
		printf("Stack Is Empty");
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

void deletebegining(){

	struct node *tmp;
	
	if(head==0)
		printf("Stack Is Empty");
	else{
	
		tmp=head;
		printf("\n%d is Deleted ",tmp->data);
		head=tmp->next;
		free(tmp)		;
		
	}	
}


void deleteposition(){
	
	struct node *prev;int pos,i=1;
	
	
	printf("\n Enter the position");
	scanf("%d",&pos);
	
	
	while(i<pos){
		prev=temp;
		temp=temp->next;
		i++;
	}
	
	prev->next=temp->next;
	
	printf("\n%d is Deleted ",temp->data);
	
	free(temp);

}





void create(){
	
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


void insertposition(){
	
	struct node *newnode;int pos,i=1;
	int data;
	
	printf("\n Enter the position");
	scanf("%d",&pos);
	
	newnode=(struct node*)malloc(sizeof(struct node*));
	
	printf("\n Enter the data want to insert");
	scanf("%d",&data);
	newnode->data=data;
	newnode->next=NULL;
	
	while(i<pos-1){
		temp=temp->next;
		i++;
	}
	
	newnode->next=temp->next;
	temp->next=newnode;
	
}



void insertbegining(){
	
	struct node *newnode;
	int data;
	
	newnode=(struct node*)malloc(sizeof(struct node*));
	
	printf("\n Enter the data want to insert At the begining");
	scanf("%d",&data);
	newnode->data=data;
	newnode->next=NULL;
	
	if(head==NULL){
		head=newnode;
		temp=newnode;
	}
	else{
	
		newnode->next=head;
		head=newnode;	
	}		
		
}

void display(){

	printf("\n******The List data****\n");
	
	temp=head;
	
	while(temp!=NULL){
	
		printf("%d->",temp->data);
		temp=temp->next;
	}
}

