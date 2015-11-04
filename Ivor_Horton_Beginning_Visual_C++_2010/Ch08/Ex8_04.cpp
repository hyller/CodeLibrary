// Ex8_04.cpp
// Implementing a complete overloaded 'greater than' operator
#include <iostream>                    // For stream I/O
using std::cout;
using std::endl;

class CBox                             // Class definition at global scope
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

    // Operator function for 'greater than' that
    // compares volumes of CBox objects.
    bool operator>(const CBox& aBox) const
    {
      return this->Volume() > aBox.Volume();
    }

    // Function to compare a CBox object with a constant
    bool operator>(const double& value) const
    {
      return this->Volume() > value;
    }

    // Destructor definition
    ~CBox()
    { cout << "Destructor called." << endl;}

  private:
    double m_Length;                   // Length of a box in inches
    double m_Width;                    // Width of a box in inches
    double m_Height;                   // Height of a box in inches
};

int operator>(const double& value, const CBox& aBox); // Function prototype

int main()
{
  CBox smallBox(4.0, 2.0, 1.0);
  CBox mediumBox(10.0, 4.0, 2.0);

  if(mediumBox > smallBox)
    cout << endl << "mediumBox is bigger than smallBox";

  if(mediumBox > 50.0)
    cout << endl << "mediumBox capacity is more than 50";
  else
    cout << endl << "mediumBox capacity is not more than 50";

  if(10.0 > smallBox)
    cout << endl << "smallBox capacity is less than 10";
  else
    cout << endl << "smallBox capacity is not less than 10";

  cout << endl;
  return 0;
}

// Function comparing a constant with a CBox object
int operator>(const double& value, const CBox& aBox)
{
  return value > aBox.Volume();
}
