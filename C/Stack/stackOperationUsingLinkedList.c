#include<stdio.h>
#include<stdlib.h>

struct node {
  int data;
  struct node* next;
}*top = NULL;

void push(){
 struct node *temp;
 temp = (struct node*)malloc(sizeof(struct node));
 if(temp==NULL){
    printf("Stack overflow\n");
 }
 else{
    int ele;
    printf("Enter an element to push on to the stack\n");
    scanf("%d", &temp->data);
    temp->next = NULL;
    if(top == NULL){
        top = temp;
    }else{
        temp->next = top;
        top = temp;
    }
 }
}

void pop(){
  struct node *p = top;
  if(p == NULL){
    printf("Stack underflow\n");
  }else{
    printf("%d is deleted\n", p->data);
    top = p->next;
    p->next = NULL;
    free(p);
  }
}

void display(){
 struct node *p = top;
 if(p == NULL){
    printf("stack is empty\n");
 }
 else{
 while(p != NULL){
    printf("%d ", p->data);
    p = p->next;
 }
 printf("\n");
 }
}

void peek(){
 int pos;
 struct node *p = top;
 if(p == NULL){
    printf("stack is empty\n");
 }else{
     printf("Enter the position \n");
     scanf("%d", &pos);
    if(pos>0 && pos<=count()){
     for(int i=1;i<pos;i++){
        p = p->next;
     }
     printf("Value -> %d\n", p->data);
    }else{
      printf("Enter the valid position\n");
    }
 }
}

int count(){
  struct node *p = top;
  int count = 0;
  while(p!=NULL){
    count++;
    p  =  p->next;
  }
  return count;
}

void isEmpty(){
  if(top == NULL){
    printf("Stack is empty\n");
  }else{
    printf("Stack contains element\n");
  }
}

void isFull(){
  struct node *temp;
  if(temp == NULL){
    printf("Stack overflow\n");
  }
  else{
    printf("stack is not full\n");
  }
}

int main(){
  int choice;
  while(1){
      printf("Enter 1 to push an element to the stack\n");
      printf("Enter 2 to pop an element to the stack\n");
      printf("Enter 3 to display stack elements\n");
      printf("Enter 4 to know the peek value\n");
      printf("Enter 5 to check stack is empty\n");
      printf("Enter 6 to check stack is full\n");
      scanf("%d", &choice);
    switch(choice){
      case 1: push();
              break;
      case 2: pop();
              break;
      case 3: display();
              break;
      case 4: peek();
              break;
      case 5: isEmpty();
              break;
      case 6: isFull();
              break;
      default: printf("Enter the valid options\n");
    }
  }


}
