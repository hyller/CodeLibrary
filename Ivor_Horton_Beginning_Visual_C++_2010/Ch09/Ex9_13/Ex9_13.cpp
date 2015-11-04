// Ex9_13.cpp
// Using a nested class to define a stack
#include "Box.h"                       // For CBox and CContainer
#include "GlassBox.h"                  // For CGlassBox (and CBox and CContainer)
#include "Stack.h"                     // For the stack class with nested struct Item 

#include <iostream>                    // For stream I/O
using std::cout;
using std::endl;


int main()
{
  CBox* pBoxes[] = { new CBox(2.0, 3.0, 4.0),
                     new CGlassBox(2.0, 3.0, 4.0),
                     new CBox(4.0, 5.0, 6.0),
                     new CGlassBox(4.0, 5.0, 6.0)
                   };
  int nBoxes = sizeof pBoxes/ sizeof pBoxes[0];
  cout << "The array of boxes have the following volumes:";
  for (int i = 0 ; i<nBoxes ; i++)
    pBoxes[i]->ShowVolume();           // Output the volume of a box

  cout << endl << endl << "Now pushing the boxes on the stack..." << endl;
  CStack* pStack = new CStack;         // Create the stack
  for (int i = 0 ; i<nBoxes ; i++)
    pStack->Push(pBoxes[i]);

  
  cout << "Popping the boxes off the stack presents them in reverse order:";
CBox* pTemp(nullptr);
while(pTemp = pStack->Pop())
  pTemp->ShowVolume();

  cout << endl;

  delete pStack;
  for(int i = 0 ; i<nBoxes ; ++i)
    delete pBoxes[i];
  return 0;
}
