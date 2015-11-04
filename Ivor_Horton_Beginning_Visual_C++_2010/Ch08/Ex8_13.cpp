// Ex8_13.cpp
// Comparing and sorting words
#include <iostream>
#include <iomanip>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::ios;
using std::setiosflags;
using std::setw;
using std::string;

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
  const size_t maxstrings(100);
  string strings[maxstrings];
  size_t nstrings(0);
  size_t maxwidth(0);

  // Read up to 100 words into the strings array
  while(nstrings < maxstrings)
  {
    cout << "Enter a word or press Enter to end: ";
    getline(cin, strings[nstrings]);
    if(maxwidth < strings[nstrings].length())
      maxwidth = strings[nstrings].length();
    if(strings[nstrings].empty())
      break;
    ++nstrings;
  }

  // Sort the input in ascending sequence
  sort(strings,nstrings);
  cout << endl
       << "In ascending sequence, the words you entered are:"
       << endl
       << setiosflags(ios::left);           // Left-justify the output
  for(size_t i = 0 ; i < nstrings ; i++)
  {
    if(i % 5 == 0)
      cout << endl;
    cout << setw(maxwidth+2) << strings[i];
  }
  cout << endl;
  return 0;
}
