/*
   *** Tree Recursion ***
    If a recursive function calling itself more than one time then its said to be tree recursion
    Ex -> void fun(n){
            print "n"
            ------
            fun(n-1)
            ------
            fun(n-1)
    }
    for n value there will be n+1 level tree and the recursive call would be sum of GP series
     i.e for n value there will (2^n+1)-1 calls and its time complexity would be ~ O(2^n)

    ex : n=3 -> n+1 tree levels = 4
             -> no. of calls (2^3+1)-1 = 15 recursive calls
 */

 #include<stdio.h>

 void treeRecursion(int n);

 int main() {
   int value;
   printf("value : ");
   scanf("%d", &value);
   treeRecursion(value);
 }

 void treeRecursion(int n) {
   if(n > 0) {
     printf("%d, ", n);
     treeRecursion(n-1);
     treeRecursion(n-1);
   }
 }







