// Ex2_10.cpp
// Using a using directive 
#include <iostream>

namespace myStuff
{
  int value = 0;
}

using namespace myStuff;            // Make all the names in myStuff available

int main()
{
  std::cout << "enter an integer: ";
  std::cin  >> value;
  std::cout << "\nYou entered " << value
            << std::endl;
  return 0;
}
