// Ex5_08.cpp
// Using a reference to modify caller arguments

#include <iostream>
using std::cout;
using std::endl;

int incr10(const int& num);              // Function prototype

int main(void)
{
   const int num(3);       // Declared const to test for temporary creation
   int value(6);

   int result = incr10(num);
   cout << endl << "incr10(num) = " << result
        << endl << "num = " << num;

   result = incr10(value);
   cout << endl << "incr10(value) = " << result;
   cout << endl << "value = " << value;

   cout << endl;
   return 0;
}

// Function to increment a variable by 10
int incr10(const int& num)       // Function with const reference argument
{
   cout << endl << "Value received = " << num;
//   num += 10;                  // this statement would now be illegal
   return num+10;              // Return the incremented value
}
