#pragma once
class CBox
{
public:
public:
   explicit CBox(double lv = 1.0, double wv = 1.0, double hv = 1.0);
   ~CBox(void);
  double GetHeight(void) const  {  return m_Height;  }
  double GetWidth(void) const   {  return m_Width;   }
  double GetLength(void) const  {  return m_Length;  }
  double Volume(void) const     {  return m_Length*m_Width*m_Height;  }

  // Overloaded addition operator
  CBox operator+(const CBox& aBox) const;

  // Multiply a box by an integer
  CBox operator*(int n) const;

  // Divide one box into another
  int operator/(const CBox& aBox) const;

private:
   // Length of a box in inches
   double m_Length;

   // Width of a box in inches
   double m_Width;

   // Height of a box in inches
   double m_Height;
};