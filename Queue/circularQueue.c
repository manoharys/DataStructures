#include<stdio.h>
#include<stdlib.h>

struct queue{
  int rear;
  int front;
  int size;
  int *a;
}q;

void create(){
  q.rear=q.front=0;
  printf("Enter the size of a queue\n");
  scanf("%d",  &q.size);
  q.a = (int*)malloc(q.size*sizeof(int));
}

void enqueue(){
 if((q.rear+1)%q.size == q.front){
    printf("Queue is full\n");
 }else{
    int ele;
    printf("Enter element\n");
    scanf("%d", &ele);
    q.rear = (q.rear + 1)%q.size;
    q.a[q.rear] = ele;
 }
}

void dequeue(){
  if(q.front == q.rear){
    printf("Queue is empty\n");
  }else{
    q.front = (q.front + 1)%q.size;
    printf("%d is deleted\n", q.a[q.front]);
  }
}

void display(){
  int i = q.front+1;
  do{
    printf("%d" , q.a[i]);
    i = (i+1)%q.size;
  }while(i != (q.rear + 1)%q.size);
  printf("\n");
}
int main(){
  int choice;
  create();
  while(1){
    printf("Enter 1 to enqueue\n");
    printf("Enter 2 to dequeue\n");
    printf("Enter 3 to display\n");
    scanf("%d", &choice);
    switch(choice){
      case 1: enqueue();
              break;
      case 2: dequeue();
              break;
      case 3: display();
              break;
      default: printf("Enter the valid choice\n");
    }
  }

}
