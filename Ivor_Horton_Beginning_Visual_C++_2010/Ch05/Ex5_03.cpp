// Ex5_03.cpp
// A successful attempt to modify caller arguments
#include <iostream>
using std::cout;
using std::endl;

int incr10(int* num);                // Function prototype

int main(void)
{
   int num(3);

   int* pnum(&num);                  // Pointer to num

   cout << endl << "Address passed = " << pnum;

   int result = incr10(pnum);
   cout << endl << "incr10(pnum) = " << result;

   cout << endl << "num = " << num << endl;
   return 0;
}

// Function to increment a variable by 10
int incr10(int* num)                 // Function with pointer argument
{
   cout << endl << "Address received = " << num;

   *num += 10;                       // Increment the caller argument
                                     //  - confidently
   return *num;                      // Return the incremented value
}
