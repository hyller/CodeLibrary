// Ex13_01.cpp  Terminating a parallel operation
#include <iostream>
#include "ppl.h"
#include <array>
#include <string>
using namespace std;
using namespace Concurrency;

// Find name as the first name in any people element
int findIndex(const array<std::string, 6>& people, const string& name)
{
  try
  {
    parallel_for(static_cast<size_t>(0), people.size(), [=](size_t n)
    {
      size_t space(people[n].find(' '));
      if(people[n].substr(0, space) == name)
        throw n;
    });
  } catch(size_t index) { return index;  }
  return -1;
}

int main()
{
  array<string, 6> people = {"Mel Gibson", "John Wayne", "Charles Chaplin",
                             "Clint Eastwood", "Jack Nicholson",  "George Clooney"};
  parallel_for_each(people.begin(), people.end(), [](string& person)
  {
    size_t space(person.find(' '));
    string first(person.substr(0, space));
    string second(person.substr(space+1, person.length()-space-1));
    person = second +' ' + first;
  });
  for_each(people.begin(), people.end(), [](string& person)
  {cout << person << endl; });
  string name("Eastwood");
  size_t index(findIndex(people, name));
  if(index == -1)
    cout << name << " not found." << endl;
  else
    cout << name << " found at index position " << index << '.' << endl;
}
