// Ex10_10.cpp Using an array storing tuple objects
#include <array>
#include <tuple>
#include <string>
#include <iostream>
#include <iomanip>

using std::get;
using std::cout;
using std::endl;
using std::setw;
using std::string;
const size_t maxRecords(100);
typedef std::tuple<int, string, string, int> Record;
typedef std::array<Record, maxRecords> Records;

// Lists the contents of a Records array
void listRecords(const Records& people)
{
  const size_t ID(0), firstname(1), secondname(2), age(3);
  cout << std::setiosflags(std::ios::left);
  for(auto iter = people.begin() ; iter != people.end() ; ++iter)
  {
    if(*iter == Record()) break;
    cout << setw(6)  << get<ID>(*iter)         << setw(15) << get<firstname>(*iter) 
         << setw(15) << get<secondname>(*iter) << setw(5)  << get<age>(*iter) << endl;
  }
}

int main()
{
  Records personnel = {Record(1001, "Clarke", "Kent", 89), Record(1002, "Mary", "Pickford", 55),
    Record(1003, "Mel", "Smith", 34), Record(1004, "June", "Whitfield", 74)};
  personnel[4] = std::make_tuple(1005, "Charles", "Chapin", 42);
  personnel.at(5) = Record(1006, "Lewis", "Hamilton", 22);

  listRecords(personnel);
  return 0;
}