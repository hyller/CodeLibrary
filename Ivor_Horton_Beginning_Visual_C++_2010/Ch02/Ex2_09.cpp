// Ex2_09.cpp
// Declaring a namespace 
#include <iostream>

namespace myStuff
{
  int value = 0;
}

int main()
{
  std::cout << "enter an integer: ";
  std::cin  >> myStuff::value;
  std::cout << "\nYou entered " << myStuff::value
            << std::endl;
  return 0;
}
