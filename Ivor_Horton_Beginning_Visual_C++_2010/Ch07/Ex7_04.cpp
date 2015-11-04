// Ex7_04.cpp
// Using a constructor
#include <iostream>
using std::cout;
using std::endl;

class CBox                             // Class definition at global scope
{
  public:
    double m_Length;                   // Length of a box in inches
    double m_Width;                    // Width of a box in inches
    double m_Height;                   // Height of a box in inches

    // Constructor definition
    CBox(double lv, double bv, double hv)
    {
      cout << endl << "Constructor called.";
      m_Length = lv;                   // Set values of
      m_Width = bv;                    // data members
      m_Height = hv;
    }

    // Function to calculate the volume of a box
    double Volume()
    {
      return m_Length* m_Width* m_Height;
    }
};

int main()
{
  CBox box1(78.0,24.0,18.0);           // Declare and initialize box1
  CBox cigarBox(8.0,5.0,1.0);          // Declare and initialize cigarBox

  double boxVolume(0.0);               // Stores the volume of a box

  boxVolume = box1.Volume();           // Calculate volume of box1
  cout << endl
       << "Volume of box1 = " << boxVolume;

  cout << endl
       << "Volume of cigarBox = "
       << cigarBox.Volume();

  cout << endl;
  return 0;
}
