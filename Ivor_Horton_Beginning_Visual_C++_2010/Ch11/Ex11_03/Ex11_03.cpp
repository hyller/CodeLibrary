// Ex11_03.cpp : main project file.
// CLR trace and debug output

#include "stdafx.h"

using namespace System;
using namespace System::Diagnostics;

public ref class TraceTest
{
public:
  TraceTest(int n):value(n){}

  property TraceLevel Level
  {
    void set(TraceLevel level) {sw->Level = level; }
    TraceLevel get(){return sw->Level; }
  }
  
  void FunA()
  {
    ++value;
    Trace::Indent();
    Trace::WriteLine(L"Starting FunA");
    if(sw->TraceInfo)
      Debug::WriteLine(L"FunA working...");
    FunB();
    Trace::WriteLine(L"Ending FunA");
    Trace::Unindent();
  }
 
  void FunB()
  {
    Trace::Indent();
    Trace::WriteLine(L"Starting FunB");
    if(sw->TraceWarning)
      Debug::WriteLine(L"FunB warning...");
    FunC();
    Trace::WriteLine(L"Ending FunB");
    Trace::Unindent();
  }

  void FunC()
  {
    Trace::Indent();
    Trace::WriteLine(L"Starting FunC");
    if(sw->TraceError)
      Debug::WriteLine(L"FunC error...");
    Debug::Assert(value < 4);
    Trace::WriteLine(L"Ending FunC");
    Trace::Unindent();
  }
private:
  int value;
  static TraceSwitch^ sw =
                      gcnew TraceSwitch(L"Trace Switch", L"Controls trace output");
};

int main(array<System::String ^> ^args)
{
  // Direct output to the command line
  TextWriterTraceListener^ listener = gcnew TextWriterTraceListener( Console::Out);
  Debug::Listeners->Add(listener);

  Debug::IndentSize = 2;              // Set the indent size

  array<TraceLevel>^ levels = { TraceLevel::Off,     TraceLevel::Error,
                                TraceLevel::Warning ,TraceLevel::Verbose};
  TraceTest^ obj = gcnew TraceTest(0);

  Console::WriteLine(L"Starting trace and debug test...");
  for each(TraceLevel level in levels)
  {
    obj->Level = level;                // Set level for messages
    Console::WriteLine(L"\nTrace level is {0}", obj->Level);
    obj->FunA();
  }
 return 0;
}
