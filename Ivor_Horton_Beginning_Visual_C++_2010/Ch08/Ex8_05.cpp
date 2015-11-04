// Ex8_05.cpp
// Overloaded assignment operator working well
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

    //Function to reset a message to *
    void Reset()
    {
      char* temp = pmessage;
      while(*temp)
        *(temp++) = '*';
    }

    // Overloaded assignment operator for CMessage objects
    CMessage& operator=(const CMessage& aMess)
    {
      if(this == &aMess)               // Check addresses, if equal
        return *this;                  // return the 1st operand

      // Release memory for 1st operand
      delete[] pmessage;
      pmessage = new char[strlen(aMess.pmessage) + 1];

      // Copy 2nd operand string to 1st
      strcpy_s(this->pmessage, strlen(aMess.pmessage) + 1, aMess.pmessage);

      // Return a reference to 1st operand
      return *this;
    }

    // Constructor definition
    CMessage(const char* text = "Default message")
    {
      pmessage = new char[strlen(text) + 1];       // Allocate space for text
      strcpy_s(pmessage, strlen(text)+1, text);    // Copy text to new memory
    }

    // Copy constructor definition
    CMessage(const CMessage& aMess)
    {
      size_t len = strlen(aMess.pmessage)+1;
      pmessage = new char[len];
      strcpy_s(pmessage, len, aMess.pmessage);
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
  CMessage motto1("The devil takes care of his own");
  CMessage motto2;

  cout << "motto2 contains - ";
  motto2.ShowIt();
  cout << endl;

  motto2 = motto1;                       // Use new assignment operator

  cout << "motto2 contains - ";
   motto2.ShowIt();
  cout << endl;

  motto1.Reset();                      // Setting motto1 to * doesn't
                                       // affect motto2

  cout << "motto1 now contains - ";
  motto1.ShowIt();
  cout << endl;

  cout << "motto2 still contains - ";
  motto2.ShowIt();
  cout << endl;

  return 0;
}
