#include<stdio.h>
#include<stdlib.h>

struct Node {
  int data;
  struct Node *next;
}*first = NULL;

void create(int *a, int n){
  struct Node *temp, *p;

  first = (struct Node*)malloc(sizeof(struct Node));
  first->data = a[0];
  first->next = NULL;
  p = first;

  for(int i=1;i<n;i++){
    temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = a[i];
    temp->next = NULL;
    p->next = temp;
    p = temp;
  }
}

 void display(struct Node *p){
   while(p != NULL){
     printf("%d->", p->data);
     p=p->next;
   }
 }

int main(){
  int a[] = {1, 2, 3, 4, 5};

  create(a, 5);
  display(first);

  printf("%d ", first->next);

}
