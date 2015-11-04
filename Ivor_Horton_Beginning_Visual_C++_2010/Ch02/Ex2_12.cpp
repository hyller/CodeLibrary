// Ex2_12.cpp : main project file.
// Calculating the price of a carpet
#include "stdafx.h"

using namespace System;

int main(array<System::String ^> ^args)
{
  double carpetPriceSqYd = 27.95;
  double roomWidth = 13.5;             // In feet
  double roomLength = 24.75;           // In feet
  const int feetPerYard = 3;           
  double roomWidthYds = roomWidth/feetPerYard;
  double roomLengthYds = roomLength/feetPerYard;
  double carpetPrice = roomWidthYds*roomLengthYds*carpetPriceSqYd;

  Console::WriteLine(L"Room size is {0:F2} yards by {1:F2} yards",
                                roomLengthYds, roomWidthYds);
  Console::WriteLine(L"Room area is {0:F2} square yards",
                                roomLengthYds*roomWidthYds);
  Console::WriteLine(L"Carpet price is ${0:F2}", carpetPrice);
  return 0;
}
