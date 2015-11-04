// Can.h for Ex9_12
#pragma once
#include "Container.h"                 // For CContainer definition
extern const double PI;

class CCan: public CContainer
{
  public:
    // Destructor
    ~CCan()
    { cout << "CCan destructor called" << endl; }

    // Function to calculate the volume of a can
    virtual double Volume() const
    { return 0.25*PI*m_Diameter*m_Diameter*m_Height; }

    // Constructor
    CCan(double hv = 4.0, double dv = 2.0): m_Height(hv), m_Diameter(dv){}

  protected:
    double m_Height;
    double m_Diameter;
};
