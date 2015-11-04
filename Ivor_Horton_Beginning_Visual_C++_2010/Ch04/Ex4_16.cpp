// Ex4_16.cpp : main project file.
// Using a two-dimensional array

#include "stdafx.h"

using namespace System;

int main(array<System::String ^> ^args)
{
  const int SIZE(12);
  array<int, 2>^ products(gcnew array<int, 2>(SIZE,SIZE));

  for (int i = 0 ; i < SIZE ; i++)
    for(int j = 0 ; j < SIZE ; j++)
      products[i,j] = (i+1)*(j+1);

  Console::WriteLine(L"Here is the {0} times table:",  SIZE);

  // Write horizontal divider line
  for(int i = 0 ; i <= SIZE ; i++)
    Console::Write(L"_____");
  Console::WriteLine();                // Write newline

  // Write top line of table
  Console::Write(L"    |");
  for(int i = 1 ; i <= SIZE ; i++)
    Console::Write(L"{0,3} |", i);
  Console::WriteLine();                // Write newline

  // Write horizontal divider line with verticals
  for(int i = 0 ; i <= SIZE ; i++)
    Console::Write(L"____|");
  Console::WriteLine();                // Write newline

  // Write remaining lines
  for(int i = 0 ; i<SIZE ; i++)
  {
    Console::Write(L"{0,3} |", i+1);
    for(int j = 0 ; j<SIZE ; j++)
      Console::Write(L"{0,3} |", products[i,j]);

    Console::WriteLine();              // Write newline
  }

  // Write horizontal divider line
  for(int i = 0 ; i <= SIZE ; i++)
    Console::Write(L"_____");
  Console::WriteLine();                // Write newline
    return 0;
}
