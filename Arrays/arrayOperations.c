#include<stdio.h>
#include<stdlib.h>

int main(){
  int size, choice, n;
  int index, element, ele, ind;
  int *p;
  printf("Enter the size of an array\n");
  scanf("%d", &size);
  n = size;
  p = (int*)malloc(size * sizeof(int));
  printf("Enter the array elements\n");
  for(int i=0;i<size;i++){
    printf("Enter the %d element\n", i+1);
    scanf("%d", &p[i]);
  }
  for(int i=0;i<size;i++){
    printf("%d ", p[i]);
  }
  printf("\n");
  while(1){
    printf("***********************************\n");
    printf("Enter 1 to get element of particular index\n");
    printf("Enter 2 to get max element of an array\n");
    printf("Enter 3 to get min element of an array\n");
    printf("Enter 4 to set an element \n");
    printf("Enter 5 to get sum(iterative) of an array\n");
    printf("Enter 6 to get sum(recursive) of an array\n");
    printf("Enter 7 to get average of an array\n");
    printf("Enter 8 to display array elements\n");

    scanf("%d", &choice);
    switch(choice) {
      case 1: printf("Enter index \n");
              scanf("%d", &index);
              if(index>=0 && index<n){
                 get(p, index);
              }else{
                 printf("Invalid index\n");
              }
              break;
      case 2: max(p, n);
              break;
      case 3: min(p, n);
              break;
      case 4: printf("Enter index\n");
              scanf("%d", &ind);
              if(ind>=0 && ind<n){
                printf("Enter element\n");
                scanf("%d", &ele);
                set(p, ind, ele);
              }else{
                printf("Invalid index\n");
              }
              break;
      case 5: sum(p, n);
              break;
      case 6: printf("SUM: %d\n",recursiveSum(p, (n-1)));
              break;
      case 7: average(p, n);
              break;
      case 8: display(p, n);
              break;
      default: printf("invalid choice\n");
    }
  }
}

void get(int p[], int index){
  printf("%d\n", p[index]);
}

void max(int p[], int n){
  int max = p[0];
  for(int i=0;i<n;i++){
    if(p[i] > max){
        max = p[i];
    }
  }
  printf("max : %d\n", max);
}

void min(int p[], int n){
  int min = p[0];
  for(int i=0;i<n;i++){
    if(p[i] < min){
        min = p[i];
    }
  }
  printf("min : %d\n", min);
}

void set(int *p, int n, int element){
  *(p+n) = element;
  printf("succesfully set\n");
}

void sum(int p[],int n){
  int total = 0;
  for(int i=0;i<n;i++){
    total += p[i];
  }
  printf("SUM : %d\n", total);
}

 int recursiveSum(int p[], int n){
  if(n>=0){
     return recursiveSum(p,n-1) + p[n];
  }else{
    return 0;
  }
}

void average(int p[], int n){
  int total = 0, avg;
  for(int i=0;i<n;i++){
    total += p[i];
  }
  printf("average : %d\n", total/n);
}

void display(int *p, int n)
{
    for(int i=0;i<n;i++){
    printf("%d ", *(p));
    p++;
  }
  printf("\n");
}
