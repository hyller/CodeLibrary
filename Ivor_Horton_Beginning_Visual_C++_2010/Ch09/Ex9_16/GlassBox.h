// GlassBox.h for Ex9_16
#pragma once
#using <Ex9_16lib.dll>
using namespace Ex9_16lib;

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
