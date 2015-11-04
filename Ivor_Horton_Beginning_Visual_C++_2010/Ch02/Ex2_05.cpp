// Ex2_05.cpp
// Calculating how many rolls of wallpaper are required for a room
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
   double height = 0.0, width = 0.0, length = 0.0; // Room dimensions
   double perimeter = 0.0;                         // Room perimeter

   const double rollWidth = 21.0;                  // Standard roll width
   const double rollLength = 12.0*33.0;            // Standard roll length(33ft.)

   int strips_per_roll = 0;                        // Number of strips in a roll
   int strips_reqd = 0;                            // Number of strips needed
   int nrolls = 0;                                 // Total number of rolls

   cout << endl                                    // Start a new line
        << "Enter the height of the room in inches: ";
   cin >> height;

   cout  << endl                                   // Start a new line
         << "Now enter the length and width in inches: ";
   cin >> length >> width;

   strips_per_roll = rollLength / height;          // Get number of strips per roll
   perimeter = 2.0*(length + width);               // Calculate room perimeter
   strips_reqd = perimeter / rollWidth;            // Get total strips required
   nrolls = strips_reqd / strips_per_roll;         // Calculate number of rolls

   cout << endl
        << "For your room you need " << nrolls << " rolls of wallpaper."
        << endl;

   return 0;
}
