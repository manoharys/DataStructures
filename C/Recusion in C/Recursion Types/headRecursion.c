/*
   *** Head Recursion ***
   The first statement in a function is a recursive call to the same function is called head recursion.
   ex -> void fun(n){
           if(n > 0)
             fun(n-1)  /* first statement is a recursive call
             print "n"
         }
        All this above operation is performed at returning time only.

      suppose
       -> void fun(n) {
            if(n > 0)
              print "n"
              fun(n - 1)  /* This example cannot be head recursion since recursive call is not a first statement
              print "n"
 */

 #include<stdio.h>

 void headRecursion(int n);

 int main() {
    int n;
    printf("Value : ");
    scanf("%d", &n);
    headRecursion(n);
 }

 void headRecursion(int n) {
   if(n > 0) {
     headRecursion(n - 1);
     printf("%d \n", n);
   }
 }








