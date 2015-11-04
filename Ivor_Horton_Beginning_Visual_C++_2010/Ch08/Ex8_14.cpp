// Ex8_14.cpp
// Extracting words from text
#include <iostream>
#include <iomanip>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::ios;
using std::setiosflags;
using std::resetiosflags;
using std::setw;
using std::string;

// Sort an array of string objects
string* sort(string* strings, size_t count)
{
  bool swapped(false);
  while(true)
  {
    for(size_t i = 0 ; i < count-1 ; i++)
    {
      if(strings[i] > strings[i+1])
      {
        swapped = true;
        strings[i].swap(strings[i+1]);
      }
    }
    if(!swapped)
      break;
    swapped = false;
  }
  return strings;
}

int main()
{
  const size_t maxwords(100);
  string words[maxwords];
  string text;
  string separators(" \".,:;!?()\n");
  size_t nwords(0);
  size_t maxwidth(0);

  cout << "Enter some text on as many lines as you wish."
    << endl << "Terminate the input with an asterisk:" << endl;

  getline(cin, text, '*');

  size_t start(0), end(0), offset(0);   // Record start & end of word & offset
  while(true)
  {
    // Find first character of a word
    start = text.find_first_not_of(separators, offset);  // Find non-separator
    if(string::npos == start)           // If we did not find it, we are done
      break;
    offset = start + 1;                 // Move past character found


    // Find first separator past end of current word
    end = text.find_first_of(separators,offset);         // Find separator
    if(string::npos == end)             // If it's the end of the string
    {                                   // current word is last in string
      offset = end;                     // We use offset to end loop later
      end = text.length();              // Set end as 1 past last character
    }
    else
      offset = end + 1;                 // Move past character found

    words[nwords] = text.substr(start, end-start);       // Extract the word

    // Keep track of longest word
    if(maxwidth < words[nwords].length())
      maxwidth = words[nwords].length();

    if(string::npos == offset)          // If we reached the end of the string
      break;                            // We are done

    if(++nwords == maxwords)            // Check for array full
    {
      cout << endl << "Maximum number of words reached."
           << endl << "Processing what we have." << endl;
      break;
    }
  }

  sort(words, nwords);

  cout << endl
       << "In ascending sequence, the words in the text are:"
       << endl;

  size_t count(0);                               // Count of duplicate words
  // Output words and number of occurrences
  for(size_t i = 0 ; i<nwords ; i++)
  {
    if(0 == count)
      count = 1;
    if(i < nwords-2 && words[i] == words[i+1])
    {
      ++count;
      continue;
    }
    cout << setiosflags(ios::left)               // Output word left-justified
         << setw(maxwidth+2) << words[i];
    cout << resetiosflags(ios::right)            // and word count right-justified
         << setw(5) << count << endl;
    count = 0;
  }
  cout << endl;
  return 0;
}
