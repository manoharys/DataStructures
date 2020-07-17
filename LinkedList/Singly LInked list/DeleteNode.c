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

void deleteNode(){
  struct node *p = root;
  int pos;
  printf("Enter the position you want to delete & there are %d nodes in the list\n", count());
  scanf("%d", &pos);
  if(pos>0 && pos<=count()){
    if(pos == 1){
        root = root->next;
        printf("%d is deleted from the node\n", p->data);
        free(p);
    }
    else{
        int i=1;
        struct node *q = NULL;
        while(i<pos){
            q = p;
            p = p->next;
            i++;
        }
        printf("%d is deleted from the node \n", p->data);
        q->next = p->next;
        free(p);
    }
  }
  else{
    printf("Enter the valid position\n");
  }

}

int main(){
  printf("%d count\n", count());
  create();
  display();
  printf("%d count\n", count());

  deleteNode();
  display();

  deleteNode();
  display();

  deleteNode();
  display();
  deleteNode();
  display();


}
