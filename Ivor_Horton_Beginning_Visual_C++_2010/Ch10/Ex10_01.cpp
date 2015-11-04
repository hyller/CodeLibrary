// Ex10_01.cpp
// Exploring the size and capacity of a vector

#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

// Template function to display the size and capacity of any vector
template<class T>
void listInfo(vector<T> &v)
{
  cout << "Container capacity: " << v.capacity()
       << " size: " << v.size() << endl;
}

int main()
{
  // Basic vector creation
  vector<double> data;
  listInfo(data);

  cout << endl << "After calling reserve(100):" << endl;
  data.reserve(100);
  listInfo(data);

  // Create a vector with 10 elements and initialize it
  vector<int> numbers(10,-1);
  cout << endl << "The initial values are:";
  for(vector<int>::size_type i = 0; i<numbers.size() ; i++)
    cout << " " << numbers[i];

  // See how adding elements affects capacity increments
  auto oldC = numbers.capacity();   // Old capacity
  auto newC = oldC;          // New capacity after adding element
  cout << endl << endl;
  listInfo(numbers);
  for(int i = 0; i<1000 ; i++)
  {
    numbers.push_back(2*i);
    newC = numbers.capacity();
    if(oldC < newC)
    {
      oldC = newC;
      listInfo(numbers);
    }
  }
  return 0;
}
