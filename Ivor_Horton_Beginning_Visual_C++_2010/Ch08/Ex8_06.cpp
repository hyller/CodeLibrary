// Ex8_06.cpp
// Adding CBox objects
#include <iostream>                    // For stream I/O
using std::cout;
using std::endl;

class CBox                             // Class definition at global scope
{
  public:
    // Constructor definition
    explicit CBox(double lv = 1.0, double wv = 1.0, double hv = 1.0): m_Height(hv)
    {
      m_Length = lv > wv ? lv : wv;    // Ensure that
      m_Width = wv < lv ? wv : lv;     // length >= width
    }

    // Function to calculate the volume of a box
    double Volume() const
    {
      return m_Length*m_Width*m_Height;
    }

    // Operator function for 'greater than' which
    // compares volumes of CBox objects.
    bool operator>(const CBox& aBox) const
    {
      return this->Volume() > aBox.Volume();
    }

    // Function to compare a CBox object with a constant
    bool operator>(const double& value) const
    {
      return Volume() > value;
    }

    // Function to add two CBox objects
    CBox operator+(const CBox& aBox) const
    {
      // New object has larger length & width, and sum of heights
      return CBox(m_Length > aBox.m_Length ? m_Length : aBox.m_Length,
                  m_Width > aBox.m_Width   ?  m_Width : aBox.m_Width,
                  m_Height + aBox.m_Height);
    }

    // Function to show the dimensions of a box
    void ShowBox() const
    {
      cout << m_Length << " " << m_Width  << " " << m_Height << endl;
    }

  private:
    double m_Length;                   // Length of a box in inches
    double m_Width;                    // Width of a box in inches
    double m_Height;                   // Height of a box in inches
};

bool operator>(const double& value, const CBox& aBox); // Function prototype

int main()
{
  CBox smallBox(4.0, 2.0, 1.0);
  CBox mediumBox(10.0, 4.0, 2.0);
  CBox aBox;
  CBox bBox;

  aBox = smallBox + mediumBox;
  cout << "aBox dimensions are ";
  aBox.ShowBox();

  bBox = aBox + smallBox + mediumBox;
  cout << "bBox dimensions are ";
  bBox.ShowBox();

  return 0;
}

// Function comparing a constant with a CBox object
bool operator>(const double& value, const CBox& aBox)
{
  return value > aBox.Volume();
}
