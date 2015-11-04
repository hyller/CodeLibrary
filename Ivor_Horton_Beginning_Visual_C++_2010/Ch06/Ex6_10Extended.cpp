// Ex6_10Extended.cpp
// A program to implement a calculator accepting parentheses

#include <iostream>                   // For stream input/output
#include <cstdlib>                    // For the exit() function
#include <cctype>                     // For the isdigit() function
#include <cstring>                    // For the strcpy() function
using std::cin;
using std::cout;
using std::endl;

void eatspaces(char* str);            // Function to eliminate blanks
double expr(char* str);               // Function evaluating an expression
double term(char* str, int& index);   // Function analyzing a term
double number(char* str, int& index); // Function to recognize a number
char* extract(char* str, int& index); // Function to extract a substring
const int MAX(80);                    // Maximum expression length, 
                                      // including '\0'
int main()
{
   char buffer[MAX] = {0};    // Input area for expression to be evaluated

   cout << endl
        << "Welcome to your friendly calculator."
        << endl
        << "Enter an expression, or an empty line to quit."
        << endl;

   for(;;)
   {
      cin.getline(buffer, sizeof buffer);   // Read an input line
      eatspaces(buffer);                    // Remove blanks from input

      if(!buffer[0])                        // Empty line ends calculator
         return 0;

      cout << "\t= " << expr(buffer)        // Output value of expression
           << endl << endl;
   }
}


// Function to eliminate spaces from a string
void eatspaces(char* str)
{
   int i(0);                              // 'Copy to' index to string
   int j(0);                              // 'Copy from' index to string

   while((*(str + i) = *(str + j++)) != '\0')  // Loop while character
                                               // copied is not \0
      if(*(str + i) != ' ')                    // Increment i as long as
         i++;                                  // character is not a space
   return;
}

// Function to evaluate an arithmetic expression
double expr(char* str)
{
  double value(0.0);                   // Store result here
  int index(0);                        // Keeps track of current character position

  value = term(str, index);            // Get first term

  for(;;)                              // Indefinite loop, all exits inside
  {
    switch(*(str + index++))           // Choose action based on current character
    {
      case '\0':                       // We're at the end of the string
         return value;                 // so return what we have got

      case '+':                        // + found so add in the
         value += term(str, index);    // next term
         break;

      case '-':                        // - found so subtract
         value -= term(str, index);    // the next term
         break;

      default:                         // If we reach here the string
         cout << endl                  // is junk
              << "Arrrgh!*#!! There's an error"
              << endl;
         exit(1);
    }
  }
}

// Function to get the value of a term
double term(char* str, int& index)
{
  double value(0.0);                   // Somewhere to accumulate 
                                       // the result

  value = number(str, index);          // Get the first number in the term

  // Loop as long as we have a good operator
  while(true)
  {

    if(*(str + index) == '*')          // If it's multiply,
      value *= number(str, ++index);   // multiply by next number

    else if(*(str + index) == '/')     // If it's divide,
      value /= number(str, ++index);   // divide by next number
    else
      break;
  }
  return value;                        // We've finished, so return what 
                                       // we've got
}

// Function to recognize a number in a string
double number(char* str, int& index)
{
  double value(0.0);                   // Store the resulting value

  if(*(str + index) == '(')            // Start of parentheses
  {
    char* psubstr(nullptr);            // Pointer for substring
    psubstr = extract(str, ++index);   // Extract substring in brackets
    value = expr(psubstr);             // Get the value of the substring
    delete[]psubstr;                   // Clean up the free store
    return value;                      // Return substring value
  }

  // There must be at least one digit...
  if(!isdigit(*(str + index)))
  { // There's no digits so input is junk...
    cout << endl                  
         << "Arrrgh!*#!! There's an error"
         << endl;
    exit(1);
  }

  while(isdigit(*(str + index)))       // Loop accumulating leading digits
    value = 10*value + (*(str + index++) - '0');

                                       // Not a digit when we get to here
  if(*(str + index) != '.')            // so check for decimal point
    return value;                      // and if not, return value

  double factor(1.0);                  // Factor for decimal places
  while(isdigit(*(str + (++index))))   // Loop as long as we have digits
  {
    factor *= 0.1;                     // Decrease factor by factor of 10
    value = value + (*(str + index) - '0')*factor;   // Add decimal place
  }

  return value;                        // On loop exit we are done
}

// Function to extract a substring between parentheses 
// (requires cstring)
char* extract(char* str, int& index)
{
  char buffer[MAX];                   // Temporary space for substring
  char* pstr(nullptr);                // Pointer to new string for return
  int numL(0);                        // Count of left parentheses found
  int bufindex(index);                // Save starting value for index

  do
  {
    buffer[index - bufindex] = *(str + index);
    switch(buffer[index - bufindex])
    {
      case ')':
        if(0 == numL)
        {
          size_t size = index - bufindex;
          buffer[index - bufindex] = '\0';  // Replace ')' with '\0' 
          ++index;
          pstr = new char[index - bufindex];
          if(!pstr)
          {
            cout << "Memory allocation failed,"
                 << " program terminated.";
            exit(1);
          }
          strcpy_s(pstr, index-bufindex, buffer); // Copy substring to new memory
          return pstr;                 // Return substring in new memory
        }
        else
          numL--;                      // Reduce count of '(' to be matched
          break;

      case '(':
        numL++;                        // Increase count of '(' to be 
                                   // matched
        break;
      }
  } while(*(str + index++) != '\0'); // Loop - don't overrun end of string

  cout << "Ran off the end of the expression, must be bad input."
       << endl;
  exit(1);
}
