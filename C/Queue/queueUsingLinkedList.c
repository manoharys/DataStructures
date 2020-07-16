#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node *next;
}*q = NULL;

int *front=NULL, *rear=NULL;

void enqueue(){
   struct node *temp;
   temp = (int*)malloc(sizeof(struct node));
   printf("Enter the data element\n");
   scanf("%d", &temp->data);
   temp->next = NULL;

   struct node *p = q;
   if(front == NULL && rear == NULL){
      q = temp;
      front = rear = temp;

   }else{
      p = rear;
      p->next = temp;
      rear = temp;
   }
}

void dequeue(){
  if(front == NULL || rear == NULL){
    printf("Queue is empty\n");
  }
  else{
      struct node *p = front;
      q = p->next;
      front = p->next;

      printf("%d deleted\n", p->data);
      p->next = NULL;
      free(p);
  }
}

void display(){
  struct node *p = q;
  while(p != NULL){
    printf("%d ", p->data);
    p = p->next;
  }
  printf("\n");
}
int main(){
  int choice;
  while(1){
      printf("Enter 1 to perform enqueue operation\n");
      printf("Enter 2 to perform dequeu operation\n");
      printf("Enter 3 to display queue element\n");
      scanf("%d", &choice);
   switch(choice){
     case 1: enqueue();
             break;
     case 2: dequeue();
             break;
     case 3: display();
             break;
     default: printf("Enter the valid choice\n");
   }
  }
}
