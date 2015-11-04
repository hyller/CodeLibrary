// Ex3_17.cpp : main project file.
// Analyzing a string using a for each loop

#include "stdafx.h"

using namespace System;


int main(array<System::String ^> ^args)
{
  int vowels(0), consonants(0);
  String^ proverb(L"A nod is as good as a wink to a blind horse.");

  for each(wchar_t ch in proverb)
  {
    if(Char::IsLetter(ch))
    {
      ch = Char::ToLower(ch);      // Convert to lowercase
      switch(ch)
      {
      case 'a': case 'e': case 'i': case 'o': case 'u':
        ++vowels;
        break;
      default:
        ++consonants;
        break;
      }
    }
  }

  Console::WriteLine(proverb);
  Console::WriteLine(L"The proverb contains {0} vowels and {1} consonants.",
                                                              vowels, consonants);
  return 0;
}
