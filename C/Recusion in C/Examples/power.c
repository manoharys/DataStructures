/*
   program to calculate the power using recursion

   eg : 2^5 = 2 * 2 * 2 * 2 * 2;
        m^n = m * m * m *...for n times

        power(m, n) = (m * m * m ... * n-1 times) * m
        therefore,
        power(m, n) = (m, n-1) * m  where  n > 0

*/

 #include<stdio.h>

 int power(int m, int n);

 int main() {
   int m, n;
   printf(" M value : ");
   scanf("%d", &m);
   printf(" N value : ");
   scanf("%d", &n);
   printf("\n %d power %d is %d", m, n, power(m, n));
 }

  int power(int m, int n) {
    if(n == 0){
        return 1;
    }
    else {
        return power(m, n-1) * m;
    }
  }
