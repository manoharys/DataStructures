/*
   Tailor series using recursion

   e^x = 1 + x/1! + x^2/2! + x^3/3! + .... +n terms

   Above expression is doing three tasks sum of n terms, exponential function and factorial function
   sum of n terms -> sum(n-1) + n;
   factorial      -> fact(n-1) * n;
   power          -> power(m, n-1) * m;

   Since function can return only single value, so utilize static variables for storiing results
   Algo ->
       int e(x, n){
          static int p=1, f=1
          if(n == 0) return 1
          else
            result = e(x, n-1)
            p *= x;
            f *= n;
            return r + p/f;
       }

*/

 #include<stdio.h>

 double e(int m, int n);

 int main() {
   int m, n;
   printf(" M value : ");
   scanf("%d", &m);
   printf(" N value : ");
   scanf("%d", &n);
   printf("%lf \n",e(m, n));

 }


  double e(int x, int n)
  {
     static double p=1,f=1;
     double r;
     if(n==0)
       return 1;
     r=e(x,n-1);
     p=p*x;
     f=f*n;
     return r+p/f;
}



