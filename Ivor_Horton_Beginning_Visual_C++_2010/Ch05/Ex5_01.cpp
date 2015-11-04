// Ex5_01.cpp
// Declaring, defining, and using a function
#include <iostream>
using std::cout;
using std::endl;

double power(double x, int n);    // Function prototype

int main(void)
{
   int index(3);                  // Raise to this power
   double x(3.0);                 // Different x from that in function power
   double y(0.0); 

   y = power(5.0, 3);             // Passing constants as arguments
   cout << endl << "5.0 cubed = " << y;

   cout << endl << "3.0 cubed = "
        << power(3.0, index);     // Outputting return value

   x = power(x, power(2.0, 2.0)); // Using a function as an argument
   cout << endl                   // with auto conversion of 2nd parameter
        << "x = " << x;

   cout << endl;
   return 0;
}

// Function to compute positive integral powers of a double value
// First argument is value, second argument is power index
double power(double x, int n)
{                                 // Function body starts here...
   double result(1.0);            // Result stored here
   for(int i = 1; i <= n; i++)
      result *= x;
   return result;
}                                 // ...and ends here
