// Ex10_09.cpp
// Exercising a stack container

#include <iostream>
#include <stack>
#include <list>
#include "Person.h"

using std::cin;
using std::cout;
using std::endl;
using std::stack;
using std::list;

int main()
{  
  stack<Person, list<Person>> people;

  string first, second;
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
       << " people in the stack." 
       << endl << endl;
  cout << "The names that you entered are:" << endl;
  while(!people.empty())
  {
    people.top().showPerson();
    people.pop();
  }

  return 0;
}
