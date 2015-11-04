// Ex7_14.cpp : main project file.
// Defining and using a value class type

#include "stdafx.h"

using namespace System;

// Class representing a height
value class Height
{
private:
  // Records the height in feet and inches
  int feet;
  int inches;

public:
  // Create a height from inches value
  Height(int ins)
  {
    feet = ins/12;
    inches = ins%12;
  }

  // Create a height from feet and inches
  Height(int ft, int ins) : feet(ft), inches(ins){}
};

int main(array<System::String ^> ^args)
{
  Height myHeight(Height(6,3));
  Height^ yourHeight(Height(70));
  Height hisHeight(*yourHeight);

  Console::WriteLine(L"My height is {0}", myHeight);
  Console::WriteLine(L"Your height is {0}", yourHeight);
  Console::WriteLine(L"His height is {0}", hisHeight);
  return 0;
}
