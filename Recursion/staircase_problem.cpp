#include <iostream>

using namespace std;

int noOfWays(int n)
{
    if(n < 0)
        return 0;
    if(n == 1 || n == 0)
        return 1;
    
    return noOfWays(n - 1) + noOfWays(n - 2);    
}

int main()
{
   int n = 3;
   cout<<noOfWays(n);
   
   return 0;
}
