// Box.h for Ex9_14
#pragma once
#include "Container.h"                 // For Container definition

ref class Box : Container              // Derived class
{
  public:
    // Function to show the volume of an object
    virtual void ShowVolume() override
    {
      Console::WriteLine(L"Box usable volume is {0}", Volume()); 
    }

    // Function to calculate the volume of a Box object
    virtual double Volume() override
    { return m_Length*m_Width*m_Height; }

    // Constructor
    Box() : m_Length(1.0), m_Width(1.0), m_Height(1.0){}

    // Constructor
    Box(double lv, double wv, double hv)
                             : m_Length(lv), m_Width(wv), m_Height(hv){}

  protected:
    double m_Length;
    double m_Width;
    double m_Height;
};
