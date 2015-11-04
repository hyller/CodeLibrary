// Ex9_21.cpp : main project file.

// Using a nested class to define a stack

#include "stdafx.h"
#include "Box.h"                       // For Box and Container
#include "GlassBox.h"                  // For GlassBox (and Box and Container)
#include "Stack.h"                     // For the generic stack class 

using namespace System;

int main(array<System::String ^> ^args)
{
  array<Box^>^ boxes = { gcnew Box(2.0, 3.0, 4.0),
                         gcnew GlassBox(2.0, 3.0, 4.0),
                         gcnew Box(4.0, 5.0, 6.0),
                         gcnew GlassBox(4.0, 5.0, 6.0)
                       };

  Console::WriteLine(L"The array of boxes have the following volumes:");
  for each(Box^ box in boxes)
    box->ShowVolume();                           // Output the volume of a box

  Console::WriteLine(L"\nNow pushing the boxes on the stack...");

  Stack<Box^>^ stack = gcnew Stack<Box^>;        // Create the stack
  for each(Box^ box in boxes)
    stack->Push(box);

  
  Console::WriteLine(
              L"Popping the boxes off the stack presents them in reverse order:");
  Box^ item;
  while((item = stack->Pop()) != nullptr)
    safe_cast<Container^>(item)->ShowVolume();

  // Try the generic Stack type storing integers
  Stack<int>^ numbers = gcnew Stack<int>;        // Create the stack
  Console::WriteLine(L"\nNow pushing integers on to the stack:");
  for(int i = 2 ; i<=12 ; i += 2)
  { 
    Console::Write(L"{0,5}",i);
    numbers->Push(i);
  }
  int number;
  Console::WriteLine(L"\n\nPopping integers off the stack produces:");
  while((number = numbers->Pop()) != 0)
    Console::Write(L"{0,5}",number);

  Console::WriteLine();
  return 0;
}
