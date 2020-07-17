/*
   *** Indirect Recursion ***
    If the function f1 calls another function f2 and f2 calls f1 then it is indirect recursion (or mutual recursion).
    This is a two-step recursive call: the function calls another function to make a recursive call.
 */

 #include<stdio.h>

 void indirectOne(int n);
 void indirectTwo(int n);

 int main() {
   int value;
   printf("value : ");
   scanf("%d", &value);
   indirectOne(value);
 }

 void indirectOne(int n) {
   if(n > 0) {
    printf("%d ",n);
    indirectTwo(n-1);
   }
 }

 void indirectTwo(int n) {
   if(n > 0) {
    printf("%d ", n);
    indirectOne(n/2);
   }
 }








