
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

void concatenation(){
 struct node *temp = first;

 while(temp->next != NULL){
    temp = temp->next;
 }
 temp->next = second;
 third = first;
}


int main(){
    printf("***First node*****\n");
    createFirst();
    display(first);
    printf("***second node****\n");
    createSecond();
    display(second);
    printf("***Third List****\n");
    concatenation();
    display(third);
}
