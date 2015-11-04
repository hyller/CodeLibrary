// Ex2_04.cpp
// Using escape sequences
#include <iostream>
#include <iomanip>

using std::cout;

int main()
{
   char newline = '\n';                         // Newline escape sequence
   cout << newline;                             // Start on a new line
   cout << "\"We\'ll make our escapes in sequence\", he said.";
   cout << "\n\tThe program\'s over, it\'s time to make a beep beep.\a\a";
   cout << newline;                             // Start on a new line
   return 0;                                    // Exit program
}
