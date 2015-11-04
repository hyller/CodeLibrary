// Ex9_14.cpp : main project file.
// Using a nested class to define a stack

#include "stdafx.h"
#include "Box.h"                  // For Box and Container
#include "GlassBox.h"             // For GlassBox (and Box and Container)
#include "Stack.h"                // For the stack class with nested struct Item 

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
    box->ShowVolume();           // Output the volume of a box

  Console::WriteLine(L"\nNow pushing the boxes on the stack...");

  Stack^ stack = gcnew Stack;         // Create the stack
  for each(Box^ box in boxes)
    stack->Push(box);
  
  Console::WriteLine(
              L"Popping the boxes off the stack presents them in reverse order:");
  Object^ item;
  while((item = stack->Pop()) != nullptr)
    safe_cast<Container^>(item)->ShowVolume();


  Console::WriteLine(L"\nNow pushing integers onto the stack:");
  for(int i = 2 ; i<=12 ; i += 2)
  { 
    Console::Write(L"{0,5}",i);
    stack->Push(i);
  }

  Console::WriteLine(L"\n\nPopping integers off the stack produces:");
  while((item = stack->Pop()) != nullptr)
    Console::Write(L"{0,5}",item);

  Console::WriteLine();
  return 0;
}
