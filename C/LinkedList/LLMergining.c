
#include<stdio.h>
#include<stdlib.h>

struct node {
  int data;
  struct node *next;
}*first = NULL, *second = NULL, *third = NULL;

void createFirst(){
  int n;
  printf("Enter how many nodes you want to create\n");
  scanf("%d", &n);
  printf("Enter the sorted data\n");
  for(int i=0;i<n;i++){
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter the node data\n");
    scanf("%d", &temp->data);
    temp->next = NULL;

    if(first == NULL){
        first = temp;
    }
    else{
        struct node *p = first;

        while(p->next != NULL){
            p = p->next;
        }

        p->next = temp;
    }
  }
}
void createSecond(){
  int n;
  printf("Enter how many nodes you want to create\n");
  scanf("%d", &n);
  printf("Enter the sorted data\n");
  for(int i=0;i<n;i++){
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter the node data\n");
    scanf("%d", &temp->data);
    temp->next = NULL;

    if(second == NULL){
        second = temp;
    }
    else{
        struct node *p = second;

        while(p->next != NULL){
            p = p->next;
        }

        p->next = temp;
    }
  }
}
void display(struct node *p){
  while(p!=NULL){
    printf("%d->",p->data);
    p = p->next;
  }
  printf("NULL \n");
}

void merge(){
  struct node *temp = NULL;
  if(first->data < second->data){
    third = temp = first;
    first = first->next;
    temp->next = NULL;
  }
  else{
    third = temp = second;
    second = second->next;
    temp->next = NULL;
  }

  while(first!=NULL && second!=NULL){
     if(first->data < second->data){
        temp->next = first;
        temp = first;
        first = first->next;
        temp->next = NULL;
     }
     else{
        temp->next = second;
        temp = second;
        second = second->next;
        temp->next = NULL;
     }
  }
//  while(first!=NULL){
//    temp->next = first;
//    temp = first;
//    temp->next = NULL;
//    first = first->next;
//  }
//  while(second!=NULL){
//    temp->next = second;
//    temp = second;
//    temp->next = NULL;
//    second = second->next;
//  }
   if(first!=NULL){
    temp->next = first;
   }
   if(second!=NULL){
    temp->next = second;
   }
}


int main(){
    printf("***First node*****\n");
    createFirst();
    display(first);
    printf("***second node****\n");
    createSecond();
    display(second);

    printf("****merged node*****\n");
    merge();
    display(third);
}
