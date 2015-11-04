// Ex6_07.cpp
// Using overloaded functions
#include <iostream>
using std::cout;
using std::endl;

int max(int array[], int len);               // Prototypes for
long max(long array[], int len);             // a set of overloaded
double max(double array[], int len);         // functions

int main(void)
{
   int small[] = {1, 24, 34, 22};
   long medium[] = {23, 245, 123, 1, 234, 2345};
   double large[] = {23.0, 1.4, 2.456, 345.5, 12.0, 21.0};

   int lensmall(sizeof small/sizeof small[0]);
   int lenmedium(sizeof medium/sizeof medium[0]);
   int lenlarge(sizeof large/sizeof large[0]);

   cout << endl << max(small, lensmall);
   cout << endl << max(medium, lenmedium);
   cout << endl << max(large, lenlarge);

   cout << endl;
   return 0;
}

// Maximum of ints
int max(int x[], int len)
{
   int maximum(x[0]);
   for(int i = 1; i < len; i++)
      if(maximum < x[i])
         maximum = x[i];
   return maximum;
}

// Maximum of longs
long max(long x[], int len)
{
   long maximum (x[0]);
   for(int i = 1; i < len; i++)
      if(maximum < x[i])
         maximum = x[i];
   return maximum;
}

// Maximum of doubles
double max(double x[], int len)
{
   double maximum(x[0]);
   for(int i = 1; i < len; i++)
      if(maximum < x[i])
         maximum = x[i];
   return maximum;
}
