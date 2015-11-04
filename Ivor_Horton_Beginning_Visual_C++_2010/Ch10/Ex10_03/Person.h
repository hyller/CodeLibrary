// Person.h
// A class defining people by their names
#pragma once
#include <cstring>
#include <iostream>
using std::cout;
using std::endl;

class Person
{
  public:
  // Constructor, includes no-arg constructor
  Person(char* first = "John", char* second = "Doe")
  {
    initName(first, second);
  }
    
  // Copy constructor
  Person(const Person& p)
  {
    initName(p.firstname, p.secondname);
  }

  // Destructor
  ~Person()
  {
    delete[] firstname;
    delete[] secondname;
  }

  // Assignment operator
  Person& operator=(const Person& p)
  {
    // Deal with p = p assignment situation
    if(&p == this)
      return *this;

    delete[] firstname;
    delete[] secondname;
    initName(p.firstname, p.secondname);
    return *this;
  }

  // Less-than operator
  bool operator<(const Person& p)
  {
    int result(strcmp(secondname, p.secondname));
    if(result < 0 || result ==  0 && strcmp(firstname, p.firstname) < 0)
      return true;
    return false;
  }

  // Output a person
  void showPerson() const
  {
    cout << firstname << " " << secondname << endl;
  }

  private:
  char* firstname;
  char* secondname;

  // Private helper function to avoid codde duplication
  void initName(char* first, char* second)
  {
    size_t length(strlen(first)+1);
    firstname = new char[length];
    strcpy_s(firstname, length, first);
    length = strlen(second)+1;
    secondname = new char[length];
    strcpy_s(secondname, length, second);
  }
};
