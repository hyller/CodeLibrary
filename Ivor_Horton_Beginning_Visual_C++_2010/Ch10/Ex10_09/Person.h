// Person.h
// A class defining a person
#pragma once
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

class Person
{
public:
  Person(string first, string second)
  {
    firstname = first;
    secondname = second;
  }

  // No-arg constructor
  Person(){}

  // Copy constructor
  Person(const Person& p)
  {
    firstname = p.firstname;
    secondname = p.secondname;
  }

  // Less-than operator
  bool operator<(const Person& p)const
  {
    if(secondname < p.secondname ||
      ((secondname == p.secondname) && (firstname < p.firstname)))
      return true;

    return false;
  }

  // Output a person
  void showPerson() const
  {
    cout << firstname << " " << secondname << endl;
  }

private:
  string firstname;
  string secondname;
};
