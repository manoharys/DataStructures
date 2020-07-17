/*
  1. Counting number of nodes present in the linked list using loop & recursion.

  2. Finding the sum of elements present in the linked list using loops & recursion.

  3. Finding Maximum and minimum element present in the linked list using loops & recursion.
  
  4. Searching a key element using loops and recursion.
*/



#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node *next;
}*root = NULL;

void append(){
  struct node *temp;
  int n;
  printf("Enter how many data node you want \n");
  scanf("%d", &n);
  for(int i=0;i<n;i++){
   temp = (struct node*)malloc(sizeof(struct node));
   printf("Enter %d node data\n", i+1);
   scanf("%d", &temp->data);
   temp->next = NULL;

   if(root == NULL){
     root = temp;
   }
   else{
     struct node *p = root;
     while(p->next != NULL){
        p = p->next;
     }
     p->next = temp;
   }
  }
}

//Counting number of nodes in linked list

  int count(struct node *p){
    int count = 0;

    while(p!=NULL){
        count++;
        p=p->next;
    }
    return (count);
  }

void display(struct node *p   ){
   while(p != NULL){
    printf("%d->", p->data);
    p = p->next;
   }
   printf("NULL");
}

int countRecursion(struct node *p){
  static int count = 0;
  if(p != NULL){
    count++;
    countRecursion(p->next);
  }
  return count;
}

int sumOfNodes(struct node *p){
  int sum = 0;
  while(p != NULL){
    sum += p->data;
    p = p->next;
  }
  return (sum);
}

int sumOfNodesRecursion(struct node *p){
   static int sum = 0;

   if(p != NULL){
      sum += p->data;
      sumOfNodesRecursion(p->next);
   }

   return (sum);

}

int max(struct node *p){
  static max = 0;

  while(p != NULL){
    if(p->data > max){
        max = p->data;
        p = p->next;
    }
    else{
        p = p->next;
    }
  }
  return max;
}

 int maxRecursion(struct node *p){
   static int m = 0;
   if(p != NULL){
    if(p->data > m){
        m = p->data;
    }
    maxRecursion(p->next);
   }
   return (m);
 }


int min(struct node *p){
  static int min;
  min = p->data;

  while(p != NULL){
    if(p->data < min){
        min = p->data;
        p = p->next;
    }
    else{
        p = p->next;
    }
  }
  return min;
}
 int mm;
 int minRecursion(struct node *p, int init){

   if(init == 0){
     mm = p->data;
   }
  if(p != NULL){
    if(p->data < mm){
        mm = p->data;
    }
    init++;
    minRecursion(p->next, init);
   }
   return (mm);
 }

 void searchElement(struct node *p, int key){
   int  node=1, found = 0;

   while(p != NULL){
      if(key == p->data){
         printf("Key element %d found at node %d\n", key, node);
         found = 1;
         break;
      }
      else{
        node++;
        p = p->next;
      }
   }
   if(found == 0){
    printf("Key element not found\n");
   }
 }

 void searchRecursive(struct node *p, int key){
   static int nodeCount;
   int found = 0;
   if(p != NULL){
     if(key == p->data){
        printf("Key element %d is found at node %d\n", key, ++nodeCount);
        found = 1;
        return;
     }
     else{
        ++nodeCount;
        searchRecursive(p->next, key);
     }
   }
   if(found == 0){
    printf("Key element is not found\n");

   }
 }


int main(){

  append();
  display(root);
  printf("\nNumber of nodes = %d\n", count(root));
  printf("Number of nodes using recursion = %d\n", countRecursion(root));
  printf("SUM of nodes = %d\n", sumOfNodes(root));
  printf("SUM of nodes using recursion = %d \n", sumOfNodesRecursion(root));
  printf("Maximum element in the linked list = %d\n", max(root));
  printf("Maximum element in the linked list using recursion = %d\n", maxRecursion(root));
  printf("Minimun element in the linked list = %d\n", min(root));
  printf("Minimum element in the linked list using recursion = %d\n", minRecursion(root, 0));

  int key;
  printf("Enter the key element to be searched\n");
  scanf("%d", &key);
  printf("Using loops\n");
  searchElement(root, key);
  printf("Using recursion\n");
  searchElement(root, key);
}

