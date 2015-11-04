// Ex6_08.cpp
// Using function templates

#include <iostream>
using std::cout;
using std::endl;

// Template for function to compute the maximum element of an array
template<typename T> T max(T x[], int len)
{
   T maximum(x[0]);
   for(int i = 1; i < len; i++)
      if(maximum < x[i])
         maximum = x[i];
   return maximum;
}

int main(void)
{
   int small[] = { 1, 24, 34, 22};
   long medium[] = { 23, 245, 123, 1, 234, 2345};
   double large[] = { 23.0, 1.4, 2.456, 345.5, 12.0, 21.0};

   int lensmall(sizeof small/sizeof small[0]);
   int lenmedium(sizeof medium/sizeof medium[0]);
   int lenlarge(sizeof large/sizeof large[0]);

   cout << endl << max(small, lensmall);
   cout << endl << max(medium, lenmedium);
   cout << endl << max(large, lenlarge);

   cout << endl;
   return 0;
}
