// Ex10_15.cpp Wrapping a lambda expression
#include <iostream>
#include <functional>
using std::function;
using std::cout;
using std::endl;
                        
int main()
{
  // Wrap the lambda expression to compute the HCF
  function<int(int,int)> hcf = [&](int m, int n) mutable ->int{ if(m < n) return hcf(n,m);
                                     int remainder(m%n);
                                     if(0 == remainder) return n;
                                     return hcf(n, remainder);};
  int a(17719), b(18879);
  cout << "For numbers " << a << " and " << b << " the HCF is " << hcf(a, b) << endl;
  a = 103*53*17*97;
  b = 3*29*103;
  cout << "For numbers " << a << " and " << b << " the HCF is " << hcf(a, b) << endl;

   return 0;
}
