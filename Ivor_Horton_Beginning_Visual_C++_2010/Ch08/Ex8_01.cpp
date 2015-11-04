// Ex8_01.cpp
// Class with an explicit destructor
#include <iostream>
using std::cout;
using std::endl;

class CBox                     // Class definition at global scope
{
  public:
    // Destructor definition
    ~CBox()
    {
      cout << "Destructor called." << endl;
    }

    // Constructor definition
    explicit CBox(double lv = 1.0, double wv = 1.0, double hv = 1.0):
                                  m_Length(lv), m_Width(wv), m_Height(hv)
    {
      cout << endl << "Constructor called.";
    }

    // Function to calculate the volume of a box
    double Volume() const
    {
      return m_Length*m_Width*m_Height;
    }

    // Function to compare two boxes which returns true
    // if the first is greater that the second, and false otherwise
    bool compare(CBox* pBox) const
    {
      return this->Volume() > pBox->Volume();
    }

  private:
    double m_Length;         // Length of a box in inches
    double m_Width;          // Width of a box in inches
    double m_Height;         // Height of a box in inches
};

// Function to demonstrate the CBox class destructor in action
int main()
{
  CBox boxes[5];              // Array of CBox objects declared
  CBox cigar(8.0, 5.0, 1.0);  // Declare cigar box
  CBox match(2.2, 1.1, 0.5);  // Declare match box
  CBox* pB1(&cigar);          // Initialize pointer to cigar object address
  CBox* pB2(0);               // Pointer to CBox initialized to null

  cout << endl
       << "Volume of cigar is "
       << pB1->Volume();      // Volume of obj. pointed to

  pB2 = boxes;                // Set to address of array
  boxes[2] = match;           // Set 3rd element to match
  cout << endl
       << "Volume of boxes[2] is "
       << (pB2 + 2)->Volume();  // Now access thru pointer

  cout << endl;
  return 0;
}
