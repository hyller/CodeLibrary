// Ex9_03.cpp
// Calling a base constructor from a derived class constructor
#include <iostream>                    // For stream I/O
#include <cstring>                     // For strlen() and strcpy()
#include "CandyBox.h"                  // For CBox and CCandyBox
using std::cout;
using std::endl;


int main()
{
  CBox myBox(4.0, 3.0, 2.0);
  CCandyBox myCandyBox;
  CCandyBox myMintBox(1.0, 2.0, 3.0, "Wafer Thin Mints");

  cout << endl
       << "myBox occupies " << sizeof  myBox     // Show how much memory
       << " bytes" << endl                       // the objects require
       << "myCandyBox occupies " << sizeof myCandyBox
       << " bytes" << endl
       << "myMintBox occupies " << sizeof myMintBox
       << " bytes";
  cout << endl
       << "myMintBox volume is "                 // Get volume of a
       << myMintBox.Volume();                    // CCandyBox object
  cout << endl;
  return 0;
}
