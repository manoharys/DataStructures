#include<stdio.h>
#include<stdlib.h>

struct node{
 int data;
 struct node *next;
}*root = NULL;

void append(){
  struct node *temp;



  for(int i=0;i<5;i++){
    temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter the %d element \n", i+1);
    scanf("%d", &temp->data);
    temp->next = NULL;

    if(root == NULL){
        root = temp;
    }
    else {
      struct node *p = root;
        while(p->next != NULL){
            p = p->next;
        }
        p->next = temp;
    }
  }
}

void display(struct node *root){

  if(root!=NULL){
  printf("%d->",root->data);
  display(root->next);
  }
  return;
}


void display2(struct node *root){

  if(root!=NULL){
  printf("%d->",root->data);
  display(root->next);
  }
  return;
}

void reverse(struct node *root){
  if(root!=NULL){
    reverse(root->next);
   printf("%d->",root->data);

  }
  return;
}
int main(){
  append();
  display(root);
  printf("\n");
  reverse(root);
}
