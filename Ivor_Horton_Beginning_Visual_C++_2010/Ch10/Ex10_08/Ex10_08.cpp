// Ex10_08.cpp
// Exercising a priority queue container

#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include "Person.h"

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::priority_queue;
using std::greater;

int main()
{
  priority_queue<Person, vector<Person>, greater<Person>> people;
  string first, second;;
  while(true)
  {
    cout << "Enter a first name or press Enter to end: " ;
    getline(cin, first);
    if(first.empty())
      break;

    cout << "Enter a second name: " ;
    getline(cin, second);
    people.push(Person(first, second));
  }

  cout << endl << "There are " << people.size()
       << " people in the queue." 
       << endl << endl;

  cout << "The names that you entered are:" << endl;
  while(!people.empty())
  {
    people.top().showPerson();
    people.pop();
  }

  return 0;
}
