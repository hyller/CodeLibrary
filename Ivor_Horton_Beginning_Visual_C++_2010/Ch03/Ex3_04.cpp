// Ex3_04.cpp
// The conditional operator selecting output
#include <iostream>

using std::cout;
using std::endl;

int main()
{
   int nCakes(1);           // Count of number of cakes

   cout << endl
        << "We have " << nCakes << " cake" << ((nCakes > 1) ? "s." : ".")
        << endl;

   ++nCakes;

   cout << endl
        << "We have " << nCakes << " cake" << ((nCakes > 1) ? "s." : ".")
        << endl;
   return 0;
}
