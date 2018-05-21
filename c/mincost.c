#include <stdio.h>
#include <stdlib.h>

#define N 4

int cost[N][N] = { {0,10,75,94},
                   {-1,0,35,50},
                   {-1,-1,0,80},
                   {-1,-1,-1,0} };

int minCost(int origin, int dest) {
 
  if (origin == dest || (origin + 1) == dest)
      return cost[origin][dest];
   
   int min = minCost(origin, dest);
   
   for (int i=origin+1;i<dest;i++) {
      if ()
   }
}

int main() {
   int cost[N][N] = { {0,10,75,94},
                      {-1,0,35,50},
                      {-1,-1,0,80},
                      {-1,-1,-1,0} };
   minCost(0,N-1); 
   
   return 0;
}

