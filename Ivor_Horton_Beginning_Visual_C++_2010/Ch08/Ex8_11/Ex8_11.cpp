// Ex8_11.cpp
// A sample packaging problem
#include <iostream>
#include "Box.h"
#include "BoxOperators.h"
using std::cout;
using std::endl;

int main()
{
   CBox candy(1.5, 1.0, 1.0);             // Candy definition
   CBox candyBox(7.0, 4.5, 2.0);          // Candy box definition
   CBox carton(30.0, 18.0, 18.0);         // Carton definition

   // Calculate candies per candy box
   int numCandies = candyBox/candy;

   // Calculate candy boxes per carton
   int numCboxes = carton/candyBox;

   // Calculate wasted carton space
   double space = carton%candyBox;

   cout << endl << "There are " << numCandies << " candies per candy box" << endl
        << "For the standard boxes there are " << numCboxes
        << " candy boxes per carton " << endl << "with "
        << space << " cubic inches wasted.";

   cout << endl << endl << "CUSTOM CANDY BOX ANALYSIS (No Waste)";

   // Try the whole range of custom candy boxes
   for(double length = 3.0 ; length <= 7.5 ; length += 0.5)
   {
      for(double width = 3.0 ; width <= 5.0 ; width += 0.5)
      {
         for(double height = 1.0 ; height <= 2.5 ; height += 0.5)
         {
            // Create new box each cycle
            CBox tryBox(length, width, height);

            if(carton%tryBox < tryBox.Volume() &&
                               tryBox % candy == 0.0 && tryBox/candy >= 30)
               cout << endl << endl
                    << "Trial Box L = " << tryBox.GetLength()
                    << " W = " << tryBox.GetWidth()
                    << " H = " << tryBox.GetHeight()
                    << endl
                    << "Trial Box contains " << tryBox / candy << " candies"
                    << " and a carton contains " << carton / tryBox
                    << " candy boxes.";
         }
      }
   }
   cout << endl;
   return 0;
}
