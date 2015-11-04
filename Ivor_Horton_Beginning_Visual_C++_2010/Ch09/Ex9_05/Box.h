// Box.h in Ex9_05
#pragma once
#include <iostream>
using std::cout;
using std::endl;

class CBox                   // Base class definition
{
  public:
    // Base class constructor
    CBox(double lv = 1.0, double wv = 1.0, double hv = 1.0):
                         m_Length(lv), m_Width(wv), m_Height(hv)
    {  cout << endl << "CBox constructor called";  }

    // Copy constructor
    CBox(const CBox& initB)
    {
      cout << endl << "CBox copy constructor called";
      m_Length = initB.m_Length;
      m_Width = initB.m_Width;
      m_Height = initB.m_Height;
    }

    // CBox destructor - just to track calls
    ~CBox()
    { cout << "CBox destructor called" << endl; }

  protected:
    double m_Length;
    double m_Width;
    double m_Height;
};
