/*
   *** Tail Recursion ***
   The last statement in a function, is a recursive call to the same function is called tail recursion.
   ex -> void fun(n){
           if(n > 0)
             print "n"
             fun(n-1)  /* Last statement is a recursive call
         }
        All this above operation is performed at calling time only and function will not perform any operation at returning time.

      suppose
       -> void fun(n) {
            if(n > 0)
              print "n"
              fun(n - 1) + n  /* n is computed to the recursive call at returning time, so it cannot be last statement in a function.
 */

 #include<stdio.h>

 void tailRecursion(int n);

 int main() {
    int n;
    printf("Value : ");
    scanf("%d", &n);
    tailRecursion(n);
 }

 void tailRecursion(int n) {
   if(n > 0) {
     printf("%d \n", n);
     tailRecursion(n - 1);
   }
 }








