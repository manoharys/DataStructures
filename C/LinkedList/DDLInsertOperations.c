#include<stdio.h>
#include<stdlib.h>

struct node {
 struct node *prev;
 int data;
 struct node *next;
}*root = NULL;

void create(){
 struct node *temp;
 int n;
 printf("Enter how many nodes do you want to create\n");
 scanf("%d", &n);
 for(int i=0;i<n;i++){
    temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter the node %d data\n", i+1);
    scanf("%d", &temp->data);
    temp->prev = temp->next = NULL;
    if(root == NULL){
        root = temp;
    }
    else{
        struct node *p = root;
        while(p->next != NULL){
            p = p->next;
        }
        temp->prev = p;
        p->next = temp;
        p = temp;
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

int length(){
 int count = 0;
  struct node *p = root;
  if(p == NULL){
    return count;
  }else{
    while(p != NULL){
        count++;
        p = p->next;
    }
    return count;
  }
}

void insertFirst(){
 struct node *temp;
 temp = (struct node*)malloc(sizeof(struct node));
 printf("Enter the node data\n");
 scanf("%d", &temp->data);
 temp->prev = temp->next = NULL;

 if(root == NULL){
    root = temp;
 }else{
   struct node *p = root;
   temp->next = p;
   p->prev = temp;
   p = root = temp;
 }
}

void insertEnd(){
 struct node *temp;
 temp = (struct node*)malloc(sizeof(struct node));
 printf("Enter the node data\n");
 scanf("%d", &temp->data);
 temp->prev = temp->next = NULL;

 if(root == NULL){
    root = temp;
 }
 else{
    struct node *p = root;
    while(p->next != NULL){
        p = p->next;
    }
    temp->prev = p;
    p->next = temp;
 }
}

void insertPosition(){
 int pos;
 printf("Enter the position to insert node & there are %d nodes in List\n ", length());
 scanf("%d", &pos);
 if(pos>0 && pos<=pos){
     struct node *temp;
     temp = (struct node*)malloc(sizeof(struct node));
     printf("Enter the node data\n");
     scanf("%d", &temp->data);
     temp->prev = temp->next = NULL;

     if(pos == 1){
        struct node *p = root;
        temp->next = p;
        p->prev = temp;
        p = root = temp;
     }
     else{
        struct node *p = root;
        for(int i=1;i<pos-1;i++){
            p = p->next;
        }
        temp->next = p->next;
        p->next->prev = temp;
        p->next = temp;
        temp->prev = p;
     }
 }
 else{
    printf("Enter the valid position\n");
 }
}

int main(){
 int choice;

 printf("**********Initial list element**********\n");
 create();
 display();

 while(1) {
     printf("Enter 1 to insert data before first node\n");
     printf("Enter 2 to insert data at the end of the list\n");
     printf("Enter 3 to insert data at specified location\n");
     printf("Enter 4 to display list\n");
     printf("Enter 5 to know the length of the list\n");
     scanf("%d", &choice);

     switch(choice){
       case 1 : insertFirst();
                break;
       case 2 : insertEnd();
                break;
       case 3 : insertPosition();
                break;
       case 4 : display();
                break;
       case 5 : printf("Length = %d\n", length());
                break;
       default : printf("Enter the valid option\n");
   }
  }
}

