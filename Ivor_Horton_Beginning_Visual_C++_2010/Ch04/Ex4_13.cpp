// Ex4_13.cpp : main project file.
// Using a CLR array
#include "stdafx.h"

using namespace System;

int main(array<System::String ^> ^args)
{
  array<double>^ samples = gcnew array<double>(50);

  // Generate random element values
  Random^ generator = gcnew Random;
  for(int i = 0 ; i< samples->Length ; i++)
    samples[i] = 100.0*generator->NextDouble();

  // Output the samples
  Console::WriteLine(L"The array contains the following values:");
  for(int i = 0 ; i< samples->Length ; i++)
  {
    Console::Write(L"{0,10:F2}", samples[i]);
    if((i+1)%5 == 0)
      Console::WriteLine();
  }

  // Find the maximum value
  double max(0);
  for each(double sample in samples)
    if(max < sample)
      max = sample;

  Console::WriteLine(L"The maximum value in the array is {0:F2}", max);
  return 0;
}
