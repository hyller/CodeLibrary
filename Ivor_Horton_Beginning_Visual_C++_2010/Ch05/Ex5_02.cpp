// Ex5_02.cpp
// A futile attempt to modify caller arguments
#include <iostream>
using std::cout;
using std::endl;

int incr10(int num);           // Function prototype

int main(void)
{
   int num(3);

   cout << endl << "incr10(num) = " << incr10(num) << endl
        << "num = " << num << endl;
   return 0;
}

// Function to increment a variable by 10
int incr10(int num)            // Using the same name might help...
{
   num += 10;                  // Increment the caller argument – hopefully
   return num;                 // Return the incremented value
}
