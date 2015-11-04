// Ex4_09.cpp
// Calculating primes
#include <iostream>
#include <iomanip>
using std::cout;
using std::endl;
using std::setw;

int main()
{
   const int MAX(100);            // Number of primes required
   long primes[MAX] = { 2,3,5 };  // First three primes defined
   long trial(5);                 // Candidate prime
   int count(3);                  // Count of primes found
   bool found(false);             // Indicates when a prime is found

   do
   {
      trial += 2;                      // Next value for checking
      found = false;                   // Set found indicator

      for(int i = 0; i < count; i++)   // Try division by existing primes
      {
         found = (trial % *(primes + i)) == 0;// True for exact division
           if(found)                          // If division is exact
              break;                          // it's not a prime
      }

      if (!found)                       // We got one...
         *(primes + count++) = trial;  // ...so save it in primes array
   }while(count < MAX);

   // Output primes 5 to a line
   for(int i = 0; i < MAX; i++)
   {
      if(i % 5 == 0)                 // New line on 1st, and every 5th line
         cout << endl;
      cout << setw(10) << *(primes + i);
   }
   cout << endl;

   return 0;
}
