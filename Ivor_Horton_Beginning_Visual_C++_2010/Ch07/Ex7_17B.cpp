// Ex7_17B.cpp : main project file.
// Defining and using default indexed properties
// With set indexed property capability added
// and named indexed property

#include "stdafx.h"
 
using namespace System;

ref class Name
{
  private:
  array<String^>^ Names;

public:
  Name(...array<String^>^ names) : Names(names) {}

  // Scalar property specifying number of names
  property int NameCount
  {
    int get() {return Names->Length; }
  }

  // Indexed property to return names
  property String^ default[int]
  {
    String^ get(int index)
    {
      if(index >= Names->Length)
        throw gcnew Exception(L"Index out of range"); 
      return Names[index]; 
    }

    void set(int index, String^ name)
    {
      if(index >= Names->Length)
        throw gcnew Exception(L"Index out of range"); 
      Names[index] = name; 
    }
  }

  // Indexed property to return initials
  property wchar_t Initials[int]
  {
    wchar_t get(int index)
    {
      if(index >= Names->Length)
        throw gcnew Exception(L"Index out of range"); 
      return Names[index][0]; 
    }
  }
};

int main(array<System::String ^> ^args)
{
  Name^ myName = gcnew Name(L"Ebenezer", L"Isaiah", L"Ezra", L"Inigo",
                                                               L"Whelkwhistle");
  myName[myName->NameCount - 1] = L"Oberwurst";  // Change last indexed property

  // List the names
  for(int i = 0 ; i < myName->NameCount ; i++)
    Console::WriteLine(L"Name {0} is  {1}", i+1, myName[i]);

  // Output the initials
  Console::Write(L"The initials are:");
  for(int i = 0 ; i < myName->NameCount ; i++)
    Console::Write(L" {0}", myName->Initials[i]);
  Console::WriteLine();

  return 0;
}
