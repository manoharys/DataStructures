#include<stdio.h>
#include<stdlib.h>


struct array {
  int *a;
  int size;
  int length;
};

int main() {
  int n, choice, element, index;
  struct array arr;
  printf("Enter the size of an array\n");
  scanf("%d",&arr.size);

  arr.a = (struct array *)malloc(arr.size*sizeof(struct array));

  printf("Enter how many numbers to be inserted to an array\n");
  scanf("%d",&n);
  if(n > arr.size){
    printf("Error : array out of bounds\nSize of an array is %d", arr.size);
    return;
  }
  arr.length = n;
  printf("Enter initial elements to an array\n");
  for(int i=0;i<n;i++){
    printf("Enter %d element\n", i+1);
    scanf("%d",&arr.a[i]);
  }

while(1){

  printf("\n**********************************\n");
  printf("Enter 1 to display array element\n");
  printf("Enter 2 to append an element to an array\n");
  printf("Enter 3 to insert an element to specified index of an array\n");
  printf("Enter 4 to delete an element from array\n");
  printf("Enter 5 to exit\n");

  scanf("%d", &choice);

  switch(choice){
    case 1: display(arr);
            break;

    case 2: printf("Enter an element\n");
            scanf("%d", &element);
            append(&arr, element);
            break;

    case 3: printf("Enter the an index\n");
            scanf("%d", &index);
            printf("Enter an element\n");
            scanf("%d", &element);
            insert(&arr, index, element);
            break;

    case 4: printf("Enter the an index\n");
            scanf("%d", &index);
            deleteArray(&arr, index);
            break;

    case 5: return;

    default: printf("Enter the valid options\n");

  }
}
}



void display(struct array arr){
  printf("Array element:\n");
  for(int i=0;i<arr.length;i++){
    printf("%d ",arr.a[i]);
  }
}

void append(struct array *arr, int element){
   if(arr->length > arr->size){
     printf("ERROR : array out of bounds\n");
     return;
   }
   arr->a[arr->length] = element;
   arr->length++;
}

void insert(struct array *arr, int index, int element){
    if(arr->length > arr->size){
     printf("ERROR : array out of bounds\n");
     return;
   }
   for(int i=arr->length;i>index;i--){
      arr->a[i] = arr->a[i-1];
   }
   arr->a[index] = element;
   arr->length++;
}

void deleteArray(struct array *arr, int index){
   for(int i=index;i<arr->length;i++){
     arr->a[i] = arr->a[i+1];
   }
   arr->length--;
}






