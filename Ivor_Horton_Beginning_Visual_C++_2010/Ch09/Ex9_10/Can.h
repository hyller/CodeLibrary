// Can.h for Ex9_10
#pragma once
#include "Container.h"                 // For CContainer definition
extern const double PI;                // PI is defined elsewhere

class CCan: public CContainer
{
  public:
    // Function to calculate the volume of a can
    virtual double Volume() const
    { return 0.25*PI*m_Diameter*m_Diameter*m_Height; }

    // Constructor
    CCan(double hv = 4.0, double dv = 2.0): m_Height(hv), m_Diameter(dv){}

  protected:
    double m_Height;
    double m_Diameter;
};
