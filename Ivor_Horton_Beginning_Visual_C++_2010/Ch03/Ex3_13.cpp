// Ex3_13.cpp
// Demonstrating nested loops to compute factorials
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
   char indicator('n');
   long value(0L), factorial(0L);

   do
   {
      cout << endl << "Enter an integer value: ";
      cin >> value;

      factorial = 1L;
      for(long i = 2L; i <= value; i++)
         factorial *= i;

      cout << "Factorial " << value << " is " << factorial;
      cout << endl << "Do you want to enter another value (y or n)? ";
      cin >> indicator;
   } while(('y' == indicator) || ('Y' == indicator));

   return 0;
}
