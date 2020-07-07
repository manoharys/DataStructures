/*
  ******Reversing an array********
  1) using auxiliary array
        time-complexity - O(n)
  2) swapping array element
        time-complexity - o(n)
*/

#include<stdio.h>
#include<stdlib.h>

struct array {
  int *a;
  int length;
};

int main(){
   struct array arr;
   printf("Enter the size of an array\n");
   scanf("%d", &arr.length);

   arr.a = (int *)malloc(arr.length*sizeof(int));

   printf("Enter the array elements\n");

   for(int i=0;i<arr.length;i++){
    printf("Enter the %d element\n", i+1);
    scanf("%d", &arr.a[i]);
   }
   printf("Arrray elements :\n");
   display(&arr);
   printf("******************\n");
   reverseOne(&arr);
   display(&arr);
   printf("*****************\n");
   reverseTwo(&arr);
   display(&arr);
}

//using auxiliary array
void reverseOne(struct array *arr){
   int i,j;
   int *aux;

   aux = (int*)malloc(arr->length*sizeof(int));

   for(i=(arr->length-1),j=0;i>=0;i--,j++){
       aux[j] = arr->a[i];
   }
   for(j=0;j<arr->length;j++){
     arr->a[j] = aux[j];
   }
}

void display(struct array *arr){
  for(int i=0;i<arr->length;i++){
    printf("%d ", arr->a[i]);
  }
  printf("\n");
}

void reverseTwo(struct array *arr){
  int i,j;
  for(i=0,j=arr->length-1;i<j;i++,j--){
      swap(&arr->a[i], &arr->a[j]);
  }
}

void swap(int *a, int *b){
   int temp;
   temp = *a;
   *a = *b;
   *b = temp;
}


