/*
   *** Factorial of N natural number using recursion ***
     general formula = n * (n-1)! , where n > 0 and 0! = 1
      n! = n * (n-1) * .... * 2 * 1
      5! = 5 * 4 * 3 * 2 * 1

   ***By using recursion***
     factorial of first 6 is           = 6 * 5 * 4 * 3 * 2 * 1

     this can be written/calculated as = 6 * (5 * 4 * 3 * 2 * 1)

     So for the given value n          = n * (n-1) * .... * 2 * 1

     this can be calculated as         = n * (n-1)!

     time complexity                   = O(n) [same for loops]
 */

 #include<stdio.h>

 int factorial(int n);

 int main() {
   int value;
   printf("value : ");
   scanf("%d", &value);
   if(value < 0) printf("Factorial of negative numbers is undefined\n");
   printf("%d ", factorial(value));
 }

 int factorial(int n) {
   if(n == 0) {
    return 1;
   }
   else {
    return n * factorial(n - 1);
   }
}








