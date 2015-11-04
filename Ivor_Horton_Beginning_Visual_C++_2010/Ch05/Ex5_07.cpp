// Ex5_07.cpp
// Using a reference to modify caller arguments
#include <iostream>
using std::cout;
using std::endl;

int incr10(int& num);                // Function prototype

int main(void)
{
   int num(3);
   int value(6);

   int result = incr10(num);
   cout << endl  << "incr10(num) = " << result
        << endl << "num = " << num;

   result = incr10(value);
   cout << endl << "incr10(value) = " << result
        << endl << "value = " << value << endl;
   return 0;
}

// Function to increment a variable by 10
int incr10(int& num)                 // Function with reference argument
{
   cout << endl << "Value received = " << num;

   num += 10;                        // Increment the caller argument
                                     //  - confidently
   return num;                       // Return the incremented value
}
