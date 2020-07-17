/*
  Merging of an array
   merging of an is a binary operation since it require comparing and concatenating/combining an array
   We have to merge two arrays such that the array elements maintain their original order in the newly merged array.
   The elements of the first array precede the elements of the second array in the newly merged array

   Time complexity =  theta(m + n) // coping from m and n array to newly merged array

*/


#include<stdio.h>

int main(){
  int arr_1[10] = {1, 3, 4, 6, 8};
  int arr_2[10] = {2, 5, 6, 7, 9};

  printf("Array One ->>  [");
  for(int i=0;i<5;i++){
    printf("%d ", arr_1[i]);
  }
  printf("]\n");

  printf("Array Two ->>  [");
  for(int i=0;i<5;i++){
    printf("%d ", arr_2[i]);
  }
  printf("]\n");

  int arr_3[10] = {0};
  merge(arr_1, arr_2, arr_3);

  printf("After merging  ->>  [");
  for(int i=0;i<10;i++){
    printf("%d ", arr_3[i]);
  }
  printf("]\n");

}

void merge(int *arrOne, int *arrTwo, int *arrThree){

  int i = 0 ,j = 0, k = 0;
  while(i<5 && j<5){
      if(arrOne[i] < arrTwo[j]){
        arrThree[k++] = arrOne[i++];
      }
      else{
        arrThree[k++] = arrTwo[j++];
      }
   }
  for(;i<5;i++){
    arrThree[k++] = arrOne[i];
  }
  for(;j<5;j++){
    arrThree[k++] = arrTwo[j];
  }
 }
