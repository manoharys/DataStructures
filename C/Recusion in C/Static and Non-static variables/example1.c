/*
  LOCAL VARIABLES =>> Every time a function is invoked new local variables are created in the stack,
         that are unrelated to any other invocation of the function.
         This is what makes local variables different from global variables.
  STATIC VARIABLES =>> Static variable are created in code section of main memory. Because of the static keyword, global = 0
         is only set when the program starts, not every time the function is called, as it would be without the keyword.
         Every time a function is invoked, new local variable are not created.
         This means that if you alter the value of global, it would keep this value the next time the function is called.
         This method can be used if you only use your recursive function once during your program; if you need to use it
         multiple times, I recommend that you use the alternative method above.
*/

 #include<stdio.h>

 int localVariables(int value);
 int staticVariables(int value);

 static int x;
 int main() {
   int value, result1, result2;
   printf("Value : ");
   scanf("%d", &value);
   result1 = localVariables(value);
   result2 = staticVariables(value);
   printf("local variables : %d \n static variables : %d \n", result1, result2);
 }

 int localVariables(int value) {
   if(value > 0) {
     return localVariables(value - 1) + value;
   }
   return 0;
 }

 int staticVariables(int value) {
   if(value > 0) {
    x++;
    return staticVariables(value - 1) + x;
   }
   return 0;
 }


