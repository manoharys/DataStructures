#include<stdio.h>
#include<stdlib.h>

struct bank {
  int adminPassword;
  char adminName[20];
  char name[15];
  int accountNo;
  float deposite;
  float balance;
};

void display(struct bank *canara,int size){

   for(int i=0;i<size;i++){
    printf("*******CUSTOMER DETAILS*******\n");
    printf("%d customer Details\n",i+1);
    printf("------------------------\n");
    printf("Name : %s\n",(canara+i)->name);
    printf("AccNo: %d\n",(canara+i)->accountNo);
    printf("Balance: %f\n",(canara+i)->balance);
        printf("------------------------\n");
  }
}

int validate(int accNo, struct bank *canara, int size){
   int flag = 0;
   for(int i=0;i<size;i++){
     if((canara + i)->accountNo == accNo){
        flag = 1;
        return i;
     }
   }
   if(flag==0){
    printf("Account Not found\n");
    return -1;
   }
}

void deposite(float amt, struct bank *canara, int customer){
  (canara+customer)->balance += amt;
   printf("You deposited %f rupees\n",amt);
}

void viewBalance(struct bank *canara, int customer){
   printf("Your current balance is %2f \n",(canara+customer)->balance);
}

void viewProfile(struct bank *canara, int customer) {
  printf("------------------\n");
  printf("Name : %s \n", (canara+customer)->name);
  printf("Account no : %d \n",(canara+customer)->accountNo);
  printf("------------------\n");
}

int validateAdminLoggin(int pass, struct bank *canara){
  if(canara->adminPassword == pass){
    return 1;
  }
  else{
    printf("Invalid password\n");
    return -1;
  }
}

void viewAdminProfie(struct bank *canara) {
  printf("Name : %s\n", canara->adminName);
  printf("Password : %d\n", canara->adminPassword);

}



int main() {
  struct bank xyz,*canara;
  int size;
  int accNo, choice, customer;

  //Customer login
  printf("Enter the no of customers\n");
  scanf("%d",&size);

  canara = (struct bank*)malloc(size*sizeof(struct bank));

  //Admin login
      printf("----------Admin section------------\n");
      printf("Enter Admin name : ");
      scanf("%s",canara->adminName);
      printf("Enter admin password : ");
      scanf("%d", &canara->adminPassword);
 printf("----------Customer section------------\n");
  for(int i=0;i<size;i++){
    printf("Enter the customer %d informations\n",i+1);
    printf("Enter the name of the customer\n");
    scanf("%s",&(canara+i)->name);
    printf("Enter the account number\n");
    scanf("%d",&(canara+i)->accountNo);
    printf("Enter the initial deposite\n");
    scanf("%f",&(canara+i)->balance);
  }

 int loggin,pass,validPass,adminSelection;
while(1){
    printf("------------------\n");
    printf("LOGGING As \n");
    printf("click 1 to loggin as ADMIN\n");
    printf("click 2 to loggin as CUSTOMER\n");
    scanf("%d", &loggin);
    switch(loggin){

    case 1 : printf("Enter your password : ");
             scanf("%d", &pass);
             validPass = validateAdminLoggin(pass, canara);
             if(validPass != -1){
                printf("********WELCOME %s ******** \n",(canara)->adminName);
                printf("Enter 1 to see entire customer database\n");
                printf("Enter 2 to see your profile\n");
                printf("Enter 3 to logout\n");
                scanf("%d", &adminSelection);
                switch(adminSelection){
                  case 1 : display(canara,size);
                           break;
                  case 2 : viewAdminProfie(canara);
                           break;
                  case 3 : printf("****Thanks for using canara bank*******\n");
                           return;
                  default : printf("Invalid selection\n");

                }
             }
             break;

    case 2 :printf("Choose your account By entering your Account number\n");
            scanf("%d", &accNo);
            customer = validate(accNo, canara, size);
            if( customer != -1){
            printf("********WELCOME %s ******** \n",(canara+customer)->name);
            printf("Click 1 to deposite money \n");
            printf("Click 2 to check your balance\n");
            printf("Click 3 to view your profile \n");
            printf("Click 4 to logout\n");
            scanf("%d",&choice);
            switch(choice){
              float depositeAmt;
              case 1 : printf("Enter the deposite amount\n");
                       scanf("%f",&depositeAmt);
                       deposite(depositeAmt, canara, customer);
                       break;
              case 2 : viewBalance(canara, customer);
                       break;
              case 3 : viewProfile(canara, customer);
                       break;
              case 4 : printf("****Thanks for using canara bank*******\n");
                       return;
              default : printf("Please Choose the valid statement\n");
            }
       }
 }
}
}










