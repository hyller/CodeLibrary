// Ex9_09.cpp
// Using a reference to call a virtual function
#include <iostream>
#include "GlassBox.h"                  // For CBox and CGlassBox
using std::cout;
using std::endl;

void Output(const CBox& aBox);         // Prototype of function

int main()
{
  CBox myBox(2.0, 3.0, 4.0);           // Declare a base box
  CGlassBox myGlassBox(2.0, 3.0, 4.0); // Declare derived box of same size

  Output(myBox);                  // Output volume of base class object
  Output(myGlassBox);             // Output volume of derived class object

  cout << endl;
  return 0;
}

void Output(const CBox& aBox)
{
  aBox.ShowVolume();
}
