// Ex4_10.cpp
// Counting string characters using a pointer
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
   const int MAX(80);                  // Maximum array dimension
   char buffer[MAX];                   // Input buffer
   char* pbuffer(buffer);              // Pointer to array buffer

   cout << endl                        // Prompt for input
        << "Enter a string of less than "
        << MAX << " characters:"
        << endl;

   cin.getline(buffer, MAX, '\n');     // Read a string until \n

   while(*pbuffer)                     // Continue until \0
      pbuffer++;

   cout << endl
        << "The string \"" << buffer
        << "\" has " << pbuffer - buffer << " characters.";
   cout << endl;

   return 0;
}
