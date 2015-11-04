// Ex10_06.cpp
// Using the remove_if() function for a list

#include <iostream>
#include <list>
#include "function_object.h"
#include <functional>

using std::cin;
using std::cout;
using std::endl;
using std::list;
using std::greater;

// Template function to list the contents of a list
template <class T>
void listlist(list<T>& data)
{
  for(list<T>::iterator iter = data.begin() ; iter != data.end() ; iter++)
    cout << *iter << "  ";
  cout << endl;
}

// Template function to read data from cin and store it in a list
template<class T>
void loadlist(list<T>& data)
{
  T value = T();
  while(cin >> value , value != T())  //Read non-zero values
    data.push_back(value);
}

int main()
{
  // Process integers
  list<int> numbers;
  cout << "Enter non-zero integers separated by spaces. Enter 0 to end." 
       << endl;
  loadlist(numbers);
  cout << "The list contains:" << endl;
  listlist(numbers);
  numbers.remove_if(is_negative<int>()); 
  cout << "After applying the remove_if() function the list contains:" 
       << endl;
  listlist(numbers);

  // Process floating-point values
  list<double> values;
  cout << endl 
       << "Enter non-zero values separated by spaces. Enter 0 to end." 
       << endl;
  loadlist(values);
  cout << "The list contains:" << endl;
  listlist(values);
  values.remove_if(is_negative<double>());        
  cout << "After applying the remove_if() function the list contains:" << endl;
  listlist(values);

  // Another list to use in merge
  list<double> morevalues;
  cout << endl 
       << "Enter non-zero values separated by spaces. Enter 0 to end." 
       << endl;
  loadlist(morevalues);
  cout << "The list contains:" << endl;
  listlist(morevalues);
  values.remove_if(is_negative<double>());        
  cout << "After applying the remove_if() function the list contains:" << endl;
  listlist(morevalues);

  // Merge the last two lists
  values.sort(greater<double>());
  morevalues.sort(greater<double>());
  values.merge(morevalues, greater<double>());
  listlist(values);

  return 0;
}
