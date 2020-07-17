#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void push(char exp);
char pop();
int isEmpty();


struct node{
 int size;
 char *data;
 int top;
}st;

int balance(char exp[]){
 char check, temp;
 st.size = strlen(exp);
 st.data = (char *)malloc(st.size*sizeof(char));

 for(int i=0;exp[i] != '\0';i++){
    if(exp[i] == '(' || exp[i] == '{' || exp[i] == '['){
      push(exp[i]);
    }
    if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']'){
        if(isEmpty() == 1){
            return 0;
        }else{
	   //Following condition can also be checked using ascii code of parentheses
         check = pop();
         if(exp[i] == ')'){
            temp = '(';
            if(temp != check){
                return 0;
            }
         }

         if(exp[i] == '}'){
            temp = '{';
            if(temp != check){
                return 0;
            }
         }

         if(exp[i] == ']'){
            temp = '[';
            if(temp != check){
                return 0;
            }
         }
    }
 }
 }
 if(isEmpty() == 1){
    return 1;
 }
 else{
    return 0;
 }
}

void push(char exp){
   if(st.top == st.size-1){
     printf("stack is full\n");
     exit(0);
   }
   else{
     st.top++;
     st.data[st.top] = exp;
   }
}

char pop(){
  char check;
  if(st.top == -1){
    printf("stack underflow\n");
    return 'x';
  }
  else{
    check = st.data[st.top];
    st.top--;
    return check;
  }
}

int isEmpty(){
  if(st.top == -1){
    return 1;
  }
  else{
    return 0;
  }
}

int main(){
 char exp[100];
 st.top = -1;
 printf("Enter the expression\n");
 scanf("%s", &exp);
 if( balance(exp) == 1)
    printf("parentheses matching\n");
 else
    printf("parentheses do not matching\n");
}
