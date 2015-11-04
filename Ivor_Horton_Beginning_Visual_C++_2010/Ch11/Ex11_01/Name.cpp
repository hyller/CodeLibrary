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
Name::Name(const char* pFirst, const char* pSecond):
                                    pFirstname(pFirst), pSurname(pSecond)
{
  // Verify that arguments are not null
  assert(pFirst);
  assert(pSecond);

#ifdef CONSTRUCTOR_TRACE
  // Trace constructor calls
  cout << "\nName constructor called.";
#endif
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
  pName[strlen(pName)] = ' ';                         // Append a space

  // Append second name and return total
  return strcpy(pName+strlen(pName)+1, pSurname);  
} 

// Returns the total length of a name
size_t Name::getNameLength() const
{
#ifdef FUNCTION_TRACE
  // Trace function calls
  cout << '\n' << __FUNCTION__ << " called.";
#endif
  return strlen(pFirstname)+strlen(pSurname);
}

