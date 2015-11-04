// Ex5_14.cpp
// Using a static variable within a function
#include <iostream>
using std::cout;
using std::endl;

void record(void);      // Function prototype, no arguments or return value

int main(void)
{
   record();

   for(int i = 0; i <= 123; i++)
      record();

   cout << endl;
   return 0;
}

// A function that records how often it is called
void record(void)
{
   static int count(0);
   cout << endl << "This is the " << ++count;
   if((count%100 > 10) && (count%100 < 14))         // All this....
      cout <<"th";
   else
      switch(count%10)                              // is just to get...
      {
         case 1: cout << "st";
                 break;
         case 2: cout << "nd";
                 break;
         case 3: cout << "rd";
                 break;
         default: cout << "th";                    // the right ending for...
      }                                            // 1st, 2nd, 3rd, 4th, etc.
   cout << " time I have been called";
   return;
}