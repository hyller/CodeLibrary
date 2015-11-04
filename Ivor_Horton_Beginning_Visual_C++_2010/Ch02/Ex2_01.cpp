// Ex2_01.cpp
// A Simple Example of a Program
#include <iostream>

using std::cout;
using std::endl;

int main()
{
   int apples, oranges;                     // Declare two integer variables
   int fruit;                               // ...then another one

   apples = 5; oranges = 6;                 // Set initial values
   fruit = apples + oranges;                // Get the total fruit

   cout << endl;                            // Start output on a new line
   cout << "Oranges are not the only fruit... " << endl
        << "- and we have " << fruit << " fruits in all.";
   cout << endl;                            // Output a new line character

   return 0;                                // Exit the program
}
