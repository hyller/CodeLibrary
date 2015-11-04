// Ex4_18.cpp : main project file.
// Creating a custom format string

#include "stdafx.h"

using namespace System;

int main(array<System::String ^> ^args)
{
  array<int>^ values = { 2, 456, 23, -46, 34211, 456, 5609, 112098,
    234, -76504, 341, 6788, -909121, 99, 10};
  String^ formatStr1(L"{0,");           // 1st half of format string
  String^ formatStr2(L"}");             // 2nd half of format string
  String^ number;                       // Stores a number as a string

  // Find the length of the maximum length value string
  int maxLength(0);                    // Holds the maximum length found
  for each(int value in values)
  {
    number = L"" + value;               // Create string from value
    if(maxLength<number->Length)
      maxLength = number->Length;
  }

  // Create the format string to be used for output
  String^ format(formatStr1 + (maxLength+1) + formatStr2);

  // Output the values
  int numberPerLine(3);
  for(int i = 0 ; i< values->Length ; i++)
  {
    Console::Write(format, values[i]);
    if((i+1)%numberPerLine == 0)
      Console::WriteLine();
  }
    return 0;
}
