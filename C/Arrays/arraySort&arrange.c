/*
  1) Inserting an element in a sorted array
  2) Checking if an array is sorted
  3) Arranging -ve element on lift side of an array
*/

#include<stdio.h>

int main(){
  int arr[] = {1, 2, 3, 5, 6, 7, 8};
  int size = 7;
  printf("array element are \n");
  display(&arr, size);
  insert(&arr, 4, size);
  display(&arr, size);
  printf("*********************************\n");

  int arr2[] = {1, 2, 4 ,5, 3, 1, 6};
  display(&arr2, size);
  printf("Checking if array is sorted :-\n ");
  printf("%d\n", isSorted(&arr2, size));
  display(&arr2, size);

  printf("*********************************\n");

  int arr3[] = {1, -2, 3, -44, 2, 3, 4, -5, -6, 44};
  printf("Array elements before arranging \n");
  size = 10;
  display(&arr3, size);
  arrange(&arr3, size);
  printf("Array elements after arranging \n");
  display(&arr3, size);
}

void display(int *arr, int size){
  for(int i=0;i<size;i++){
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void insert(int *arr, int n, int size){
  int i=size-1;
  while(n<arr[i])
  {
    arr[i+1] = arr[i];
    i--;
  }
  arr[i+1] = n;
}

int isSorted(int *arr, int size){
  for(int i=0;i<size-1;i++){
    if(arr[i] > arr[i+1]){
        printf("sorted\n");
        return;
    }
    else{
        printf("array is not sorted\n");
        return;
    }
  }
}

void arrange(int *arr, int size){
  int i=0, j=size-1;
  while(i<j){
    while(arr[i]<0){
        i++;
    }
    while(arr[j]>0){
        j--;
    }
    if(i<j){
        swap(&arr[i], &arr[j]);
    }
  }
}


void swap(int *a, int *b){
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}
