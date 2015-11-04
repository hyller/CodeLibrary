// Ex9_02.cpp
// Using a function inherited from a base class
#include <iostream>                    // For stream I/O
#include <cstring>                     // For strlen() and strcpy()
#include "CandyBox.h"                  // For CBox and CCandyBox
using std::cout;
using std::endl;

int main()
{
  CBox myBox(4.0,3.0,2.0);                       // Create CBox object
  CCandyBox myCandyBox;
  CCandyBox myMintBox("Wafer Thin Mints");       // Create CCandyBox object

  cout << endl
       << "myBox occupies " << sizeof  myBox     // Show how much memory
       << " bytes" << endl                       // the objects require
       << "myCandyBox occupies " << sizeof myCandyBox
       << " bytes" << endl
       << "myMintBox occupies " << sizeof myMintBox    
       << " bytes";
  cout << endl                                 
       << "myMintBox volume is " << myMintBox.Volume(); // Get volume of a 
                                                        // CCandyBox object  
  cout << endl;
  return 0;
}
