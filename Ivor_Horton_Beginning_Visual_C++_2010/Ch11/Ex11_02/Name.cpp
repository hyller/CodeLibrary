// Name.cpp – Implementation of the Name class
#include "Name.h"                                // Name class definitions
#include "DebugStuff.h"                          // Debugging code control
#include <cstring>                               // For C-style string functions
#include <cassert>                               // For assertions
#include <iostream>
using namespace std;

// Default constructor
Name::Name()
{
#ifdef CONSTRUCTOR_TRACE
  // Trace constructor calls
  cerr << "\nDefault Name constructor called.";
#endif
  pFirstname = pSurname = "\0";
}

// Constructor
Name::Name(const char* pFirst, const char* pSecond)
{
  // Verify that arguments are not null
  assert(pFirst);
  assert(pSecond);

#ifdef CONSTRUCTOR_TRACE
  // Trace constructor calls
  cout << "\nName constructor called.";
#endif
  pFirstname = new char[strlen(pFirst)+1];
  strcpy(pFirstname, pFirst);
  pSurname = new char[strlen(pSecond)+1];
  strcpy(pSurname, pSecond);
}

// Return a complete name as a string containing first name, space, surname
// The argument must be the address of a char array sufficient to hold the name
char* Name::getName(char* pName) const
{
  assert(pName);                                 // Verify non-null argument

#ifdef FUNCTION_TRACE
  // Trace function calls
  cout << '\n' << __FUNCTION__ << " called.";
#endif

  strcpy(pName, pFirstname);                          // copy first name
  strcat(pName, " ");                                 // Append a space

  // Append second name and return total
  return strcat(pName, pSurname);      // Append second name and return total
} 

 // Returns the total length of a name
size_t Name::getNameLength() const
{
#ifdef FUNCTION_TRACE
  // Trace function calls
  cout << '\n' << __FUNCTION__ << " called.";
#endif
  return strlen(pFirstname)+strlen(pSurname)+1;
}

// Less than operator
bool Name::operator<(const Name& name) const
{
  int result = strcmp(pSurname, name.pSurname);
  if(result < 0)
    return true;
  if(result == 0 && strcmp(pFirstname, name.pFirstname) < 0)
    return true;
  else
    return false;
}

// Greater than operator
bool Name::operator>(const Name& name) const
{
  return name > *this;
}

// Equal to operator
bool Name::operator==(const Name& name) const
{
  if(strcmp(pSurname, name.pSurname) == 0 &&
                                         strcmp(pFirstname, name.pFirstname) == 0)
    return true;
  else
    return false;
}
