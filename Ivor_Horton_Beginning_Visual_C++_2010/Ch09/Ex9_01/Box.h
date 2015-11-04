// Header file Box.h in project Ex9_01
#pragma once

class CBox
{
  public:
    double m_Length;
    double m_Width;
    double m_Height;

    CBox(double lv = 1.0, double wv = 1.0, double hv = 1.0):
                                m_Length(lv), m_Width(wv), m_Height(hv){}
};
