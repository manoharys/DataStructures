#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void push(char exp);
int precedence(char exp);
int isOperand(char exp);
char pop();
char stackTop();

struct node {
  int top;
  char *a;
  int size;
}st;

char* toPostFix(char* expression){
  st.size = strlen(expression);
  st.a = (char*)malloc((st.size + 2)*sizeof(char));
  char* postfix = (char*)malloc((st.size + 1)*sizeof(char));


  int i=0,j=0;
  while(expression[i] != '\0'){
    if(isOperand(expression[i]) == 1){
        postfix[j++] = expression[i++];
    }
    else{
       if(precedence(expression[i]) > precedence(stackTop())){
         push(expression[i++]);
       }
       else{
         postfix[j++]=pop();
       }
    }
  }
  while(st.top != -1){
    postfix[j++] = pop();
  }
  postfix[j] = '\0';

  return postfix;
}

int isOperand(char exp){
   if(exp == '+' || exp == '-' || exp == '*' || exp == '/'){
    return 0;
   }
   else{
    return 1;
   }
}

int precedence(char exp){

  if(exp == '+' || exp == '-'){
    return 1;
  }
  if(exp == '/' || exp == '*'){
    return 2;
  }
  return 0;

}

void push(char exp){
   if(st.top == st.size-1){
     printf("stack overflow\n");
     return;
   }
   else{
     st.top++;
     st.a[st.top] = exp;
   }
}

char pop(){
  if(st.top == -1){
    printf("Stack underflow\n");
    return 0;
  }
  else{
    char ele = st.a[st.top];
    st.top--;
    return ele;
  }
}

char stackTop(){
  if(st.top == -1){
    return '9999';
  }
  else{
    return st.a[st.top];
  }
}
int main(){
 char expression[100];
 char *postFixExpression;

 st.top = -1;
 printf("Enter the infix expression\n");
 scanf("%s", expression);

 postFixExpression = toPostFix(&expression);

 printf("%s", postFixExpression);

}


