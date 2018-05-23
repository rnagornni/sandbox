#include <stdio.h>
#include <stdlib.h>

int maxSubStrLength(char *str) {
   int len = strlen(str);
   int max = 0;
   for (int i = 0; i < len; i++) {
      for (int j=i+1; j < len; j += 2) {
         int sum1 = 0, sum2 = 0;
         for (int k = 0; k < j/2; k++) {
            sum1 += str[i + k] - '0';
            sum2 += str[i + j/2 + k] - '0';
         }
         if (sum1 == sum2) {
            max = j;
         }
      }
   }
   return max;
}


int main() {
   char n[] = "9430723"; // 4307
  // char n[] = "142124";  //6
   printf("Maxsubstring length %d\n", maxSubStrLength(n));
   return 0;
}
