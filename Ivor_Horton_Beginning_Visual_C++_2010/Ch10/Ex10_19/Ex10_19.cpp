// Ex10_19.cpp
// Storing phone numbers in a map
#include "stdafx.h"
#include "Person.h"
#include <cliext/map>

using namespace System;
using namespace cliext;

// Read a person from standard input
Person^ getPerson()
{
  String^ first;
  String^ second;
  Console::Write(L"Enter a first name: ") ;
  first = Console::ReadLine();
  Console::Write(L"Enter a second name: ") ;
  second = Console::ReadLine();
  return gcnew Person(first->Trim(), second->Trim());
}

// Add a new entry to a phone book
void addEntry(map<Person^, String^>^ book)
{
  map<Person^, String^>::value_type entry;              // Stores a phone book entry
  String^ number;
  Person^ person = getPerson();

  Console::Write(L"Enter the phone number for {0}: ", person);
  number = Console::ReadLine()->Trim();

  entry = book->make_value(person, number);
  map<Person^,String^>::pair_iter_bool pr = book->insert(entry);
    if(pr.second)
      Console::WriteLine(L"Entry successful.");
    else
      Console::WriteLine(L"Entry exists for {0}. The number is {1}",
                                      person, pr.first->second);
}

// List the contents of a phone book
void listEntries(map<Person^, String^>^ book)
{
  if(book->empty())
  {
    Console::WriteLine(L"The phone book is empty.");
    return;
  }
  map<Person^, String^>::iterator iter;
  for(iter = book->begin() ; iter != book->end() ; iter++)
    Console::WriteLine(L"{0, -30}{1,-12}",
                    iter->first, iter->second); 
}

// Retrieve an entry from a phone book
void getEntry(map<Person^, String^>^ book)
{
  Person^ person = getPerson();
  map<Person^, String^>::const_iterator iter = book->find(person);
  if(book->end() == iter)
    Console::WriteLine(L"No entry found for {0}", person);
  else
    Console::WriteLine(L"The number for {0} is {1}",
                                          person, iter->second);
}

// Delete an entry from a phone book
void deleteEntry(map<Person^, String^>^ book)
{
  Person^ person = getPerson();
  map<Person^, String^>::iterator iter = book->find(person);
  if(book->end() == iter)
    Console::WriteLine(L"No entry found for {0}", person);
  else
  {
    book->erase(iter);
    Console::WriteLine(L"{0} erased.", person);
  }
}

int main(array<System::String ^> ^args)
{
  map<Person^, String^>^ phonebook = gcnew map<Person^, String^>();
  String^ answer;

  while(true)
  {
    Console::Write(L"Do you want to enter a phone book entry(Y or N): ") ;
    answer = Console::ReadLine()->Trim();
    if(Char::ToUpper(answer[0]) == L'N')
      break;
    addEntry(phonebook);
  }

  // Query the phonebook
  while(true)
  {
    Console::WriteLine(L"\nChoose from the following options:");
    Console::WriteLine(L"A  Add an entry   D Delete an entry   G  Get an entry");
    Console::WriteLine(L"L  List entries   Q  Quit"); 
    while(true)
    {
      answer = Console::ReadLine()->Trim();
      if(answer->Length)
        break;
      Console::WriteLine(L"\nYou must enter something - try again.");
    }
    
    switch(Char::ToUpper(answer[0]))
    {
      case L'A':
        addEntry(phonebook);
        break;
      case L'G':
        getEntry(phonebook);
        break;
      case L'D':
        deleteEntry(phonebook);
        break;
      case L'L':
        listEntries(phonebook);
        break;
      case L'Q':
        return 0;
      default:
        Console::WriteLine(L"Invalid selection. Try again.");
        break;
    }
  }
  
  return 0;
}
