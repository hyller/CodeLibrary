// Ex4_01.cpp
// Calculating gas mileage
#include <iostream>
#include <iomanip>

using std::cin;
using std::cout;
using std::endl;
using std::setw;

int main()
{
   const int MAX(20);                      // Maximum number of values
   double gas[ MAX ];                      // Gas quantity in gallons
   long miles[ MAX ];                      // Odometer readings
   int count(0);                           // Loop counter
   char indicator('y');                    // Input indicator

   while( ('y' == indicator || 'Y' == indicator) && count < MAX )
   {
      cout << endl << "Enter gas quantity: ";
      cin >> gas[count];                   // Read gas quantity
      cout << "Enter odometer reading: ";
      cin >> miles[count];                 // Read odometer value

      ++count;
      cout << "Do you want to enter another(y or n)? ";
      cin >> indicator;
   }

   if(count <= 1)                     // count = 1 after 1 entry completed
   {                                  // ... we need at least 2
      cout << endl << "Sorry - at least two readings are necessary.";
      return 0;
   }

   // Output results from 2nd entry to last entry
   for(int i = 1; i < count; i++)
   {
     cout << endl
          << setw(2) << i << "."             // Output sequence number
          << "Gas purchased = " << gas[i] << " gallons" // Output gas
          << " resulted in "                 // Output miles per gallon
          << (miles[i] - miles[i - 1])/gas[i] << " miles per gallon.";
   }

   cout << endl;
   return 0;
}
