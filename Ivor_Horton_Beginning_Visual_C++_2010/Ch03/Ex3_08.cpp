// Ex3_08.cpp
// Summing integers with a for loop
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
   int i(1), sum(0);
   const int max(10);

   for(i = 1; i <= max; i++)       // Loop specification
      sum += i;                    // Loop statement

   cout << endl
        << "sum = " << sum << endl
        << "i = "   << i   << endl;
   return 0;
}
