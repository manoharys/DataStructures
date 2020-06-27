/*
   *** Finding sum of N natural number using recursion ***
     natural no = {1, 2, 3, 4, 5,.....n}
     formula for finding sum of N natural no. = n * (n + 1)/2
     Time complexity = O(1)

   ***By using recursion***
     sum of first 6 natural no.        = 1 + 2 + 3 + 4 + 5 + 6

     this can be written/calculated as =(1 + 2 + 3 + 4 + 5) + 6

     so if there are n terms           = 1 + 2 + 3 + 4 + .....+(n-1)+n

     this can be calculated as          = sumOf(n-1) + n

     time complexity                   = O(n) [same for loops]
 */

 #include<stdio.h>

int SumOfNaturalNo(int n);

 int main() {
   int value;
   printf("value : ");
   scanf("%d", &value);
   printf("%d ", SumOfNaturalNo(value));
 }

 int SumOfNaturalNo(int n) {
   if(n == 0) {
      return 0;
   }
   else {
      return SumOfNaturalNo(n-1) + n;
   }
 }







