// Ex6_04.cpp  Using exception handling
#include <iostream>
using std::cout;
using std::endl;

int main(void)
{
  int counts[] = {34, 54, 0, 27, 0, 10, 0};
  int time(60);                        // One hour in minutes

  for(int i = 0 ; i < sizeof counts/sizeof counts[0] ; i++)
    try
    {
      cout << endl << "Hour " << i+1;

      if(0 == counts[i])
        throw "Zero count - calculation not possible.";

      cout << " minutes per item: " << static_cast<double>(time)/counts[i];
    }
    catch(const char aMessage[])
    {
      cout << endl << aMessage << endl;
    }
  return 0;
}
