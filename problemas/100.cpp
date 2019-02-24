#include <iostream>



//even
//n/2
//odd
//3n+1
int main()
{
  int n = 22;
  int min, max;
  int nmax = 0;
  std::cin >> min >> max;
  std::cout<<"Starting ...."<<min<<"..."<<max<<std::endl;
  for(int i = min;i<=max;i++)
  {
    int iter = 1;
    n = i;
    while(1)
    {
     //std::cout<<"n="<<n<<std::endl;
     if(n % 2 == 0)
       n = (n / 2);
     else
       n = 3 * n + 1;
     iter++;
     if(n == 1)
     {
       std::cout<<i<<" "<<iter<<std::endl;
       break; 
     }
    }
    nmax = nmax > iter? nmax : iter;
  }
  std::cout<<min<<" "<<max<<" "<<nmax<<std::endl;
  return 0;
}

