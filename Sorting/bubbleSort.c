/* Bubble sort take O(n^2) for comparison & swapping.
   Bubble sort is a stable sorting algorithm(preserves the order of the elements).
   Bubble sort is Adaptable by introducing flag variable to
   check whether the swapping as been performed or not which reduces time complexity to O(n) when the given input lists are already sorted.
*/

#include<stdio.h>

void bubbleSort(int arr[], int n);
void swap(int *a, int *b);

void bubbleSort(int arr[], int n){
  int flag;
  for(int i=0;i<n-1;i++){
    flag = 0;
    for(int j=0;j<n-1-i;j++){
        if(arr[j] > arr[j+1]){
            flag=1;
            swap(&arr[j], &arr[j+1]);
        }
    }
    if(flag == 0){
        //elements are already sorted
        break;
    }
  }
}

void swap(int *a, int *b){
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
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

  bubbleSort(arr, n);


  for(int i=0;i<n;i++){
    printf("%d ", arr[i]);
  }
}
