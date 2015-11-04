// Ex4_06.cpp
// Initializing pointers with strings
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
   char* pstr1("Robert Redford");
   char* pstr2("Hopalong Cassidy");
   char* pstr3("Lassie");
   char* pstr4("Slim Pickens");
   char* pstr5 ("Boris Karloff");
   char* pstr6("Oliver Hardy");
   char* pstr("Your lucky star is ");
   
   int dice(0);

   cout << endl
        << "Pick a lucky star!"
        << "Enter a number between 1 and 6: ";
   cin >> dice;

   cout << endl;
   switch(dice)
   {
      case 1: cout << pstr << pstr1;
              break;
      case 2: cout << pstr << pstr2;
              break;
      case 3: cout << pstr << pstr3;
              break;
      case 4: cout << pstr << pstr4;
              break;
      case 5: cout << pstr << pstr5;
              break;
      case 6: cout << pstr << pstr6;
              break;
      
      default: cout << "Sorry, you haven't got a lucky star.";
   }
   
   cout << endl;
   return 0;
}
