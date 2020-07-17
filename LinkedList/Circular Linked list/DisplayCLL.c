#include<stdio.h>
#include<stdlib.h>

struct node {
  int data;
  struct node* next;
}*head = NULL;

void create(){
 struct node *temp, *p;
 int n;
 printf("Enter how many nodes do you want to create\n");
 scanf("%d", &n);

 for(int i=0;i<n;i++){
   temp = (struct node*)malloc(sizeof(struct node));
   printf("Enter the node %d data\n", i+1);
   scanf("%d", &temp->data);
   temp->next = NULL;
   if(head == NULL){
    head = temp;
    p = head;
   }else{
    p->next = temp;
    p = temp;
   }
 }
 p->next = head;
}

void display(){
     struct node *p = head;
 do{

    printf("%d->", p->data);
    p = p->next;
 }while(p != head);
 printf("NULL\n");
  printf("%d first node address\n", head);
  printf("%d last node address\n", p);
}

int main(){
  create();
  display();
  struct node *p = head;
}
