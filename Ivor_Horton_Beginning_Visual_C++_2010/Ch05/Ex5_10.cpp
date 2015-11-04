// Ex5_10.cpp
// Reading command line arguments
#include <iostream>
using std::cout;
using std::endl;

int main(int argc, char* argv[])
{
  cout << endl << "argc = " << argc << endl;
  cout << "Command line arguments received are:" << endl;
  for(int i = 0 ; i <argc ; i++)
    cout << "argument " << (i+1) << ": " << argv[i] << endl;
  return 0;
}
