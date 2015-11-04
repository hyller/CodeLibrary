// Ex10_16.cpp
// Storing handles in a vector
#include "stdafx.h"
#include "Person.h"
#include <cliext/vector>

using namespace System;
using namespace cliext;

int main(array<System::String ^> ^args)
{
  vector<Person^>^ people = gcnew vector<Person^>(); 
  String^ first;             // Stores a first name
  String^ second;            // Stores a second name
  Person^ person;            // Stores a Person

  while(true)
  {
    Console::Write(L"Enter a first name or press Enter to end: ");
    first = Console::ReadLine();
    if(0 == first->Length)
      break;
    Console::Write(L"Enter a second name: ");
    second = Console::ReadLine();
    person = gcnew Person(first->Trim(),second->Trim());
    people->push_back(person);
  }

  // Output the contents of the vector
  Console::WriteLine(L"\nThe persons in the vector are:");
  for each(Person^ person in people)
    Console::WriteLine("{0}",person);
  return 0;
}
