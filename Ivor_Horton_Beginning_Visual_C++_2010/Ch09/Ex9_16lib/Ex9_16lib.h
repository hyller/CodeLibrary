// Ex9_16lib.h

#pragma once

using namespace System;

namespace Ex9_16lib
{
// IContainer.h for Ex9_16 
public interface class IContainer
{
  virtual double Volume();             // Function for calculating a volume
  virtual void ShowVolume();           // Function to display a volume
};

  
// Box.h for Ex9_16
public ref class Box : IContainer     
{
  public:
    // Function to show the volume of an object
    virtual void ShowVolume()
    {
      Console::WriteLine(L"CBox usable volume is {0}", Volume()); 
    }

    // Function to calculate the volume of a Box object
    virtual double Volume()
    { return m_Length*m_Width*m_Height; }

    // Constructor
    Box() : m_Length(1.0), m_Width(1.0), m_Height(1.0){}

    // Constructor
    Box(double lv, double wv, double hv)
                             : m_Length(lv), m_Width(wv), m_Height(hv){}

  public protected:
    double m_Length;
    double m_Width;
    double m_Height;
};

// Stack.h for Ex9_16
public ref class Stack
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

  Item^ Top;                          // Handle for item that is at the top

public:
  // Push an object onto the stack
  void Push(Object^ obj)
  {
    Top = gcnew Item(obj, Top);        // Create new item and make it the top
  }

  // Pop an  object off the stack
  Object^ Pop()
  {  
    if(Top == nullptr)                 // If the stack is empty
      return nullptr;                  // return nullptr

    Object^ obj = Top->Obj;            // Get box from item
    Top = Top->Next;                   // Make next item the top 
    return obj;
  }
};
}
