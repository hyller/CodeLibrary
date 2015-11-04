// Box.h in Ex9_02
#pragma once

class CBox
{
  public:
    CBox(double lv = 1.0, double wv = 1.0, double hv = 1.0):
                             m_Length(lv), m_Width(wv), m_Height(hv){}

    //Function to calculate the volume of a CBox object
    double Volume() const
    { return m_Length*m_Width*m_Height; }

  private:
    double m_Length;
    double m_Width;
    double m_Height;
};
