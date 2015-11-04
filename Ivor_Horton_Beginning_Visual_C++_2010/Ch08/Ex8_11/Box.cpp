#include "Box.h"


CBox::CBox(double lv, double wv, double hv)
{
  lv = lv <= 0.0 ? 1.0 : lv;           // Ensure positive
  wv = wv <= 0.0 ? 1.0 : wv;           // dimensions for
  hv = hv <= 0.0 ? 1.0 : hv;           // the object

  m_Length = lv > wv ? lv : wv;        // Ensure that
  m_Width = wv < lv ? wv : lv;         // length >= width
  m_Height = hv;
}


CBox::~CBox(void)
{
}

// Overloaded addition operator
CBox CBox::operator+(const CBox& aBox) const
{
  // New object has larger length and width of the two,
  // and sum of the two heights
  return CBox(m_Length > aBox.m_Length ? m_Length : aBox.m_Length,
              m_Width > aBox.m_Width ? m_Width : aBox.m_Width,
              m_Height + aBox.m_Height);
}

// Multiply a box by an integer
CBox CBox::operator*(int n) const
{
  if(n%2)
    return CBox(m_Length, m_Width, n*m_Height);           // n odd
  else
    return CBox(m_Length, 2.0*m_Width, (n/2)*m_Height);   // n even
}

// Divide one box into another
int CBox::operator/(const CBox& aBox) const
{
  // Temporary for number in horizontal plane this way
  int tc1 = 0;
  // Temporary for number in a plane that way
  int tc2 = 0;

  tc1 = static_cast<int>((m_Length/aBox.m_Length))*
         static_cast<int>((m_Width/aBox.m_Width));	 // to fit this way

  tc2 = static_cast<int>((m_Length/aBox.m_Width))*
        static_cast<int>((m_Width/aBox.m_Length));	 // and that way

  //Return best fit
  return static_cast<int>((m_Height/aBox.m_Height))*(tc1>tc2 ? tc1 : tc2);
}
