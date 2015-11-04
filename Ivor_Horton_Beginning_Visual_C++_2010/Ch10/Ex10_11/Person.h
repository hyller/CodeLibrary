// Person.h
// A class defining a person
#pragma once
#include <iostream>
#include <string>
#include <functional>
using std::cout;
using std::endl;
using std::string;

class Person
{
public:
  Person(const string first = "", const string second = "")
  {
    firstname = first;
    secondname = second;
  }

  // Less-than operator
  bool operator<(const Person& p)const
  {
    if(secondname < p.secondname ||
      ((secondname == p.secondname) && (firstname < p.firstname)))
      return true;

    return false;
  }

  // Get the name 
  string getName()const
  {
    return firstname + " " + secondname;
  }

private:
  string firstname;
  string secondname;
};
