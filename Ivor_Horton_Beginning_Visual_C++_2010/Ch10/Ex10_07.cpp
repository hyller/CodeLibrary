// Ex10_07.cpp
// Exercising a queue container

#include <iostream>
#include <queue>
#include <string>


using std::cin;
using std::cout;
using std::endl;
using std::queue;
using std::string;


int main()
{
  queue<string> sayings;
  string saying;
  cout << "Enter one or more sayings. Press Enter to end." << endl;
  while(true)
  {
    getline(cin, saying);
    if(saying.empty())
      break;
    sayings.push(saying);
  }

  cout << "There are " << sayings.size()
       << " sayings in the queue." 
       << endl << endl;
  cout << "The sayings that you entered are:" << endl;
  while(!sayings.empty())
  {
    cout << sayings.front() << endl;
    sayings.pop();
  }

  return 0;
}
