#include <stdio.h>
#include <stdlib.h>

#define N 4

int cost[N][N] = { {0,10,75,94},
                   {-1,0,35,50},
                   {-1,-1,0,80},
                   {-1,-1,-1,0} };

int MEMO[N][N] = {0};

int minCost(int origin, int dest) {
   int min, i;
   if(MEMO[origin][dest] == 0) {
      if (origin == dest || (origin + 1) == dest)
         return cost[origin][dest];
 
      min = cost[origin][dest];

      for (i=origin+1;i<dest;i++) {
         int temp = minCost(origin,i) + minCost(i,dest);
         if(min > temp)
            min = temp;
      }
      MEMO[origin][dest] =  min;
      return MEMO[origin][dest];
   }
   return MEMO[origin][dest];
}

int main() {
   int cost[N][N] = { {0,10,75,94},
                      {-1,0,35,50},
                      {-1,-1,0,80},
                      {-1,-1,-1,0} };

   printf("The minimum cost: %d\n", minCost(0,N-1));
   
   return 0;
}

