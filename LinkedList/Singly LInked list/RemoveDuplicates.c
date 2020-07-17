#include<stdio.h>
#include<stdlib.h>

struct node {
  int data;
  struct node *next;
}*root = NULL;

void create(){
  int n;
  printf("Enter how many nodes you want to create\n");
  scanf("%d", &n);
  printf("Enter the sorted elements \n");
  for(int i=0;i<n;i++){
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter the node data\n");
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
}

void display(){
  struct node *p = root;
  while(p!=NULL){
    printf("%d->",p->data);
    p = p->next;
  }
  printf("NULL \n");
}

 int count(){
   struct node *p = root;
   int count = 0;
   while(p != NULL){
    count++;
    p = p->next;
   }
   return count;
 }


void removeDuplicates(){
  struct node *p = root;
  struct node *q = p->next;

  while(q!=NULL){
    if(p->data == q->data){
        p->next = q->next;
        free(q);
        q = p->next;
    }
    else{
        p = q;
        q = q->next;
    }

  }

}

int main(){

  create();
  display();


  removeDuplicates();
  display();
}
