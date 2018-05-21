#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 2
//https://blogs.msdn.microsoft.com/xiangfan/2009/04/28/optimize-your-code-matrix-multiplication/
//https://en.wikipedia.org/wiki/Strassen_algorithm
//https://en.wikipedia.org/wiki/Matrix_multiplication_algorithm
//http://www.agner.org/optimize/
//TODO: fazer o profilling
void swap(int *a, int *b);
int getat(int a[][SIZE], int i, int j, size_t size);
inline void swap(int *a, int *b)
{
   int c = *a;
   *a = *b;
   *b = c;
}
//vector as a matrix
inline int getat(int a[], int i, int j, size_t size)
{
   return a[i + j*size];
}
//print
void matrix_print(int a[][SIZE], size_t size) {
   int i, j;
   for(i=0;i<size;i++){
      for(j=0;j<size;j++){
         printf("%d ", a[i][j]);
      }
   printf("\n");
   }
}

//transposta
void matrix_trans(int a[][SIZE], size_t size) {
   int i, j, c;
   for(i=0;i<size;i++) {
      for(j=1+i;j<size;j++){
         swap(&a[i][j], &a[j][i]);
      }
   }
}

//multiplicacao
void matrix_mult(int a[][SIZE], int b[][SIZE], int c[][SIZE],size_t size) {
   int i,j,k;
   for(i=0;i<size;i++) {
      for(j=0;j<size;j++) {
         for(k=0;k<size;k++)
            c[i][j] += a[i][k] * b[k][j];
      }
   }
}
//multiplicacao transposta
void matrix_mult_trans(int a[][SIZE], int b[][SIZE], int c[][SIZE], size_t size){
   int i,j,k;
   matrix_trans(a,size);
   for(i=0;i<size;i++) {
      for(j=0;j<size;j++) {
         for(k=0;k<size;k++)
            c[i][j] += a[i][k] * b[j][k];
      }
   }
   matrix_trans(c,size);
}

int main(){
   clock_t begin;
   clock_t end;
   double time_spent;
   begin = clock();
   int x1[2][2] = {{1,2},{3,4}};
   int x2[2][2];

   matrix_print(x1,SIZE);
   matrix_trans(x1,SIZE);
   matrix_print(x1,SIZE);
   end = clock();
   time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

   return 0;
}

