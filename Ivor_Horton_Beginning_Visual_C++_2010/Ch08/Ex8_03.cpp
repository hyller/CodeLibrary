// Ex8_03.cpp
// Exercising the overloaded 'greater than' operator
#include <iostream>                      // For stream I/O
using std::cout;
using std::endl;

class CBox                               // Class definition at global scope
{
  public:
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

    bool operator>(const CBox& aBox) const;  // Overloaded 'greater than'

    // Destructor definition
    ~CBox()
    {
      cout << "Destructor called." << endl;
    }

  private:
    double m_Length;                         // Length of a box in inches
    double m_Width;                          // Width of a box in inches
    double m_Height;                         // Height of a box in inches
};

// Operator function for 'greater than' that
// compares volumes of CBox objects.
bool CBox::operator>(const CBox& aBox) const
{
  return this->Volume() > aBox.Volume();
}

int main()
{
  CBox smallBox(4.0, 2.0, 1.0);
  CBox mediumBox(10.0, 4.0, 2.0);
  CBox bigBox(30.0, 20.0, 40.0);

  if(mediumBox > smallBox)
    cout << endl
         << "mediumBox is bigger than smallBox";

  if(mediumBox > bigBox)
    cout << endl
         << "mediumBox is bigger than bigBox";
  else
    cout << endl
         << "mediumBox is not bigger than bigBox";

  cout << endl;
  return 0;
}
