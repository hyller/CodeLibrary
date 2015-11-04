// Ex9_05.cpp
// Using a derived class copy constructor
#include <iostream>                    // For stream I/O
#include <cstring>                     // For strlen() and strcpy()
#include "CandyBox.h"                  // For CBox and CCandyBox
using std::cout;
using std::endl;

int main()
{
  CCandyBox chocBox(2.0, 3.0, 4.0, "Chockies");  // Declare and initialize
  CCandyBox chocolateBox(chocBox);               // Use copy constructor

  cout << endl
       << "Volume of chocBox is " << chocBox.Volume()
       << endl
       << "Volume of chocolateBox is " << chocolateBox.Volume()
       << endl;

  return 0;
}
