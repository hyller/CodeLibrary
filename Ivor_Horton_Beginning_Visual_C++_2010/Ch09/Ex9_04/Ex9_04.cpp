// Ex9_04.cpp
// Using the protected access specifier
#include <iostream>                    // For stream I/O
#include <cstring>                     // For strlen() and strcpy()
#include "CandyBox.h"                  // For CBox and CCandyBox
using std::cout;
using std::endl;

int main()
{
  CCandyBox myCandyBox;
  CCandyBox myToffeeBox(2, 3, 4, "Stickjaw Toffee");

  cout << endl
       << "myCandyBox volume is " << myCandyBox.Volume()
       << endl
       << "myToffeeBox volume is " << myToffeeBox.Volume();

  // cout << endl << myToffeeBox.m_Length;  // Uncomment this for an error

  cout << endl;
  return 0;
}
