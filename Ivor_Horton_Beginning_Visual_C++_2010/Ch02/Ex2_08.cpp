// Ex2_08.cpp
// Demonstrating variable scope
#include <iostream>

using std::cout;
using std::endl;

int count1 = 100;                         // Global version of count1

int main()
{                                         // Function scope starts here
   int count1 = 10;
   int count3 = 50;
   cout << endl
        << "Value of outer count1 = " << count1
        << endl;
   cout << "Value of global count1 = " << ::count1            // From outer block
        << endl;

   {                                // New scope starts here...
      int count1 = 20;              //This hides the outer count1
      int count2 = 30;
      cout << "Value of inner count1 = " << count1
           << endl;
      cout << "Value of global count1 = " << ::count1         // From inner block
           << endl;

      count1 += 3;                  // This affects the inner count1
      count3 += count2;
   }                                // ...and ends here.

   cout << "Value of outer count1 = " << count1
        << endl
        << "Value of outer count3 = " << count3
        << endl;

   //cout << count2 << endl;        // uncomment to get an error
   
   return 0;
}   
