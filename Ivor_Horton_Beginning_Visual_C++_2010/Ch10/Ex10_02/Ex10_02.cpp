// Ex10_02.cpp
// Storing objects in a vector

#include <iostream>
#include <vector>
// #include <algorithm>                // Uncomment to sort
#include "Person.h" 

using std::cin;
using std::cout;
using std::endl;
using std::vector;
// using std::sort;                    // Uncomment to sort

int main()
{
  vector<Person> people;               // Vector of Person objects
  const size_t maxlength(50);
  char firstname[maxlength];
  char secondname[maxlength];
  while(true)
  {
    cout << "Enter a first name or press Enter to end: ";
    cin.getline(firstname, maxlength, '\n'); 
    if(strlen(firstname) == 0)
      break;
    cout << "Enter the second name: ";
    cin.getline(secondname, maxlength, '\n'); 
    people.push_back(Person(firstname, secondname));
  }

//  sort(people.begin(), people.end());     // Uncomment to sort

  // Output the contents of the vector
  cout << endl;
  auto iter(people.begin());  
  while(iter != people.end())
    iter++->showPerson();

  return 0;
}
