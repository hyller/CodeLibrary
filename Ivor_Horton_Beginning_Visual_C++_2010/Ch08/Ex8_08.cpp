// Ex8_08.cpp
// Minimizing copy operations
#include <iostream>
#include <cstring>
using std::cout;
using std::endl;

class CMessage
{
  private:
    char* pmessage;                    // Pointer to object text string

  public:
    // Function to display a message
    void ShowIt() const
    {
      cout << endl << pmessage;
    }

    // Overloaded addition operator
    CMessage operator+(const CMessage& aMess) const
    {
      cout << "Add operator function called." << endl;
      size_t len = strlen(pmessage) + strlen(aMess.pmessage) + 1;
      CMessage message;
      message.pmessage = new char[len];
      strcpy_s(message.pmessage, len, pmessage);
      strcat_s(message.pmessage, len, aMess.pmessage);
      return message;
      
    }
  
    // Overloaded assignment operator for CMessage objects
    CMessage& operator=(const CMessage& aMess)
    {
      cout << "Assignment operator function called." << endl;
      if(this == &aMess)               // Check addresses, if equal
        return *this;                  // return the 1st operand

      delete[] pmessage;              // Release memory for 1st operand
      pmessage = new char[strlen(aMess.pmessage) + 1];

      // Copy 2nd operand string to 1st
      strcpy_s(this->pmessage, strlen(aMess.pmessage)+1, aMess.pmessage);

      // Return a reference to 1st operand
      return *this;
    }

    // Overloaded assignment operator for CMessage objects
    CMessage& operator=(CMessage&& aMess)
    {
      cout << "Move assignment operator function called." << endl;
      delete[] pmessage;            // Release memory for left operand
      pmessage = aMess.pmessage;    // Steal string from rhs object
      aMess.pmessage = 0;           // Null rhs pointer
      return *this;                 // Return a reference to 1st operand
    }

    // Constructor definition
    CMessage(const char* text = "Default message")
    {
      cout << "Constructor called." << endl;
      pmessage = new char[strlen(text) + 1];         // Allocate space for text
      strcpy_s(pmessage, strlen(text)+1, text);      // Copy text to new memory
    }

    // Copy constructor definition
    CMessage(const CMessage& aMess)
    {
      cout << "Copy constructor called." << endl;
      size_t len = strlen(aMess.pmessage)+1;
      pmessage = new char[len];
      strcpy_s(pmessage, len, aMess.pmessage);
    }

    // Move copy constructor definition
    CMessage(CMessage&& aMess)
    {
      cout << "Move copy constructor called." << endl;
      pmessage = aMess.pmessage;
      aMess.pmessage = 0;
    }

    // Destructor to free memory allocated by new
    ~CMessage()
    {
      cout << "Destructor called."     // Just to track what happens
           << endl;
      delete[] pmessage;               // Free memory assigned to pointer
    }
};

int main()
{
  CMessage motto1("The devil takes care of his own. ");
  CMessage motto2("If you sup with the devil use a long spoon.\n");
  CMessage motto3;

  cout << " Executing: motto3 = motto1 + motto2 " << endl;
  motto3 = motto1 + motto2;                       // Use new addition operator
  cout << " Done!! " << endl << endl;

  cout << " Executing: motto3 = motto3 + motto1 + motto2 " << endl;
  motto3 = motto3 + motto1 + motto2;
  cout << " Done!! " << endl << endl;
  cout << "motto3 contains - ";
   motto3.ShowIt();
  cout << endl;
  return 0;
}
