// Ex7_13.cpp
// Exercising the indirect member access operator
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
    double Volume() const
    {
      return m_Length*m_Width*m_Height;
    }

    // Function to compare two boxes which returns true
    // if the first is greater that the second, and false otherwise
    bool Compare(CBox* pBox) const
    {
      if(!pBox)
        return 0;
      return this->Volume() > pBox->Volume();
    }

  private:
    double m_Length;                   // Length of a box in inches
    double m_Width;                    // Width of a box in inches
    double m_Height;                   // Height of a box in inches
};

int main()
{
  CBox boxes[5];                       // Array of CBox objects declared
  CBox match(2.2, 1.1, 0.5);           // Declare match box
  CBox cigar(8.0, 5.0, 1.0);           // Declare cigar Box
  CBox* pB1(&cigar);                   // Initialize pointer to cigar object address
  CBox* pB2(nullptr);                  // Pointer to CBox initialized to null

  cout << endl
       << "Address of cigar is " << pB1     // Display address
       << endl
       << "Volume of cigar is "
       << pB1->Volume();                    // Volume of object pointed to

  pB2 = &match;
  if(pB2->Compare(pB1))                     // Compare via pointers
    cout << endl
         << "match is greater than cigar";
  else
    cout << endl
         << "match is less than or equal to cigar";

  pB1 = boxes;                              // Set to address of array
  boxes[2] = match;                         // Set 3rd element to match
  cout << endl                              // Now access thru pointer
       << "Volume of boxes[2] is " << (pB1 + 2)->Volume();

  cout << endl;
  return 0;
}
