/*Time complexity
   Best case => O(1) [if the elements present at first index]
   worst/Avg => O(n) [element present at middle/last/not present]

   *****Improving linear search******
    If we're searching for an element in an array there is a possibility that we might
    search for a same element again, if so this methods improves linear search
      1) Transposition -> whenever we find key element, we swap key element by previous element
                          this gradually this decrease time complexity.
      2) MoveToHead/MoveToFront -> Swap the key element with the first element of an array, So if we
                                   search for a same element again it can be found in constant time O(1)
*/


#include<stdio.h>

int size, ele;
int main(){
  printf("Enter the size of an array\n");
  scanf("%d", &size);
  int arr[size];
  printf("Enter values to an array\n");
  for(int i=0;i<size;i++){
    printf("Enter %d element \n", i+1);
    scanf("%d", &arr[i]);
  }
  printf("Array element\n");
  for(int i=0;i<size;i++){
    printf("%d ",arr[i]);
  }
  printf("\nEnter key element\n");
  scanf("%d", &ele);
  linearSearch(arr);
  transposition(arr);
  moveToHead(arr);
}

void linearSearch(int array[]){
   int found, flag=0;
   for(int i=0;i<size;i++){
     if(array[i] == ele){
        found = i;
        flag = 1;
        break;
     }
   }
   if(flag != 0){
    printf("\nKey element found at index %d \n array[%d] = %d\n", found, found, array[found]);
   }
   else{
    printf("Key not found\n");
   }
}

void transposition(int *array[]){
   int found, flag=0;
   printf("--------\n");
   for(int i=0;i<size;i++){
     if(array[i] == ele){
        found = i;
        flag = 1;
        break;
     }
   }
   if(flag != 0){
    printf("\nKey element found at index %d \n array[%d] = %d\n", found, found, array[found]);
    swap(&array[found], &array[found-1]);
   }
   else{
    printf("Key not found\n");
   }
}

void moveToHead(int *array[]){
int found, flag=0;
   printf("--------\n");
   for(int i=0;i<size;i++){
     if(array[i] == ele){
        found = i;
        flag = 1;
        break;
     }
   }
   if(flag != 0){
    printf("\nKey element found at index %d \n array[%d] = %d\n", found, found, array[found]);
    swap(&array[found], &array[0]);
   }
   else{
    printf("Key not found\n");
   }
}


void swap(int *a, int *b){
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}














