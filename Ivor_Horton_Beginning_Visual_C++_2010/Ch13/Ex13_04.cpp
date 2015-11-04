// Ex13_04.cpp
// Computing pi by summing a series
#include <iostream>
#include <iomanip>
#include <cmath>
#include "ppl.h"

int main()
{
  Concurrency::combinable<double> piParts;
  Concurrency::parallel_for(1, 1000000, [&piParts](long long n)
  { piParts.local() += 6.0/(n*n);  });
  
  double pi2 = piParts.combine([](double left, double right)
  {  return left + right;  });
  std::cout << "pi squared = " << std::setprecision(10) << pi2 << std::endl;
  std::cout << "pi = " << std::sqrt(pi2) << std::endl;
  return 0;
}