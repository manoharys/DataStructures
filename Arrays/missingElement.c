/*
  **********Finding the missing element in an array***************

  1) missing element in first n natural number
    ex : array[] = {1, 2, 3 ,5}
         In above example 4 is missing, to find missing element utilize formula -> n*(n+1)/2
         * using above formula n*(n+1)/2 = 5*(5+1)/2 = 15 is the sum.
         * calculate sum of an array -> 11 is the sum.
         * take difference 15 - 11 -> 4, So four is the missing element.

  2) Finding missing element of natural number but not starting from one
    ex : array[] = {6, 7, 8, 10}
         In above example 9 is missing, to find the missing element utilize array indices.
         * subtract a[0] from 0 for 1st element that is 6 - 0 = 6
           subtract a[1] from 1 for 2nd element that is 7 - 1 = 6
           and 3rd element 8 - 2 = 6
           4th element 10 - 3 = 7 so the difference is changing at the index 3, so add the result 6 to the index 3
           and the missing element 6 + 3 = 9 is the missing element
*/


#include<stdio.h>
#include<stdlib.h>



int main(){

 int a[] = {1, 2, 4, 5, 6};
 findMissing(a, 5);

 int b[] = {6, 7, 8, 10, 11};
 findMissing2(b, 5);
}


void findMissing(int a[], int size){
 int sum = 0, s = 0;
 for(int i=0;i<size;i++){
   sum += a[i];
 }
 int n = a[size-1];
 s = n*(n+1)/2;

 int diff = s - sum;
 printf("%d is the missing element in an array\n", diff);
}

void findMissing2(int b[], int size){
  int diff = b[0] - 0;
  for(int i=0;i<size;i++){
    if(b[i] - i != diff){
        printf("%d is the missing element in an array\n", diff + i);
        break;
    }
  }
}
