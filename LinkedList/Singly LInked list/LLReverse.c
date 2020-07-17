/*
  ****Reversing the linked list******
   1) Reversing the linked list using auxiliary array.
   2) Reversing the linked list by reversing their links.
   3) Reversing the linked list using recursion.
*/

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

// reversing the data elements using auxiliary array(links are not modified links remains same)

 void reverseUsingAuxArray(){
    struct node *p = root;
    int i=0, *array;

    array = (int*)malloc(count()*sizeof(int));

    while(p != NULL){
      array[i] = p->data;
      p = p->next;
      i++;
    }

    p = root;
    i--;

    while(p!=NULL){
        p->data = array[i];
        p = p->next;
        i--;
    }
  }

// reversing node data by reversing their links

void reverseByLinks(){
  struct node *p = root;
  struct node *q = NULL, *r = NULL;

  while(p != NULL){
    r = q;
    q = p;
    p = p->next;

    q->next = r ;
  }
  root = q;
}

void reverseUsingRecursion(struct node *p, struct node *q){
  if(p!=NULL){
    reverseUsingRecursion(p->next, p);
    p->next = q;
  }
  else{
    root = q;
  }
}

int main(){

    create();
    display();
    printf("*****\n");
    reverseUsingAuxArray();
    display();
    printf("******\n");
    reverseByLinks();
    display();
    printf("******\n");
    struct node *q = NULL;
    reverseUsingRecursion(root, q);
    display();
}
