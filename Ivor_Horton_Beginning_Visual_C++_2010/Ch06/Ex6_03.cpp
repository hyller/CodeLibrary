// Ex6_03.cpp
// Omitting function arguments
#include <iostream>
using std::cout;
using std::endl;

void showit(const char message[] = "Something is wrong.");

int main(void)
{
  const char mymess[] = "The end of the world is nigh.";

  showit();                                 // Display the basic message
  showit("Something is terribly wrong!");   // Display an alternative
  showit();                                 // Display the default again
  showit(mymess);                           // Display a predefined message

  cout << endl;
  return 0;
}

void showit(const char message[])
{
  cout << endl
       << message;
  return;
}