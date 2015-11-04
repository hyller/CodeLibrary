// Ex6_11.cpp : main project file.
// Defining and using generic functions

#include "stdafx.h"

using namespace System;

// Generic function to find the maximum element in an array
generic<typename T> where T:IComparable
T MaxElement(array<T>^ x)
{
  T max(x[0]);
  for(int i = 1; i < x->Length; i++)
    if(max->CompareTo(x[i]) < 0)
       max = x[i];
  return max;
}

// Generic function to remove an element from an array
generic<typename T> where T:IComparable
array<T>^ RemoveElement(T element, array<T>^ data)
{
  array<T>^ newData = gcnew array<T>(data->Length - 1);
  int index(0);                  // Index to elements in newData array
  bool found(false);             // Indicates that the element to remove was found
  for each(T item in data)
  {
    // Check for invalid index or element found
    if((!found) && item->CompareTo(element) == 0)
    {
      found = true;
      continue;
    }
    else
    {
      if(newData->Length == index)
      {
        Console::WriteLine(L"Element to remove not found");
        return data;
      }
      newData[index++] = item;
    }
  }
    return newData;
}

// Generic function to list an array
generic<typename T>
void ListElements(array<T>^ data)
{
  for each(T item in data)
    Console::Write(L"{0,10}", item);
  Console::WriteLine();
}

int main(array<System::String ^> ^args)
{
  array<double>^ data = {1.5, 3.5, 6.7, 4.2, 2.1};
  Console::WriteLine(L"Array contains:");
  ListElements(data);
  Console::WriteLine(L"\nMaximum element = {0}\n", MaxElement(data));
  array<double>^ result = RemoveElement(MaxElement(data), data);
  Console::WriteLine(L" After removing maximum, array contains:");
  ListElements(result);

  array<int>^ numbers = {3, 12, 7, 0, 10,11};
  Console::WriteLine(L"\nArray contains:");
  ListElements(numbers);
  Console::WriteLine(L"\nMaximum element = {0}\n", MaxElement(numbers));
  Console::WriteLine(L"\nAfter removing maximum, array contains:");
  ListElements(RemoveElement(MaxElement(numbers), numbers));

  array<String^>^ strings = {L"Many", L"hands", L"make", L"light", L"work"};
  Console::WriteLine(L"\nArray contains:");
  ListElements(strings);
  Console::WriteLine(L"\nMaximum element = {0}\n", MaxElement(strings));
  Console::WriteLine(L"\nAfter removing maximum, array contains:");
  ListElements(RemoveElement(MaxElement(strings), strings));
  return 0;
}
