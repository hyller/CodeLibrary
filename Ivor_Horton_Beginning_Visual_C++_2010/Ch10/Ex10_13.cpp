// Ex10_13.cpp
// Using stream and inserter iterators
#include <iostream>
#include <numeric>
#include <vector>
#include <iterator>
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::istream_iterator;
using std::ostream_iterator;
using std::back_inserter;
using std::accumulate;


int main()
{
  vector<int> numbers;
  cout << "Enter a series of integers separated by spaces" 
       << " followed by Ctrl+Z or a letter:" << endl;

  istream_iterator<int> input(cin), input_end;
  ostream_iterator<int> out(cout, " ");

  copy(input, input_end, back_inserter<vector<int>>(numbers));

  cout << "You entered the following values:" << endl;
  copy(numbers.begin(), numbers.end(), out);

  cout << endl << "The sum of these values is " 
       << accumulate(numbers.begin(), numbers.end(), 0) << endl;

  return 0;
} 
