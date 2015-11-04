// Ex9_18.cpp : main project file.
// Using an unbound delegate

#include "stdafx.h"

using namespace System;

public ref class ThisClass
{
public:
  void Sum(int n)
  { Console::WriteLine(L"Sum result = {0} ", value+n); } 

  void Product(int n)
  { Console::WriteLine(L"product result = {0} ", value*n); } 

  ThisClass(double v) : value(v){}

private:
  double value;
}; 

public delegate void UBHandler(ThisClass^, int value);         

int main(array<System::String ^> ^args)
{
  array<ThisClass^>^ things = { gcnew ThisClass(5.0),gcnew ThisClass(10.0),
                                gcnew ThisClass(15.0),gcnew ThisClass(20.0),
                                gcnew ThisClass(25.0)
                              };
  
  UBHandler^ ubh = gcnew UBHandler(&ThisClass::Sum);  // Create a delegate object 

  // Call the delegate for each things array element
  for each(ThisClass^ thing in things)
    ubh(thing, 3);

   ubh += gcnew UBHandler(&ThisClass::Product);   // Add a function to the delegate

  // Call the new delegate for each things array element
  for each(ThisClass^ thing in things)
    ubh(thing, 2);
  
  return 0;
}
