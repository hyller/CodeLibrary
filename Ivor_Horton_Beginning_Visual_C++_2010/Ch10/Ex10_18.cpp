// Ex10_18.cpp  Storing value class objects in a list
#include "stdafx.h"
#include <cliext/list>

using namespace System;
using namespace cliext;

int main(array<System::String ^> ^args)
{
  array<double>^ values = {2.5, -4.5, 6.5, -2.5, 2.5, 7.5, 1.5, 3.5}; 
  list<double>^ data = gcnew list<double>(); 
  for(int i = 0 ; i<values->Length ; i++)
    data->push_back(values[i]);

  Console::WriteLine("The list contains: ");
  for each(double value in data)
    Console::Write("{0} ", value);
  Console::WriteLine();

  data->sort(greater<double>());
  Console::WriteLine("\nAfter sorting the list contains: ");
  for each(double value in data)
    Console::Write("{0} ", value);
  Console::WriteLine();

  Console::ReadLine();
  
  return 0;
}
