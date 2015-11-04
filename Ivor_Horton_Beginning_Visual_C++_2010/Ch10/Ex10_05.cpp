// Ex10_05.cpp
// Working with a list

#include <iostream>
#include <list>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::list;
using std::string;

int main()
{
  list<string> text;
  list<string>::iterator iter;           // Stores an iterator
 
  // Read the data 
  cout << "Enter a few lines of text. Just press Enter to end:"
       << endl;
  string sentence;
  while(getline(cin, sentence, '\n'), !sentence.empty())
    text.push_front(sentence);

  // Output the data using an iterator
  cout << endl << "Here is the text you entered:" << endl;
  for(iter = text.begin() ; iter != text.end() ; iter++)
    cout << *iter << endl;

  // Sort the data in ascending sequence
  cout << endl << "In ascending sequence the sentences you entered are:" << endl;
  text.sort();
  for(iter = text.begin() ; iter != text.end() ; iter++)
    cout << *iter << endl;

  return 0;
}
