// Ex9_17.cpp : main project file.
// Creating and calling delegates

#include "stdafx.h"

using namespace System;

public ref class HandlerClass
{
public:
  static void Fun1(int m) 
  { Console::WriteLine(L"Function1 called with value {0}", m); }

  static void Fun2(int m) 
  { Console::WriteLine(L"Function2 called with value {0}", m); }

  void Fun3(int m) 
  { Console::WriteLine(L"Function3 called with value {0}", m+value); }

  void Fun4(int m) 
  { Console::WriteLine(L"Function4 called with value {0}", m+value); }

  HandlerClass():value(1){}

  HandlerClass(int m):value(m){}
protected:
  int value;
};

public delegate void Handler(int value);         // Delegate declaration

int main(array<System::String ^> ^args)
{
  Handler^ handler = gcnew Handler(HandlerClass::Fun1); // Delegate object
  Console::WriteLine(L"Delegate with one pointer to a static function:");
  handler->Invoke(90);

  handler += gcnew Handler(HandlerClass::Fun2);
  Console::WriteLine(L"\nDelegate with two pointers to static functions:");
  handler->Invoke(80);

  HandlerClass^ obj = gcnew HandlerClass;
  Handler^ handler2 = gcnew Handler (obj, &HandlerClass::Fun3);
  handler += handler2;
  Console::WriteLine(L"\nDelegate with three pointers to functions:");
  handler(70);

  Console::WriteLine(L"\nShortening the invocation list...");
  handler -= gcnew Handler(HandlerClass::Fun1);
  Console::WriteLine
           (L"\nDelegate with pointers to one static and one instance function:");
  handler(60);
  return 0;
}
