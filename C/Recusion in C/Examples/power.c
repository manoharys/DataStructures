/*
   program to calculate the power using recursion

   eg : 2^5 = 2 * 2 * 2 * 2 * 2;
        m^n = m * m * m *...for n times

   i)   power(m, n) = (m * m * m ... * n-1 times) * m
        therefore,
        power(m, n) = (m, n-1) * m  where  n > 0

   ii)  We can improve the first method by reducing power to half
        eg : 2^8 is same as (2 * 2)^4  //for even numbers
             2^9 is same as 2*(2*2)^4  //for odd numbers multiply with 2

        therefore power(m, n) = power((m * m), n/2)
                  power(m, n) = power((m * m), n/2) * m);
*/

 #include<stdio.h>

 int power(int m, int n);
 int powerUpdated(int m, int n);

 int main() {
   int m, n;
   printf(" M value : ");
   scanf("%d", &m);
   printf(" N value : ");
   scanf("%d", &n);
   printf("\n %d power %d is %d", m, n, power(m, n));
   printf("\n %d power %d is %d", m, n, powerUpdated(m, n));
 }

  int power(int m, int n) {
    if(n == 0){
        return 1;
    }
    else {
        return power(m, n-1) * m;
    }
  }

  int powerUpdated(int m, int n) {
    if(n == 0) {
        return 1;
    }
    else {
        if(n % 2 == 0) {
            return power(m*m, n/2);
        }
        else{
            return 2 * power(m*m, n/2);
        }
    }
  }
