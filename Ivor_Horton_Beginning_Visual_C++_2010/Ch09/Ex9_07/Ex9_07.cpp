// Ex9_07.cpp (the same as Ex9_06.cpp)
// Using a virtual function 
#include <iostream>
#include "GlassBox.h"                  // For CBox and CGlassBox
using std::cout;
using std::endl;

int main()
{
  CBox myBox(2.0, 3.0, 4.0);           // Declare a base box
  CGlassBox myGlassBox(2.0, 3.0, 4.0); // Declare derived box - same size

  myBox.ShowVolume();                  // Display volume of base box
  myGlassBox.ShowVolume();             // Display volume of derived box

  cout << endl;
  return 0;
}
