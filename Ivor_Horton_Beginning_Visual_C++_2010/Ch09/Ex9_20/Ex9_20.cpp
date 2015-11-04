// Ex9_20.cpp : main project file.
// Finalizers and destructors

#include "stdafx.h"

using namespace System;

ref class MyClass 
{
public:
  // Constructor
  MyClass(int n) : value(n){}

  // Destructor
  ~MyClass()
  { 
    Console::WriteLine("MyClass object({0}) destructor called.", value);
  }

  // Finalizer
  !MyClass()
  { 
    Console::WriteLine("MyClass object({0}) finalizer called.", value);
  }
private:
  int value;
};

int main(array<System::String ^> ^args)
{
  MyClass^ obj1 = gcnew MyClass(1);
  MyClass^ obj2 = gcnew MyClass(2);
  MyClass^ obj3 = gcnew MyClass(3);
  delete obj1;
  obj2->~MyClass();

  Console::WriteLine(L"End Program");
  return 0;
}
