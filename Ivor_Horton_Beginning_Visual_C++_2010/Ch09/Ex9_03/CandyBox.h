// CandyBox.h in Ex9_03
#pragma once
#include <iostream>
#include "Box.h"
using std::cout;
using std::endl;

class CCandyBox: public CBox
{
  public:
    char* m_Contents;

    // Constructor to set dimensions and contents
    // with explicit call of CBox constructor
    CCandyBox(double lv, double wv, double hv, char* str = "Candy")
                                                        :CBox(lv, wv, hv)
    {
      cout << endl <<"CCandyBox constructor2 called";
      m_Contents = new char[ strlen(str) + 1 ];
      strcpy_s(m_Contents, strlen(str) + 1, str);
    }

    // Constructor to set contents
    // calls default CBox constructor automatically
    CCandyBox(char* str = "Candy")
    {
      cout << endl << "CCandyBox constructor1 called";
      m_Contents = new char[ strlen(str) + 1 ];
      strcpy_s(m_Contents, strlen(str) + 1, str);
    }

    ~CCandyBox()                                 // Destructor
    { delete[] m_Contents; }
};
