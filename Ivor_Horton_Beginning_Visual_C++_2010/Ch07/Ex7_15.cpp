// Ex7_15.cpp : main project file.
// Using the Box reference class type

#include "stdafx.h"

using namespace System;

ref class Box
{
  public:
    // No-arg constructor supplying default field values
    Box(): Length(1.0), Width(1.0), Height(1.0)
   {
     Console::WriteLine(L"No-arg constructor called.");
   }

    // Constructor definition using an initialisation list
    Box(double lv, double bv, double hv):
                             Length(lv), Width(bv), Height(hv)
   {
     Console::WriteLine(L"Constructor called.");
   }

   // Function to calculate the volume of a box
   double Volume()
   {
     return Length*Width*Height;
   }

  private:
    double Length;                     // Length of a box in inches
    double Width;                      // Width of a box in inches
    double Height;                     // Height of a box in inches
};

int main(array<System::String ^> ^args)
{
  Box^ aBox;                           // Handle of type Box^
  Box^ newBox = gcnew Box(10, 15, 20);
  aBox = gcnew Box;                    // Initialize with default Box
  Console::WriteLine(L"Default box volume is {0}", aBox->Volume());
  Console::WriteLine(L"New box volume is {0}", newBox->Volume());
  return 0;
}
