/* Insertion sort take O(n^2) for comparison & swapping.
   Bubble sort is a stable sorting algorithm(preserves the order of the elements).
   Bubble sort is Adaptable sorting algorithm.*/

#include<stdio.h>

void insertionSort(int a[], int n);

void insertionSort(int a[], int n){
  int x, j;
  for(int i=1;i<n;i++){
    x = a[i];
    j = i-1;
    while(j>-1 && a[j]>x){
        a[j+1] = a[j];
        j--;
    }
    a[j+1] = x;
  }
}


int main(){
  int n;
  printf("Enter the size of an array\n");
  scanf("%d", &n);
  int arr[n];
  printf("Enter the array elements\n");
  for(int i=0;i<n;i++){
    printf("Enter %d element\n", i+1);
    scanf("%d", &arr[i]);
  }

  insertionSort(arr, n);


  for(int i=0;i<n;i++){
    printf("%d ", arr[i]);
  }
}
