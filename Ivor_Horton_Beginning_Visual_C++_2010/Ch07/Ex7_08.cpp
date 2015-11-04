// Ex7_08.cpp
// Creating a friend function of a class
#include <iostream>
using std::cout;
using std::endl;

class CBox                             // Class definition at global scope
{
  public:

    // Constructor definition
    explicit CBox(double lv = 1.0, double bv = 1.0, double hv = 1.0)
    {
      cout << endl << "Constructor called.";
      m_Length = lv;                   // Set values of
      m_Width = bv;                    // data members
      m_Height = hv;
    }

    // Function to calculate the volume of a box
    double Volume()
    {
      return m_Length*m_Width*m_Height;
    }

  private:
    double m_Length;                   // Length of a box in inches
    double m_Width;                    // Width of a box in inches
    double m_Height;                   // Height of a box in inches

  // Friend function
  friend double BoxSurface(CBox aBox);
};

// friend function to calculate the surface area of a Box object
double BoxSurface(CBox aBox)
{
  return 2.0*(aBox.m_Length*aBox.m_Width +
              aBox.m_Length*aBox.m_Height +
              aBox.m_Height*aBox.m_Width);
}

int main()
{
  CBox match(2.2, 1.1, 0.5);           // Declare match box
  CBox box2;                           // Declare box2 - no initial values

  cout << endl
       << "Volume of match = "
       << match.Volume();

  cout << endl
       << "Surface area of match = "
       << BoxSurface(match);

  cout << endl
       << "Volume of box2 = "
       << box2.Volume();

  cout << endl
       << "Surface area of box2 = "
       << BoxSurface(box2);

  cout << endl;
  return 0;
}
