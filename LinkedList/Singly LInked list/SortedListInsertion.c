#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node *next;
}*root = NULL;

void create(int a[], int size){
  struct node *temp;
  for(int i=0;i<size;i++){
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = a[i];
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
  struct node *p= root;
  while(p != NULL){
    printf("%d->", p->data);
    p = p->next;
  }
  printf("NULL\n");
}

 void insertIntoSortedLinkedList(){
       struct node *temp;

       temp = (struct node*)malloc(sizeof(struct node));

       printf("Enter the node data\n");
       scanf("%d", &temp->data);
       temp->next = NULL;

       struct node *p = root, *q;
       if(temp->data < p->data){
        temp->next = root;
        root = temp;
        return;
       }
      else{
       while(p && temp->data > p->data){
          q = p;
          p = p->next;
       }
       temp->next = p;
       q->next = temp;
  }
 }


int main(){
  int a[] = {10, 20, 30, 40, 50, 60};
  create(a, sizeof(a)/sizeof(a[0]));
  display();
  insertIntoSortedLinkedList();
  display();
insertIntoSortedLinkedList();
  display();
insertIntoSortedLinkedList();
  display();
insertIntoSortedLinkedList();
  display();

}

