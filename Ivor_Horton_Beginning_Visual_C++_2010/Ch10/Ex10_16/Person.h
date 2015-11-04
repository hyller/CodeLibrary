// Person.h
// A class defining a person
#pragma once
using namespace System;

ref class Person
{
public:
	Person():firstname(L""), secondname(L""){}
	
	Person(String^ first, String^ second):firstname(first), secondname(second)
	{}
  
  // Destructor
  ~Person(){}

  // String representation of a person
  virtual String^ ToString() override
  {
    return firstname + L" " + secondname;
  }

private:
  String^ firstname;
  String^ secondname;
};
