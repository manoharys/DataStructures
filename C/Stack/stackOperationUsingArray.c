#include<stdio.h>
#include<stdlib.h>

struct stack {
  int size;
  int top;
  int *s;
}st;

void create(){
  printf("Enter the size of the stack\n");
  scanf("%d", &st.size);
  st.s = (int *)malloc(st.size*sizeof(int));
}

void display(){
  if(st.top == -1){
    printf("NO elements in the stack\n");
  }
  else{
  for(int i=st.top;i>=0;i--){
    printf("%d ", st.s[i]);
  }
  printf("\n");
}
}

void push(){
 int ele;
 printf("Enter an element to push into stack\n");
 scanf("%d", &ele);
 if(st.top < st.size - 1){
   st.top++;
   st.s[st.top] = ele;
 }else{
   printf("Stack overflow\n");
 }
}

void pop(){
  if(st.top == -1){
    printf("Stack underflow\n");
  }else{
    printf("%d is deleted\n", st.s[st.top--]);
  }
}

void top(){
  printf("top => %d\n", st.top);
}

void isEmpty(){
  if(st.top == -1){
    printf("Stack is empty\n");
  }
  else{
    printf("Stack contains elements\n");
  }
}

void isFull(){
  if(st.top == st.size - 1){
   printf("Stack is full\n");
  }else{
   printf("Stack is not full\n");
  }
}

void peek(){
  int pos;
  if(top == -1){printf("stack is empty\n");}
  else{
      printf("Enter the position\n");
      scanf("%d", &pos);
      if(((st.top-pos) + 1) >= 0){
        printf("element at %d position is %d \n", pos, st.s[((st.top-pos)+1)]);
      }else{
        printf("Invalid position\n");
      }
    }
}
int main(){
 int choice;
 st.top = -1;
  create();

 while(1){
    printf("Enter 1 to push an element into the stack\n");
    printf("Enter 2 to pop an element from the stack\n");
    printf("Enter 3 to display an element from the stack\n");
    printf("Enter 4 to know top element\n");
    printf("Enter 5 to check whether stack is empty\n");
    printf("Enter 6 to check stack is full\n");
    printf("Enter 7 to know the peek value\n");
    scanf("%d", &choice);

    switch(choice){
      case 1: push();
              break;
      case 2: pop();
              break;
      case 3: display();
              break;
      case 4: top();
              break;
      case 5: isEmpty();
              break;
      case 6: isFull();
              break;
      case 7: peek();
              break;

      default: printf("Enter the valid options\n");
    }
 }

 return 0;
}
