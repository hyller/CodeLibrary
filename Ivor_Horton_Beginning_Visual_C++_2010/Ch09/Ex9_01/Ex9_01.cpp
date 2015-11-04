// Ex9_01.cpp
// Using a derived class
#include <iostream>                    // For stream I/O
#include <cstring>                     // For strlen() and strcpy()
#include "CandyBox.h"                  // For CBox and CCandyBox
using std::cout;
using std::endl;


int main()
{
  CBox myBox(4.0, 3.0, 2.0);                     // Create CBox object
  CCandyBox myCandyBox;
  CCandyBox myMintBox("Wafer Thin Mints");       // Create CCandyBox object

  cout << endl
       << "myBox occupies " << sizeof myBox      // Show how much memory
       << " bytes" << endl                       // the objects require
       << "myCandyBox occupies " << sizeof myCandyBox
        << " bytes" << endl
       << "myMintBox occupies " << sizeof myMintBox
       << " bytes";

  cout << endl
       << "myBox length is " << myBox.m_Length;

  myBox.m_Length = 10.0;

  // myCandyBox.m_Length = 10.0;       // uncomment this for an error

  cout << endl;
  return 0;
}
