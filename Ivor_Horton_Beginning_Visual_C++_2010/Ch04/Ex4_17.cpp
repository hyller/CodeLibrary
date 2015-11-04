// Ex4_17.cpp : main project file.
// Using an array of arrays

#include "stdafx.h"

using namespace System;

int main(array<System::String ^> ^args)
{
array< array< String^ >^ >^ grades = gcnew array< array< String^ >^ >
          {
            gcnew array<String^>{"Louise", "Jack"},                  // Grade A
            gcnew array<String^>{"Bill", "Mary", "Ben", "Joan"},     // Grade B
            gcnew array<String^>{"Jill", "Will", "Phil"},            // Grade C
            gcnew array<String^>{"Ned", "Fred", "Ted", "Jed", "Ed"}, // Grade D
            gcnew array<String^>{"Dan", "Ann"}                       // Grade E
          };

  wchar_t gradeLetter('A');

  for each(array< String^ >^ grade in grades)
  {
    Console::WriteLine(L"Students with Grade {0}:", gradeLetter++);

    for each( String^ student in grade)
      Console::Write(L"{0,12}",student);          // Output the current name

    Console::WriteLine();                        // Write a newline
  }
  return 0;
}
