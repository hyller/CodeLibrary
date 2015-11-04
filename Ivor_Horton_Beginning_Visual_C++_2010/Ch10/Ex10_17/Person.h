// Person.h
// A class defining a person
#pragma once
using namespace System;

ref class Person
{
public:
 Person():firstname(""), secondname(""){}
 
 Person(String^ first, String^ second):firstname(first), secondname(second)
 {}
 
  // Copy constructors
 Person(const Person% p):firstname(p.firstname),secondname(p.secondname){}
 Person(Person^ p):firstname(p->firstname), secondname(p->secondname){}

  // Destructor
  ~Person(){}

  // Assignment operator
  Person% operator=(const Person% p)
  {
    if(this != %p)
    {
      firstname = p.firstname;
      secondname = p.secondname;
    }
    return *this;
  }

  // Less-than operator
  bool operator<(Person^ p)
  {
    if(String::Compare(secondname, p->secondname) < 0 ||
       (String::Compare(secondname, p->secondname)== 0 &&
        String::Compare(firstname, p->firstname) < 0))
     return true;
    return false;
  }

  // String representation of a person
  virtual String^ ToString() override
  {
    return firstname + L" " + secondname;
  }

private:
  String^ firstname;
  String^ secondname;
};
