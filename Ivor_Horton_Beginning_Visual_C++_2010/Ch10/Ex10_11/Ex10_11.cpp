// Ex10_11.cpp
// Using a map container

#include <iostream>
#include <cstdio>
#include <iomanip>
#include <string>
#include <map>
#include "Person.h"

using std::cin;
using std::cout;
using std::endl;
using std::setw;
using std::ios;
using std::string;
using std::pair;
using std::map;
using std::make_pair;

// Read a person from cin
Person getPerson()
{
  string first;
  string second;
  cout << "Enter a first name: " ;
  getline(cin, first);
  cout << "Enter a second name: " ;
  getline(cin, second);
  return Person(first, second);
}

// Add a new entry to a phone book
void addEntry(map<Person, string>& book)
{
  string number;
  Person person = getPerson();

  cout << "Enter the phone number for "
    << person.getName() << ": ";
    getline(cin, number);
    auto entry = make_pair(person, number);
    auto pr = book.insert(entry);

    if(pr.second)
      cout << "Entry successful." << endl;
    else
    {
      cout << "Entry exists for " << person.getName()
           << ". The number is " << pr.first->second << endl;
    }
}

// List the contents of a phone book
void listEntries(map<Person, string>& book)
{
  if(book.empty())
  {
    cout << "The phone book is empty." << endl;
    return;
  }
//  map<Person, string>::iterator iter;
  cout << setiosflags(ios::left);              // Left justify output
  for(auto iter = book.begin() ; iter != book.end() ; iter++)
  {
    cout << setw(30) << iter->first.getName() 
         << setw(12) << iter->second << endl; 
  }
  cout << resetiosflags(ios::right);           // Right justify output
}

// Retrieve an entry from a phone book
void getEntry(map<Person, string>& book)
{
  Person person = getPerson();
  auto iter = book.find(person);
  if(iter == book.end())
    cout << "No entry found for " << person.getName() << endl;
  else
    cout << "The number for " << person.getName()
         << " is " << iter->second << endl;
}

// Delete an entry from a phone book
void deleteEntry(map<Person, string>& book)
{
  Person person = getPerson();
  map<Person, string>::iterator iter = book.find(person);
  if(iter == book.end())
    cout << "No entry found for " << person.getName() << endl;
  else
  {
    book.erase(iter);
    cout << person.getName() << " erased." << endl;
  }
}

int main()
{  
  map<Person, string> phonebook;
  char answer = 0;

  while(true)
  {
    cout << "Do you want to enter a phone book entry(Y or N): " ;
    cin >> answer;
    cin.ignore();                      // Ignore newline in buffer
    if(toupper(answer) == 'N')
      break;
    if(toupper(answer) != 'Y')
    {
      cout << "Invalid response. Try again." << endl;
      continue;
    }
    addEntry(phonebook);
  }

  // Query the phonebook
  while(true)
  {
    cout << endl << "Choose from the following options:" << endl
         << "A  Add an entry   D Delete an entry   G  Get an entry" << endl
         << "L  List entries   Q  Quit" << endl; 
    cin >> answer;
    cin.ignore();                      // Ignore newline in buffer
    
    switch(toupper(answer))
    {
      case 'A':
        addEntry(phonebook);
        break;
      case 'G':
        getEntry(phonebook);
        break;
      case 'D':
        deleteEntry(phonebook);
        break;
      case 'L':
        listEntries(phonebook);
        break;
      case 'Q':
        return 0;
      default:
        cout << "Invalid selection. Try again." << endl;
        break;
    }
  }
  return 0;
}
