// Ex10_03.cpp
// Storing pointers to objects in a vector

#include <iostream>
#include <vector>
#include "Person.h" 

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main()
{
  vector<Person*> people;               // Vector of Person objects
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
    people.push_back(new Person(firstname, secondname));
  }

  // Output the contents of the vector
  cout << endl;
  auto iter(people.begin());  
  while(iter != people.end())
    (*(iter++))->showPerson();

  // Release memory for the people
  iter = people.begin();
  while(iter != people.end())
    delete *(iter++);

  // Pointers in the vector are now invalid
  // so remove the contents
  people.clear();

  return 0;
}
