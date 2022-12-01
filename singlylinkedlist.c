#include<stdio.h>

#include<stdlib.h>

struct node {
  int data;
  struct node * next;
};
struct node * head, * temp, * newnode, * prev;
int i = 1, position;
void beginsert();
void lastinsert();
void randominsert();
void begindelete();
void lastdelete();
void randomdelete();
void display();
void main() {
  int choice;
  do {
    printf("\nsingly linkedlist operations\n");
    printf("\nselect an option\n");
    printf("\n1.insert @ beginning\n2.insert @ end\n3.random insert\n4.delete @ beginning\n5.delete @ end\n6.random delete\n7.display\n8.exit");
    scanf("%d", & choice);
    switch (choice) {
    case 1:
      beginsert();
      break;
    case 2:
      lastinsert();
      break;
    case 3:
      randominsert();
      break;
    case 4:
      begindelete();
      break;
    case 5:
      lastdelete();
      break;
    case 6:
      randomdelete();
      break;
    case 7:
      display();
      break;
    case 8:
      printf("\nexit\n");
      break;
    default:
      printf("\nenter a valid option\n");
    }
  }
  while (choice != 8);
}
void beginsert() {
  //struct node *newnode;
  newnode = (struct node * ) malloc(sizeof(struct node));
  if (newnode == 0) {
    printf("\noverflow\n");
  } else {
    printf("\nenter data\n");
    scanf("%d", & newnode -> data);
    newnode->next=0;
    if(head==0){
    head=temp=newnode;
    printf("\nnode inserted\n");
    } 
    else {
      newnode->next=head;
      head=newnode;
      printf("\n node inserteted\n");
      }
  }
}

void lastinsert() {
  newnode = (struct node * ) malloc(sizeof(struct node));
  if (newnode == 0) {
    printf("\noverflow\n");
  } else {
    printf("\nenter data\n");
    scanf("%d", & newnode -> data);
    if (head == 0) {
      newnode -> next = 0;
      head = newnode;
      printf("\nnode inserted\n");
    } else {
      temp = head;
      while (temp -> next != 0) {
        temp = temp -> next;
      }
      temp -> next = newnode;
      newnode -> next = 0;
      printf("\nnode inserted\n");
    }
  }
}
void randominsert() {
  newnode = (struct node * ) malloc(sizeof(struct node));
  if (newnode == 0) {
    printf("\noverflow\n");
  } else {
    printf("\nenter data\n");
    scanf("%d", & newnode -> data);
    printf("enter position");
    scanf("%d", & position);
    newnode->next=0;

    while (i < position-1) {
      temp = temp -> next;
      i++;
    }
    newnode -> next = temp -> next;
    temp -> next = newnode;
    printf("\nnode inserted\n");
  }
}
void begindelete() {
  if (head == 0) {
    printf("\n list is empty\n");
  } else {
    temp = head;
    head = temp -> next;
    printf("\ndeleted %d\n", temp -> data);
    free(temp);

  }
}
void lastdelete() {
  if (head == 0) {
    printf("\n list is empty\n");
  } else {
    temp = head;
    while (temp -> next != 0) {
      prev = temp;
      temp = temp -> next;
    }
    prev -> next = 0;
    printf("\ndeleted %d\n", temp -> data);
    free(temp);

  }
}
void randomdelete() {
  printf("enter location");
  scanf("%d", & position-1);
  if (head == 0) {
    printf("\n list is empty\n");
  } else {
    temp=head;
    while (i < position) {
      prev = temp;
      temp = temp -> next;
      i++;
    }
    prev -> next = temp -> next;
    printf("\ndeleted %d\n", temp -> data);
    free(temp);
  }
}
void display() {
    if (head == 0) {
      printf("\nempty\n");
    } else {
      temp = head;
      while (temp != 0) {
        printf("%d\t", temp -> data);
        temp = temp -> next;
      }
    }
}    
