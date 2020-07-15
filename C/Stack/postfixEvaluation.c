#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
 int top;
 int size;
 char *a;
 int *b;
}st;


char* toPostfix(char *exp);
void push(char exp);
char pop();
int isOperand(char exp);
int precedence(char exp);
char stackTop();

char * toPostfix(char *exp){
   int i=0,j=0;
   st.size = strlen(exp);
   st.a = (char*)malloc((st.size + 1)*sizeof(char));
   char* postfix = (char*)malloc((st.size + 1)*sizeof(char));
   while(exp[i] != '\0'){
     if(isOperand(exp[i]) == 1){
        postfix[j++] = exp[i++];
     }
     else{
        if(precedence(exp[i]) > precedence(stackTop())){
            push(exp[i++]);
          }
        else{
         postfix[j++] = pop();
       }
     }
   }
   while(st.top != -1){
     postfix[j++] = pop();
   }
    postfix[j] = '\0';
  return postfix;
}

char stackTop(){
  if(st.top == -1){
    return '0';
  }
  else{
    return st.a[st.top];
  }
}


void push(char ele){
   if(st.top == st.size - 1)
     {
         printf("stack overflow\n");
         return;
     }
     else{
        st.top++;
        st.a[st.top] = ele;
     }
}

char pop(){
  char ele;
  if(st.top == -1){
    printf("stack empty\n");
    return 'f';
  }else{
    ele = st.a[st.top];
    st.top--;
    return ele;
  }
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
  else if(exp == '*' || exp == '/'){
    return 2;
  }
  return 0;
}

void pushInt(int ele){

   if(st.top == st.size - 1)
     {
         printf("stack overflow\n");
         return;
     }
     else{
        st.top++;
        st.b[st.top] = ele;
     }
}

int popInt(){
  int ele;
  if(st.top == -1){
    printf("stack empty\n");
    return;
  }else{
    ele = st.b[st.top];
    st.top--;
    return ele;
  }
}
///evaluating postfix expression
int postfixEval(char *exp){
  st.b = (int*)malloc((st.size+1)*sizeof(int));
  int i=0;
  while(exp[i] != '\0'){
    if(isOperand(exp[i]) == 1){
        pushInt(exp[i] - '0');

        i++;
    }
    else{
       int second = popInt();

       int first = popInt();

       int res;
       if(exp[i] == '+'){
         res = first + second;
       }
       if(exp[i] == '-'){
         res = first - second;
       }
       if(exp[i] == '*'){
         res = first * second;
       }
       if(exp[i] == '/'){
         res = first/second;
       }

      pushInt(res);
      i++;
    }
  }
  return st.b[st.top];
}

int main(){
  st.top = -1;
  char exp[10];
  char *postfixExp;
  printf("Enter the infix expression\n");
  scanf("%s", exp);

  postfixExp = toPostfix(&exp);
  printf("Postfix fix expression -> %s\n", postfixExp);

  st.top = -1;
  int result = postfixEval(postfixExp);
  printf("Result of postfix expression %d", result);

}
