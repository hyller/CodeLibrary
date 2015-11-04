// Ex7_12.cpp
// Using a static data member in a class
#include <iostream>
using std::cout;
using std::endl;

class CBox                             // Class definition at global scope
{
  public:
    static int objectCount;            // Count of objects in existence

    // Constructor definition
    explicit CBox(double lv, double bv = 1.0, double hv = 1.0)
    {
      cout << endl << "Constructor called.";
      m_Length = lv;                   // Set values of
      m_Width = bv;                    // data members
      m_Height = hv;
      objectCount++;
    }

    CBox()                             // Default constructor
    {
      cout << endl
           << "Default constructor called.";
      m_Length = m_Width = m_Height = 1.0;
      objectCount++;
    }

    // Function to calculate the volume of a box
    double Volume() const
    {
      return m_Length*m_Width*m_Height;
    }

  private:
    double m_Length;                   // Length of a box in inches
    double m_Width;                    // Width of a box in inches
    double m_Height;                   // Height of a box in inches
};

int CBox::objectCount(0);              // Initialize static member of CBox class

int main()
{
  CBox boxes[5];                       // Array of CBox objects declared
  CBox cigar(8.0, 5.0, 1.0);           // Declare cigar box

  cout << endl << endl
       << "Number of objects (through class) = "
       << CBox::objectCount;

  cout << endl
       << "Number of objects (through object) = "
       << boxes[2].objectCount;

  cout << endl;
  return 0;
}
