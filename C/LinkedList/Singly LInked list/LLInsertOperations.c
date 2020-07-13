#include<stdio.h>
#include<stdlib.h>

void appendFirst();
void appendAfter();
void appendBefore();
void appendLast();
void display();
int count();


struct node {
  int data;
  struct node *next;
}*root = NULL;

int main(){

 int choice;

 while(1){
    printf("\n****Linked list Operations******\n");
    printf("Enter 1 to insert an element to last node\n");
    printf("Enter 2 to insert an element to first node\n");
    printf("Enter 3 to insert an element after a node at specified position\n");
    printf("Enter 4 to insert an element before a node at specified position\n");
    printf("Enter 5 to display nodes present in the linked list\n");
    printf("Enter 6 to count number of nodes present in the linked list\n");
    scanf("%d",&choice);

    switch(choice){
      case 1 : appendLast();
               break;
      case 2 : appendFirst();
               break;
      case 3 : appendAfter();
               break;
      case 4 : appendBefore();
               break;
      case 5 : display();
               break;
      case 6 : printf("No of nodes = %d\n", count());
               break;
      default : printf("Enter the valid option\n");
    }
 }

 return 0;
}

  void appendLast(){
    struct node *temp;

    temp = (struct node*)malloc(sizeof(struct node));

    printf("Enter node data\n");
    scanf("%d", &temp->data);
    temp->next = NULL;

    if(root == NULL){
        root = temp;
    }
    else{
        struct node *p = root;
        while(p->next != NULL){
            p = p->next;
        }
        p->next = temp;
    }
  }

 void appendFirst(){
    struct node *temp;

    temp = (struct node*)malloc(sizeof(struct node));

    printf("Enter node data\n");
    scanf("%d", &temp->data);
    temp->next = NULL;

    if(root == NULL){
        root = temp;
    }
    else{
        temp->next = root;
        root = temp;
    }
 }

 int count(){
   struct node *p = root;
   int count = 0;
   while(p != NULL){
    count++;
    p = p->next;
   }
   return (count);
 }

 void appendAfter(){
   int position;
   if(count() == 0){
    printf("Operation cannot be performed. Since List contains 0 nodes\n");
   }
   else{
       printf("Enter node position & current list has %d nodes\n", count());
       scanf("%d", &position);

       if(position>0 && position<=count()){
          struct node *temp, *p = root;
          temp = (struct node*)malloc(sizeof(struct node));
          printf("Enter the node data\n");
          scanf("%d", &temp->data);
          temp->next = NULL;

          int i=1;
          while(i<position){
            p = p->next;
            i++;
          }
          temp->next = p->next;
          p->next = temp;
       }
   }
 }

 void appendBefore(){

   int position;
   if(count() == 0){
    printf("Operation cannot be performed. Since List contains 0 nodes\n");
   }
   else{
       printf("Enter node position & current list has %d nodes\n", count());
       scanf("%d", &position);

       if(position>0 && position<=count()){
          struct node *temp, *p = root;
          temp = (struct node*)malloc(sizeof(struct node));
          printf("Enter the node data\n");
          scanf("%d", &temp->data);
          temp->next = NULL;

          int i=1;
          while(i<position-1){
            p = p->next;
            i++;
          }
          temp->next = p->next;
          p->next = temp;
       }
   }

 }

 void display(){
   struct node *p = root;
   while(p != NULL){
     printf("%d->", p->data);
     p = p->next;
   }
   printf("NULL\n");
 }


