// Ex3_15.cpp : main project file.

#include "stdafx.h"

using namespace System;

int main(array<System::String ^> ^args)
{
  wchar_t letter;                      // Corresponds to the C++/CLI Char type
  Console::Write(L"Enter a letter: ");
  letter = Console::Read();
  if(letter >= 'A')                    // Test for 'A' or larger
    if(letter <= 'Z')                  // Test for 'Z' or smaller
    {
      Console::WriteLine(L"You entered a capital letter.");
      return 0;
    }

  if(letter >= 'a')                    // Test for 'a' or larger
    if(letter <= 'z')                  // Test for 'z' or smaller
    {
      Console::WriteLine(L"You entered a small letter.");
      return 0;
    }

  Console::WriteLine(L"You did not enter a letter.");
   return 0;
}
