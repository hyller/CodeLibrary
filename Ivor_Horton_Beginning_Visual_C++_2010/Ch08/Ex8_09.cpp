// Ex8_09.cpp Creeping inefficiencies
#include <iostream>
#include <cstring>
#include <utility>
using std::cout;
using std::endl;

class CText
{
private:
  char* pText;

public:
    // Function to display text
    void ShowIt() const
    {
      cout << pText << endl;
    }

    // Constructor
    CText(const char* pStr="No text")
    {
      cout << "CText constructor called." << endl;
      size_t len(strlen(pStr)+1);
      pText = new char[len];                // Allocate space for text
      strcpy_s(pText, len, pStr);           // Copy text to new memory
    }

    // Copy constructor definition
    CText(const CText& txt)
    {
      cout << "CText copy constructor called." << endl;
      size_t len(strlen(txt.pText)+1);
      pText = new char[len];
      strcpy_s(pText, len, txt.pText);
    }

    // Move copy constructor definition
    CText(CText&& txt)
    {
      cout << "CText move copy constructor called." << endl;
      pText = txt.pText;
      txt.pText = 0;
    }

    // Destructor to free memory allocated by new
    ~CText()
    {
      cout << "CText destructor called." << endl;    // Just to track what happens
      delete[] pText;                                // Free memory assigned to pointer
    }
  
    // Overloaded assignment operator for CText objects
    CText& operator=(const CText& txt)
    {
      cout << "CText assignment operator function called." << endl;
      if(this == &txt)               // Check addresses, if equal
        return *this;                  // return the 1st operand

      delete[] pText;              // Release memory for 1st operand
      size_t len(strlen(txt.pText)+1);
      pText = new char[len];

      // Copy 2nd operand string to 1st
      strcpy_s(this->pText, len, txt.pText);

      // Return a reference to 1st operand
      return *this;
    }

    // Overloaded assignment operator for CText objects
    CText& operator=(CText&& txt)
    {
      cout << "CText move assignment operator function called." << endl;
      delete[] pText;              // Release memory for 1st operand
      pText = txt.pText;
      txt.pText = 0;

      // Return a reference to 1st operand
      return *this;
    }

    // Overloaded addition operator
    CText operator+(const CText& txt) const
    {
      cout << "CText add operator function called." << endl;
      size_t len(strlen(pText) + strlen(txt.pText) + 1);
      CText aText;
      aText.pText = new char[len];
      strcpy_s(aText.pText, len, pText);
      strcat_s(aText.pText, len, txt.pText);
      return aText;
    }
};

class CMessage
{
  private:
    CText text;                    // Object text string

  public:
    // Function to display a message
    void ShowIt() const
    {
      text.ShowIt();
    }

    // Overloaded addition operator
    CMessage operator+(const CMessage& aMess) const
    {
      cout << "CMessage add operator function called." << endl;
      CMessage message;
      message.text = text + aMess.text;
      return message;
    }
  
    // Copy assignment operator for CMessage objects
    CMessage& operator=(const CMessage& aMess)
    {
      cout << "CMessage copy assignment operator function called." << endl;
      if(this == &aMess)               // Check addresses, if equal
        return *this;                  // return the 1st operand

      text = aMess.text;
      return *this;                    // Return a reference to 1st operand
    }

    // Move assignment operator for CMessage objects
    CMessage& operator=(CMessage&& aMess)
    {
      cout << "CMessage move assignment operator function called." << endl;
//      text = aMess.text;
      text = std::move(aMess.text);
      return *this;                    // Return a reference to 1st operand
    }

    // Constructor definition
    CMessage(const char* str = "Default message")
    {
      cout << "CMessage constructor called." << endl;
      text = CText(str);
    }

    // Copy constructor definition
    CMessage(const CMessage& aMess)
    {
      cout << "CMessage copy constructor called." << endl;
      text = aMess.text;
    }

    // Move constructor definition
    CMessage(CMessage&& aMess)
    {
      cout << "CMessage move constructor called." << endl;
//      text = aMess.text;
      text = std::move(aMess.text);
    }
};

int main()
{
  CMessage motto1("The devil takes care of his own. ");
  CMessage motto2("If you sup with the devil use a long spoon.\n");

  cout << endl << " Executing: CMessage motto3(motto1+motto2); " << endl;
  CMessage motto3(motto1+motto2);
  cout << " Done!! " << endl << endl << "motto3 contains - ";
   motto3.ShowIt();
  CMessage motto4;
  cout << endl << " Executing: motto4 = motto3 + motto2; " << endl;
  motto4 = motto3 + motto2;
  cout << " Done!! " << endl << endl << "motto4 contains - ";
   motto4.ShowIt();
  cout << endl;
  return 0;
}
