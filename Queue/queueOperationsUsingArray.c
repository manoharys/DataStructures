#include<stdio.h>
#include<stdlib.h>

struct queue {
  int front;
  int rear;
  int *a;
  int size;
}q;

void enqueue(struct queue *a){
  if(q.rear == q.size - 1){
    printf("Queue is full\n");
  }else{
    int data;
    printf("Enter the data\n");
    scanf("%d", &data);
    q.a[++q.rear] = data;
 }
}

void dequeue(struct queue *a){
  if(q.front == q.rear || (q.front == -1 && q.rear == -1)){
    printf("Queue is empty\n");
  }else{
    printf("%d is deleted\n", q.a[++q.front]);
  }
}

void display(struct queue *a){
   if(q.front == q.rear || (q.front == -1 && q.rear == -1)){
    printf("Queue is empty\n");
  }
  else{
      for(int i=q.front+1;i<=q.rear;i++){
         printf("%d ", q.a[i]);
      }
      printf("\n");
 }
}

void count(struct queue *a){
  if(q.front == q.rear || (q.front == -1 && q.rear == -1)){
    printf("0 element present\n");
  }
  else{
    int count=0;
    for(int i=q.front+1;i<=q.rear;i++){
      count++;
    }
   printf("%d elements present\n", count);

  }
}
int main(){
  printf("Enter the size of the queue\n");
  scanf("%d", &q.size);
  q.a = (int*)malloc(q.size*sizeof(int));
  q.front = q.rear = -1;
  int choice;
  while(1){
    printf("Enter 1 to perform enqueue operation\n");
    printf("Enter 2 to  perform dequeue operation\n");
    printf("Enter 3 to display queue elements\n");
    printf("Enter 4 to count how many element present in the queue\n");
    scanf("%d", &choice);
    switch(choice){
      case 1: enqueue(&q.a);
              break;
      case 2: dequeue(&q.a);
              break;
      case 3: display(&q.a);
              break;
      case 4: count(&q.a);
              break;
      default: printf("Enter the valid choice\n");
    }
 }
}
