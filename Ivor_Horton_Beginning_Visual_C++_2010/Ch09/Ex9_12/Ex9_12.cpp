// Ex9_12.cpp
// Destructor calls with derived classes
// using objects via a base class pointer

// You need to uncomment the virtual keyword in Container.h for proper operation...


#include "Box.h"                       // For CBox and CContainer
#include "Can.h"                       // For CCan (and CContainer)
#include "GlassBox.h"                  // For CGlassBox (and CBox and CContainer)
#include <iostream>                    // For stream I/O
using std::cout;
using std::endl;

const double PI = 3.14159265;          // Global definition for PI

int main()
{
  // Pointer to abstract base class initialized with CBox object address
  CContainer* pC1 = new CBox(2.0, 3.0, 4.0);

  CCan myCan(6.5, 3.0);                // Define CCan object
  CGlassBox myGlassBox(2.0, 3.0, 4.0); // Define CGlassBox object

  pC1->ShowVolume();                   // Output the volume of CBox
  cout << endl << "Delete CBox" << endl;
  delete pC1;                          // Now clean up the free store

  pC1 = new CGlassBox(4.0, 5.0, 6.0);  // Create CGlassBox dynamically
  pC1->ShowVolume();                   // ...output its volume...
  cout << endl << "Delete CGlassBox" << endl;
  delete pC1;                          // ...and delete it

  pC1 = &myCan;                        // Get myCan address in pointer
  pC1->ShowVolume();                   // Output the volume of CCan

  pC1 = &myGlassBox;                   // Get myGlassBox address in pointer
  pC1->ShowVolume();                   // Output the volume of CGlassBox

  cout << endl;
  return 0;
}
