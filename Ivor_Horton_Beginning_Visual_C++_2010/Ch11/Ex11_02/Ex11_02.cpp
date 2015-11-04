// Ex11_02.cpp : Extending the test operation
#include <iostream>
#include "Name.h"
using namespace std;

// Function to initialize an array of random names
void init(Name* names, int count)
{
  char* firstnames[] = { "Charles", "Mary", "Arthur", "Emily", "John"};
  int firstsize = sizeof (firstnames)/sizeof(firstnames[0]);
  char* secondnames[] = { "Dickens", "Shelley", "Miller", "Bronte", "Steinbeck"};
  int secondsize = sizeof (secondnames)/sizeof(secondnames[0]);
  char* first = firstnames[0];
  char* second = secondnames[0];

  for(int i = 0 ; i<count ; i++)
  {
    if(i%2)
      first = firstnames[i%firstsize];
    else
      second = secondnames[i%secondsize];

    names[i] = Name(first, second);
  }
}

int main(int argc, char* argv[])
{
  Name myName("Ivor", "Horton");                 // Try a single object

  // Retrieve and store the name in a local char array  
  char theName[12];
  cout << "\nThe name is " << myName.getName(theName);

  // Store the name in an array in the free store
  char* pName = new char[myName.getNameLength()+1]; 
  cout << "\nThe name is " << myName.getName(pName);

  const int arraysize = 10;
  Name names[arraysize];                          // Try an array

  // Initialize names
  init(names, arraysize);

  // Try out comparisons
  char* phrase = nullptr;                         // Stores a comparison phrase
  char* iName = nullptr;                          // Stores a complete name  
  char* jName = nullptr;                          // Stores a complete name  

  for(int i = 0; i < arraysize ; i++)             // Compare each element
  {
    iName = new char[names[i].getNameLength()+1]; // Array to hold first name
    for(int j = i+1 ; j<arraysize ; j++)          // with all the others
    {
      if(names[i] < names[j])
        phrase = " less than ";
      else if(names[i] > names[j])
        phrase = " greater than ";
      else if(names[i] == names[j])     // Superfluous - but it calls operator==() 
        phrase = " equal to ";

      jName = new char[names[j].getNameLength()+1]; // Array to hold second name
      cout << endl << names[i].getName(iName) << " is" << phrase 
           << names[j].getName(jName);
    }
  }

  cout << endl;
  return 0;
}
