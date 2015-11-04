// Container.h for Ex9_21
#pragma once
using namespace System;

// Abstract base class for specific containers
ref class Container abstract      
{
  public:
    // Function for calculating a volume - no content
    // This is defined as an 'abstract' virtual function,
    // indicated by the 'abstract' keyword
     virtual double Volume() abstract;

    // Function to display a volume
    virtual void ShowVolume() 
    {
      Console::WriteLine(L"Volume is {0}", Volume());
    }
};
