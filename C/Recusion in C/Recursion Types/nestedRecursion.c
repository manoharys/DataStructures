/*
   *** Nested Recursion ***
     A recursive function will passes the parameter as recursive call(function inside a function)
     eg : void fun(n)
            if(n>0)
                return n
            else
                return fun(fun(n)) //parameter is a recursive function
 */

 #include<stdio.h>

int nestedRecursive(int n);

 int main() {
   int value;
   printf("value : ");
   scanf("%d", &value);
   printf("%d ", nestedRecursive(value));
 }

 int nestedRecursive(int n) {
   if(n > 100) {
     return n-10;
   }
   else{
     return nestedRecursive(nestedRecursive(n + 11));
   }
 }








