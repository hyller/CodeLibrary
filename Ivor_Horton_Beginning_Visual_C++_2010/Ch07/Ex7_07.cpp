// Ex7_07.cpp
// A class with private members
#include <iostream>
using std::cout;
using std::endl;

class CBox                             // Class definition at global scope
{
  public:
    // Constructor definition using an initialisation list
    explicit CBox(double lv = 1.0, double bv = 1.0, double hv = 1.0):
                             m_Length(lv), m_Width(bv), m_Height(hv)
   {
     cout << endl << "Constructor called.";
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
};

int main()
{
  CBox match(2.2, 1.1, 0.5);           // Declare match box
  CBox box2;                           // Declare box2 - no initial values

  cout << endl
       << "Volume of match = "
       << match.Volume();

// Uncomment the following line to get an error
// box2.m_Length = 4.0;

  cout << endl
       << "Volume of box2 = "
       << box2.Volume();
  cout << endl;

  return 0;
}
