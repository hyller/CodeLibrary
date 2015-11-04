// Ex4_11.cpp
// Calculating primes using dynamic memory allocation
#include <iostream>
#include <iomanip>
using std::cin;
using std::cout;
using std::endl;
using std::setw;

int main()
{
   long* pprime(nullptr);         // Pointer to prime array
   long trial(5);                 // Candidate prime
   int count(3);                  // Count of primes found
   int found(0);                  // Indicates when a prime is found
   int max(0);                    // Number of primes required

   cout << endl
        << "Enter the number of primes you would like (at least 4): ";
   cin >> max;                    // Number of primes required

   if(max < 4)                    // Test the user input, if less than 4
      max = 4;                    // ensure it is at least 4

   pprime = new long[max];

   *pprime = 2;                   // Insert three
   *(pprime + 1) = 3;             // seed primes
   *(pprime + 2) = 5;

   do
   {
      trial += 2;                            // Next value for checking
      found = 0;                             // Set found indicator

      for(int i = 0; i < count; i++)         // Division by existing primes
      {
         found =(trial % *(pprime + i)) == 0;// True for exact division
         if(found)                           // If division is exact
            break;                           // it's not a prime
      }

      if (found == 0)                        // We got one...
         *(pprime + count++) = trial;        // ...so save it in primes array
   } while(count < max);

   // Output primes 5 to a line
   for(int i = 0; i < max; i++)
   {
      if(i % 5 == 0)                         // New line on 1st, and every 5th line
         cout << endl;
      cout << setw(10) << *(pprime + i);
   }

   delete [] pprime;                         // Free up memory
   pprime = nullptr;                         // and reset the pointer
   cout << endl;
   return 0;
}
