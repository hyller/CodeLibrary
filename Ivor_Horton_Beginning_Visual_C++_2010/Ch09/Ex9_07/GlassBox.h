// GlassBox.h in Ex9_07
#pragma once
#include "Box.h"

class CGlassBox: public CBox           // Derived class
{
  public:
    // Function to calculate volume of a CGlassBox
    // allowing 15% for packing
    virtual double Volume() const
    { return 0.85*m_Length*m_Width*m_Height; }

    // Constructor
    CGlassBox(double lv, double wv, double hv): CBox(lv, wv, hv){}
};
