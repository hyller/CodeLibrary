// Stack.h for Ex9_15
// A push-down stack to store objects of any ref class type
#pragma once

ref class Stack
{
private:
  // Defines items to store in the stack
  ref struct Item
  {
    Object^ Obj;                  // Handle for the object in this item
    Item^ Next;                   // Handle for next item in the stack or nullptr

    // Constructor
    Item(Object^ obj, Item^ next): Obj(obj), Next(next){}
  };

  Item^ Top;                       // Handle for item that is at the top

public:
  // Push an object onto the stack
  void Push(Object^ obj)
  {
    Top = gcnew Item(obj, Top);     // Create new item and make it the top
  }

  // Pop an  object off the stack
  Object^ Pop()
  {  
    if(Top == nullptr)                 // If the stack is empty
      return nullptr;                  // return nullptr

    Object^ obj = Top->Obj;            // Get object from item
    Top = Top->Next;                   // Make next item the top 
    return obj;
  }
};
