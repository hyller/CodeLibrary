// Ex10_17.cpp
// Storing ref class objects in a double-ended queue
#include "stdafx.h"
#include "Person.h"
#include <cliext/deque>
#include <cliext/algorithm>

using namespace System;
using namespace cliext;

int main(array<System::String ^> ^args)
{
  
  deque<Person>^ people = gcnew deque<Person>(); 
  
  String^ first;             // Stores a first name
  String^ second;            // Stores a second name
  Person person;             // Stores a Person

  while(true)
  {
    Console::Write(L"Enter a first name or press Enter to end: ");
    first = Console::ReadLine();
    if(0 == first->Length)
      break;
    Console::Write(L"Enter a second name: ");
    second = Console::ReadLine();
    person = Person(first->Trim(),second->Trim());
    people->push_back(person);
  }

  sort(people->begin(), people->end());

  // Output the contents of the vector
  Console::WriteLine(L"\nThe persons in the vector are:");
  for each(Person^ p in people)
    Console::WriteLine("{0}",p);
    
  return 0;
}
