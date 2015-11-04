// Ex9_15.cpp : main project file.
// Implementing an interface class
#include "stdafx.h"
#include "Box.h"                       // For Box and IContainer
#include "GlassBox.h"                  // For GlassBox (and Box and IContainer)
#include "Stack.h"                     // For the stack class with nested struct Item 

using namespace System;

int main(array<System::String ^> ^args)
{
 array<IContainer^>^ containers = { gcnew Box(2.0, 3.0, 4.0),
                                    gcnew GlassBox(2.0, 3.0, 4.0),
                                    gcnew Box(4.0, 5.0, 6.0),
                                    gcnew GlassBox(4.0, 5.0, 6.0)
                                  };

  Console::WriteLine(L"The array of containers have the following volumes:");
  for each(IContainer^ container in containers)
    container->ShowVolume();           // Output the volume of a box

  Console::WriteLine(L"\nNow pushing the containers on the stack...");

  Stack^ stack = gcnew Stack;          // Create the stack
  for each(IContainer^ container in containers)
    stack->Push(container);

  
  Console::WriteLine(
          L"Popping the containers off the stack presents them in reverse order:");
  Object^ item;
  while((item = stack->Pop()) != nullptr)
    safe_cast<IContainer^>(item)->ShowVolume();

  Console::WriteLine();
  return 0;
}
