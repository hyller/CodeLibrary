// CandyBox.h in Ex9_05
#pragma once
#include "Box.h"
#include <iostream>
using std::cout;
using std::endl;

class CCandyBox: public CBox
{
  public:
    char* m_Contents;

    // Derived class function to calculate volume
    double Volume() const
    { return m_Length*m_Width*m_Height; }

    // Constructor to set dimensions and contents
    // with explicit call of CBox constructor
    CCandyBox(double lv, double wv, double hv, char* str = "Candy")
                                          :CBox(lv, wv, hv)  // Constructor
    {
      cout << endl <<"CCandyBox constructor2 called";
      m_Contents = new char[ strlen(str) + 1 ];
      strcpy_s(m_Contents, strlen(str) + 1, str);
    }

    // Constructor to set contents
    // calls default CBox constructor automatically
    CCandyBox(char* str = "Candy")               // Constructor
    {
      cout << endl << "CCandyBox constructor1 called";
      m_Contents = new char[ strlen(str) + 1 ];
      strcpy_s(m_Contents, strlen(str) + 1, str);
    }

    // Derived class copy constructor
    CCandyBox(const CCandyBox& initCB)
     // Uncomment the following line to call the base class copy constructor 
      //: CBox(initCB)
    {
      cout << endl << "CCandyBox copy constructor called";

      // Get new memory
      m_Contents = new char[ strlen(initCB.m_Contents) + 1 ];

      // Copy string
      strcpy_s(m_Contents, strlen(initCB.m_Contents) + 1, initCB.m_Contents);
    }
/*      Uncomment this to add the move constructor
    // Move constructor
    CCandyBox(CCandyBox&& initCB): CBox(initCB)
    {
      cout << endl << "CCandyBox move constructor called";
      m_Contents = initCB.m_Contents;
      initCB.m_Contents = 0;
    }
*/
    // Destructor
    ~CCandyBox()    
    {
      cout << "CCandyBox destructor called" << endl;
      delete[] m_Contents;
    }
};
