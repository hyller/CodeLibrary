// Ex3_11.cpp
// Display ASCII codes for alphabetic characters
#include <iostream>
#include <iomanip>

using std::cout;
using std::endl;
using std::hex;
using std::dec;
using std::setw;

int main()
{
   for(char capital = 'A', small = 'a'; capital <= 'Z'; capital++, small++)
      cout << endl
           << "\t" << capital                      // Output capital as a character
           << hex << setw(10) << static_cast<int>(capital)   // and as hexadecimal
           << dec << setw(10) << static_cast<int>(capital)   // and as decimal
           << "    " << small                      // Output small as a character
           << hex << setw(10) << static_cast<int>(small)     // and as hexadecimal
           << dec << setw(10) << static_cast<int>(small);    // and as decimal

   cout << endl;
   return 0;
}
