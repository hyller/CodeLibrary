// Ex3_01.cpp
// A nested if demonstration
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
   char letter(0);                       // Store input in here

   cout << endl
        << "Enter a letter: ";           // Prompt for the input
   cin >> letter;                        // then read a character

   if(letter >= 'A')                     // Test for 'A' or larger
   {
      if(letter <= 'Z')                  // Test for 'Z' or smaller
      {
         cout << endl
              << "You entered a capital letter."
              << endl;
         return 0;
      }
   }

   if(letter >= 'a')                     // Test for 'a' or larger
   {
      if(letter <= 'z')                  // Test for 'z' or smaller
      {
         cout << endl
              << "You entered a small letter."
              << endl;
         return 0;
      }
   }

   cout << endl << "You did not enter a letter." << endl;
   return 0;
}
