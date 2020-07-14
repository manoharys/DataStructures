#include<stdio.h>
#include<stdlib.h>

struct node{
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
   temp->prev = NULL;
   temp->next = NULL;

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
     while(p!=NULL){
     printf("%d->", p->data);
     p = p->next;
   }
 printf("NULL\n");
}

int count(){
 int count = 0;
 struct node *p=root;
 if(root == NULL){
    return count;
 }
 else{
    while(p!=NULL){
        count++;
        p = p->next;
    }
    return count;
 }
}

int main(){
 create();
 printf("******\n");
 display();
 printf("%d nodes present in the list\n", count());
}
