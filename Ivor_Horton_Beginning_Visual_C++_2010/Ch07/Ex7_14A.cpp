// Ex7_14A.cpp : main project file.
// Overriding ToString()

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

  // Create a string representation of the object
  virtual String^ ToString() override
  {
    return feet + L" feet "+ inches + L" inches";
  }
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
