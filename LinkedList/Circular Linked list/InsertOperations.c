#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node* next;
}*head = NULL;

//creating the initial circular linked list
 void create(){
   struct node *temp = NULL, *p = NULL;
   int n;
   printf("Creating initial list\n");
   printf("Enter the number of node do you want to create\n");
   scanf("%d", &n);

   for(int i=0;i<n;i++){
     temp = (struct node*)malloc(sizeof(struct node));
     printf("Enter the node %d data\n", i+1);
     scanf("%d", &temp->data);
     temp->next = NULL;

     if(head == NULL){
        head = temp;
        head->next = head;
        p = head;
     }
     else{
        temp->next = p->next;
        p->next = temp;
        p = temp;
     }
   }
 }

//Displaying the list
void display(){

  if(count() == 0){
    printf("No nodes in the list\n");
    exit(0);
  }
  else{
      struct node *p = head;
        printf("first Address : %d->", p->next);
      do {
        printf("%d->", p->data);
        p = p->next;
      }while(p != head);

        printf("%d last Address\n",p->next);
  }
}
//Appending element to the last node
void append(){
 struct node *temp, *p = head;
 temp = (struct node*)malloc(sizeof(struct node));
 printf("Enter the node data\n");
 scanf("%d", &temp->data);

 p = p->next;
 while(p->next != head){
   p = p->next;
 }
 p->next = temp;
 temp->next = head;
}

//Prepending element to the first node
void prepend(){
 struct node *temp, *p = head;
 temp = (struct node*)malloc(sizeof(struct node));
 printf("Enter the node data\n");
 scanf("%d", &temp->data);

 temp->next = head;
 p = p->next;
 while(p->next != head){
   p = p->next;
 }
 p->next = temp;
 head = temp;
}

int count(){
  int count = 0;
  struct node *p = head;
  if(head == NULL){
    return count;
  }
  else{
    do{
      count++;
      p = p->next;
    }while(p!=head);
    return count;
  }
}

 void appendPosition(){
   int pos;
   printf("Enter the position to insert a data & there are %d nodes\n", count());
   scanf("%d", &pos);
   if(pos>0 && pos<=count()){
   struct node *temp, *p = head;
   temp = (struct node*)malloc(sizeof(struct node));
   printf("Enter the node data\n");
   scanf("%d", &temp->data);

   if(pos == 1){
     temp->next = head;
     p = p->next;
     while(p->next != head){
       p = p->next;
     }
     p->next = temp;
     head = temp;
   }
   else{
      for(int i=1;i<pos-1;i++){
        p = p->next;
      }
      temp->next = p->next;
      p->next = temp;
   }
   }
   else{
    printf("Enter the valid position\n");
   }
 }

 void deleteNode(){
  int pos;
  printf("Enter the node position to delete that node & there are %d nodes present\n", count());
  scanf("%d", &pos);
  if(pos>0 && pos<=count()){
      if(count() == 1){
        head = NULL;
      }
   else if(pos == 1){
        struct node *p = head;
        p = p->next;
        while(p->next != head){
            p = p->next;
        }
        head = head->next;
        p->next = head;
     }
     else{
        struct node *p = head, *temp = NULL;
        for(int i=1;i<pos-1;i++){
            p = p->next;
        }
        temp = p->next;
        p->next = temp->next;
        temp->next = NULL;
        free(temp);
     }
  }
  else{
    printf("Enter the valid position\n");
  }
}

int main(){
  int choice;
  create();
    while(1){
  printf("*****Circular linked list********\n");
  printf("Enter 1 to insert element at the end of the circular linked list\n");
  printf("Enter 2 to insert element before head node\n"); //technically this & above statement are same in circular linked list, Since last node contains the address of first node.
  printf("Enter 3 to insert at specific position\n");
  printf("Enter 4 to display element in circular linked list\n");
  printf("Enter 5 to count the number of element in the circular linked list\n");
  printf("Enter 6 to delete a node\n");
  scanf("%d", &choice);

      switch(choice){
        case 1: append();
                break;
        case 2: prepend();
                break;
        case 3: appendPosition();
                break;
        case 4: display();
                break;
        case 5: count();
                break;
        case 6: deleteNode();
                break;
        default: printf("Choose the valid options\n");
      }
  }
}
