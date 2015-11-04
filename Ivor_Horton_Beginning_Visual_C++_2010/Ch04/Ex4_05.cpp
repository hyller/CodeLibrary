// Ex4_05.cpp
// Exercising pointers
#include <iostream>
using std::cout;
using std::endl;
using std::hex;
using std::dec;

int main()
{
   long* pnumber(nullptr);         // Pointer declaration & initialization
   long number1(55), number2(99);

   pnumber = &number1;             // Store address in pointer
   *pnumber += 11;                 // Increment number1 by 11
   cout << endl
        << "number1 = " << number1
        << "   &number1 = " << hex << pnumber;

   pnumber = &number2;             // Change pointer to address of number2
   number1 = *pnumber*10;          // 10 times number2

   cout << endl
        << "number1 = " << dec << number1
        << "   pnumber = " << hex << pnumber
        << "   *pnumber = " << dec << *pnumber;

   cout << endl;
   return 0;
}
