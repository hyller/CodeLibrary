// Ex8_15.cpp : main project file.
// Overloading operators in the value class, Length
#include "stdafx.h"
using namespace System;

value class Length
{
private:
  int feet;
  int inches;

public:
  static initonly int inchesPerFoot = 12;

  // Constructor
  Length(int ft, int ins) : feet(ft), inches(ins){ }

  // A length as a string
  virtual String^ ToString() override
  {
    return feet.ToString() + (1 == feet ? L" foot " : L" feet ") +
           inches + (1 == inches ? L" inch" : L" inches");  
  }

  // Addition operator
  Length operator+(Length len)
  {
    int inchTotal = inches+len.inches+inchesPerFoot*(feet+len.feet);
    return Length(inchTotal/inchesPerFoot, inchTotal%inchesPerFoot);
  }

  // Division operator
  static Length operator/(Length len, double x)
  {
    int ins = safe_cast<int>((len.feet*inchesPerFoot + len.inches)/x);
    return Length(ins/inchesPerFoot, ins%inchesPerFoot);
  }

  static Length operator*(double x, Length len); // Pre-multiply by double value
  static Length operator*(Length len, double x); // Post-multiply by double value
};

Length Length::operator *(double x, Length len)
{
  int ins = safe_cast<int>(x*len.inches +x*len.feet*inchesPerFoot);
  return Length(ins/inchesPerFoot, ins%inchesPerFoot);
}

Length Length::operator *(Length len, double x)
{ return operator*(x, len);  }

int main(array<System::String ^> ^args)
{
  Length len1 = Length(6, 9);
  Length len2 = Length(7, 8);
  double factor(2.5);

  Console::WriteLine(L"{0} plus {1} is {2}", len1, len2, len1+len2);
  Console::WriteLine(L"{0} times {1} is {2}", factor, len2, factor*len2);
  Console::WriteLine(L"{1} times {0} is {2}", factor, len2, len2*factor);
  Console::WriteLine(L"The sum of {0} and {1} divided by {2} is {3}",
                                      len1, len2, factor, (len1+len2)/factor);
  return 0;
}
