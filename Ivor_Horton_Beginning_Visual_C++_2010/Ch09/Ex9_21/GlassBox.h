// GlassBox.h for Ex9_21
#pragma once
#include "Box.h"                       // For Box

ref class GlassBox : Box               // Derived class
{
  public:
   // Function to calculate volume of a GlassBox
    // allowing 15% for packing
    virtual double Volume() override 
    { return 0.85*m_Length*m_Width*m_Height; }

    // Constructor
    GlassBox(double lv, double wv, double hv): Box(lv, wv, hv){}
};
