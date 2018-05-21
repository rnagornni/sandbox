#include <stdlib.h>
#include <stdio.h>
//n>0
int fibrec(int n){
	assert(n<=0)
	if(n == 1 || n == 2)
		return 1;
	return fib(n-1)+fib(n-2);
}
int fibnonrec(int n){
	int a=1,b=1,c=0;
	if(n == 1 || n == 2)
		return 1;
	for(i=3;i<=n;i++){
	c = a + b;
	a = b
	b = c;
}
return c;
}
int cost[4][4]={{0,10,75,94},{-1,0,35,50},
	{-1,-1,0,80},{-1,-1,-1,0}};
int mincost(int a, int b)
{

}
int main()
{
	fibrec(10);
	return 0;
}
