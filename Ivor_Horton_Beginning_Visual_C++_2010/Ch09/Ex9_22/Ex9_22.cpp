// Ex9_22.cpp : main project file.
// Using generic collection classes

#include "stdafx.h"

using namespace System;
using namespace System::Collections::Generic;    // For generic collections

// Class encapsulating a name
ref class Name
{
public:
  Name(String^ name1, String^ name2) : First(name1),Second(name2){}
  virtual String^ ToString() override{ return First +L" "+Second;}
private:
  String^ First;
  String^ Second;
};

// Class encapsulating a phone number
ref class PhoneNumber
{
public:
  PhoneNumber(int area, int local, int number):
      Area(area),Local(local), Number(number){}
  virtual String^ ToString() override
  { return Area +L" "+Local+L" "+Number; }

private:
  int Area;
  int Local;
  int Number;

};

int main(array<System::String ^> ^args)
{
  // Using List<T>
  Console::WriteLine(L"Creating a List<T> of integers:");
  List<int>^ numbers = gcnew List<int>;
  for(int i = 0 ; i<1000 ; i++)
    numbers->Add(2*i+1);

  // Sum the contents of the list
  int sum = 0;
  for(int i = 0 ; i<numbers->Count ; i++)
    sum += numbers[i];
  Console::WriteLine(L"Total = {0}", sum);

  // Using LinkedList<T>
  Console::WriteLine(L"\nCreating a LinkedList<T> of double values:");
  LinkedList<double>^ values = gcnew LinkedList<double>;
  for(int i = 0 ; i<1000 ; i++)
    values->AddLast(2.5*i);

  double sumd = 0.0;
  for each(double v in values)
    sumd += v;

  Console::WriteLine(L"Total = {0}", sumd);
  
  LinkedListNode<double>^ node = values->Find(20.0);   // Find node containing 20.0
  values->AddBefore(node, 19.9);
  values->AddAfter(values->Find(30.0), 30.1);

  // Sum the contents of the linked list again
  sumd = 0.0;
  for each(double v in values)
    sumd += v;

  Console::WriteLine(L"Total after adding values = {0}", sumd);

  // Using Dictionary<K,V>
  Console::WriteLine(L"\nCreating a Dictionary<K,V> of name/number pairs:");
  Dictionary<Name^, PhoneNumber^>^ phonebook = gcnew Dictionary<Name^, PhoneNumber^>;

  // Add name/number pairs to dictionary
  Name^ name = gcnew Name("Jim", "Jones");
  PhoneNumber^ number = gcnew PhoneNumber(914, 316, 2233);
  phonebook->Add(name, number);          
  phonebook->Add(gcnew Name("Fred","Fong"), gcnew PhoneNumber(123,234,3456)); 
  phonebook->Add(gcnew Name("Janet","Smith"), gcnew PhoneNumber(515,224,6864)); 

  // List all numbers
  Console::WriteLine(L"List all the numbers:");
  for each(PhoneNumber^ number in phonebook->Values)
    Console::WriteLine(number);

  // List names and numbers
  Console::WriteLine(L"Access the keys to list all name/number pairs:");
  for each(Name^ name in phonebook->Keys)
    Console::WriteLine(L"{0} : {1}", name, phonebook[name]);

    return 0;
}
