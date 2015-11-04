// Ex4_14.cpp : main project file.
// Sorting an array of keys(the names) and an array of objects(the weights)

#include "stdafx.h"

using namespace System;

int main(array<System::String ^> ^args)
{
  array<String^>^ names = { "Jill", "Ted", "Mary", "Eve", "Bill", "Al"};
  array<int>^ weights = { 103, 168, 128, 115, 180, 176};

  Array::Sort( names,weights);                   // Sort the arrays
  for each(String^ name in names)                // Output the names
    Console::Write(L"{0, 10}", name);
  Console::WriteLine();

  for each(int weight in weights)                // Output the weights
    Console::Write(L"{0, 10}", weight);
  Console::WriteLine();
    return 0;
}
