// Ex8_02.cpp
// Using a destructor to free memory
#include <iostream>          // For stream I/O
#include <cstring>           // For strlen() and strcpy()
using std::cout;
using std::endl;

// Put the CMessage class definition here (Listing 08_01)

//Listing 08_01
class CMessage
{
  private:
    char* pmessage;                   // Pointer to object text string

  public:

    // Function to display a message
    void ShowIt() const
    {
      cout << endl << pmessage;
    }

    // Constructor definition
    CMessage(const char* text = "Default message")
    {
      pmessage = new char[strlen(text) + 1];        // Allocate space for text
      strcpy_s(pmessage, strlen(text) + 1, text);   // Copy text to new memory
    }

    ~CMessage();                               // Destructor prototype
};

// Destructor to free memory allocated by new
CMessage::~CMessage()
{
  cout << "Destructor called."         // Just to track what happens
       << endl;
  delete[] pmessage;                   // Free memory assigned to pointer
}

int main()
{
  // Declare object
  CMessage motto("A miss is as good as a mile.");

  // Dynamic object
  CMessage* pM(new CMessage("A cat can look at a queen."));

  motto.ShowIt();            // Display 1st message
  pM->ShowIt();              // Display 2nd message
  cout << endl;

  // delete pM;              // Manually delete object created with new
   return 0;
}
