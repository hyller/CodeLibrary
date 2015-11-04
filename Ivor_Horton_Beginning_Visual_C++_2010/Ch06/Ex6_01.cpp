// Ex6_01.cpp
// Exercising pointers to functions
#include <iostream>
using std::cout;
using std::endl;

long sum(long a, long b);              // Function prototype
long product(long a, long b);          // Function prototype

int main(void)
{
  long (*pdo_it)(long, long);          // Pointer to function declaration

  pdo_it = product;
  cout << endl
       << "3*5 = " << pdo_it(3, 5);    // Call product thru a pointer

  pdo_it = sum;                        // Reassign pointer to sum()
  cout << endl
       << "3*(4 + 5) + 6 = "
       << pdo_it(product(3, pdo_it(4, 5)), 6);   // Call thru a pointer,
                                                 // twice
  cout << endl;
  return 0;
}

// Function to multiply two values
long product(long a, long b)
{
  return a*b;
}

// Function to add two values
long sum(long a, long b)
{
  return a + b;
}
