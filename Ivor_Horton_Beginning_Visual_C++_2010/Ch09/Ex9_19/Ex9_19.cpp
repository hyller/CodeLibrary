// Ex9_19.cpp : main project file.
// Defining, triggering and handling events.
#include "stdafx.h"

using namespace System;

public delegate void DoorHandler(String^ str);

// Class with an event member
public ref class Door
{
public:
  // An event that will call functions associated
  // with a DoorHandler delegate object
  event DoorHandler^ Knock;      

  // Function to trigger events
  void TriggerEvents()
  {
    Knock(L"Fred");
    Knock(L"Jane");
  }
};

// Class defining handler functions for Knock events
public ref class AnswerDoor
{
public:
  void ImIn(String^ name)
  {
    Console::WriteLine(L"Come in {0}, it's open.",name);
  }

  void ImOut(String^ name)
  {
    Console::WriteLine(L"Go away {0}, I'm out.",name);
  }
};

int main(array<System::String ^> ^args)
{
  Door^ door = gcnew Door;
  AnswerDoor^ answer = gcnew AnswerDoor;

  // Add handler for Knock event member of door
  door->Knock += gcnew DoorHandler(answer, &AnswerDoor::ImIn);

  door->TriggerEvents();               // Trigger Knock events

  // Change the way a knock is dealt with
  door->Knock -= gcnew DoorHandler(answer, &AnswerDoor::ImIn);
  door->Knock += gcnew DoorHandler(answer, &AnswerDoor::ImOut);
  door->TriggerEvents();               // Trigger Knock events
  return 0;
}
