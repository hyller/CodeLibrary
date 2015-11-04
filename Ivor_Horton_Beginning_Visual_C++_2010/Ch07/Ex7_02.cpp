// Ex7_02.cpp
// Creating and using boxes
#include <iostream>
using std::cout;
using std::endl;

class CBox                             // Class definition at global scope
{
  public:
    double m_Length;                   // Length of a box in inches
    double m_Width;                    // Width of a box in inches
    double m_Height;                   // Height of a box in inches
};

int main()
{
  CBox box1;                           // Declare box1 of type CBox
  CBox box2;                           // Declare box2 of type CBox

  double boxVolume(0.0);               // Stores the volume of a box

  box1.m_Height = 18.0;                // Define the values
  box1.m_Length = 78.0;                // of the members of
  box1.m_Width = 24.0;                 // the object box1

  box2.m_Height = box1.m_Height - 10;  // Define box2
  box2.m_Length = box1.m_Length/2.0;   // members in
  box2.m_Width = 0.25*box1.m_Length;   // terms of box1

  // Calculate volume of box1
  boxVolume = box1.m_Height*box1.m_Length*box1.m_Width;

  cout << endl
       << "Volume of box1 = " << boxVolume;

  cout << endl
       << "box2 has sides which total "
       << box2.m_Height+ box2.m_Length+ box2.m_Width
       << " inches.";

  cout << endl                         // Display the size of a box in memory
       << "A CBox object occupies "
       << sizeof box1 << " bytes.";

  cout << endl;
  return 0;
}
