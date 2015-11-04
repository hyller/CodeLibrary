// Ex10_04.cpp
// Using a double-ended queue

#include <iostream>
#include <deque>
#include <algorithm>
#include <numeric>

using std::cin;
using std::cout;
using std::endl;
using std::deque;
using std::sort;
using std::accumulate;

int main()
{
  deque<int> data;
  deque<int>::iterator iter;             // Stores an iterator
  deque<int>::reverse_iterator riter;    // Stores a reverse iteraotr
 
  // Read the data 
  cout << "Enter a series of non-zero integers separated by spaces."
       << " Enter 0 to end." << endl;
  int value(0);
  while(cin >> value, value != 0)
    data.push_front(value);

  // Output the data using an iterator
  cout << endl << "The values you entered are:" << endl;
  for(iter = data.begin() ; iter != data.end() ; iter++)
    cout << *iter << "  ";
  cout << endl;

  // Output the data using a reverse iterator
  cout << endl << "In reverse order the values you entered are:" << endl;
  for(riter = data.rbegin() ; riter != data.rend() ; riter++)
    cout << *riter << "  ";

  // Sort the data in descending sequence
  cout << endl;
  cout << endl << "In descending sequence the values you entered are:" << endl;
  sort(data.rbegin(), data.rend());
  for(iter = data.begin() ; iter != data.end() ; iter++)
    cout << *iter << "  ";
  cout << endl;

  // Calculate the sum of the elements
  cout << endl << "The sum of the elements in the queue is: " 
       << accumulate(data.begin(), data.end(), 0)  << endl;

  return 0;
}
