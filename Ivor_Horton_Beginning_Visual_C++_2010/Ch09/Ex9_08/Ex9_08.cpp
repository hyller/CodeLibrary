// Ex9_08.cpp
// Using a base class pointer to call a virtual function
#include <iostream>
#include "GlassBox.h"                  // For CBox and CGlassBox
using std::cout;
using std::endl;

int main()
{
  CBox myBox(2.0, 3.0, 4.0);            // Declare a base box
  CGlassBox myGlassBox(2.0, 3.0, 4.0);  // Declare derived box of same size
  CBox* pBox(nullptr);       // Declare a pointer to base class objects

  pBox = &myBox;             // Set pointer to address of base object
  pBox->ShowVolume();        // Display volume of base box
  pBox = &myGlassBox;        // Set pointer to derived class object
  pBox->ShowVolume();        // Display volume of derived box

  cout << endl;
  return 0;
}
