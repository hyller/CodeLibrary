// Ex5_15.cpp (based on Ex5_01.cpp)
// A recursive version of x to the power n
#include <iostream>
using std::cout;
using std::endl;

double power(double x, int n);    // Function prototype

int main(void)
{
  double x(2.0);                 // Different x from that in function power
  double result(0.0);

  // Calculate x raised to powers -3 to +3 inclusive
  for(int index = -3 ; index<=3 ; index++)
    cout << x << " to the power " << index << " is " << power(x, index)<< endl;

  return 0;
}

// Recursive function to compute integral powers of a double value
// First argument is value, second argument is power index
double power(double x, int n)
{
   if(n < 0)
     return power(1.0/x, -n);
   if(n > 0)
      return x*power(x, n-1);
   return 1.0;
}
