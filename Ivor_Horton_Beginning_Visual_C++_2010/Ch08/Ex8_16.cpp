// Ex8_16.cpp : main project file.
// Defining and using overloaded operator

#include "stdafx.h"
using namespace System;

ref class Length
{
private:
  int feet;
  int inches;

public:
  static initonly int inchesPerFoot = 12;

  // Constructor
  Length(int ft, int ins) : feet(ft), inches(ins){ }

  // A length as a string
  virtual String^ ToString() override
  {
    return feet.ToString() + (1 == feet ? L" foot " : L" feet ") +
           inches + (1 == inches ? L" inch" : L" inches");  
  }

  // Overloaded addition operator
  Length^ operator+(Length^ len)
  {
    int inchTotal = inches+len->inches+inchesPerFoot*(feet+len->feet);
    return gcnew Length(inchTotal/inchesPerFoot, inchTotal%inchesPerFoot);
  }

  // Overloaded divide operator - right operand type double
  static Length^ operator/(Length^ len, double x)
  {
    int ins = safe_cast<int>((len->feet*inchesPerFoot + len->inches)/x);
    return gcnew Length(ins/inchesPerFoot, ins%inchesPerFoot);
  }

  // Overloaded divide operator - both operands type Length
  static int operator/(Length^ len1, Length^ len2)
  {
    return (len1->feet*inchesPerFoot + len1->inches)/
                                      (len2->feet*inchesPerFoot + len2->inches);
  }

  // Overloaded remainder operator
  static Length^ operator%(Length^ len1, Length^ len2)
  {
    int ins = (len1->feet*inchesPerFoot + len1->inches)%
                                       (len2->feet*inchesPerFoot + len2->inches);
    return gcnew Length(ins/inchesPerFoot, ins%inchesPerFoot);
  }

  static Length^ operator*(double x, Length^ len); // Multiply - L operand double
  static Length^ operator*(Length^ len, double x); // Multiply - R operand double

  // Pre- and postfix increment operator
  static Length^ operator++(Length^ len)
  {
    Length^ temp = gcnew Length(len->feet, len->inches);
    ++temp->inches;
    temp->feet += temp->inches/temp->inchesPerFoot;
    temp->inches %= temp->inchesPerFoot;
    return temp;
  }
};

// Multiply operator implementation - left operand double
Length^ Length::operator*(double x, Length^ len)
{
  int ins = safe_cast<int>(x*len->inches +x*len->feet*inchesPerFoot);
  return gcnew Length(ins/inchesPerFoot, ins%inchesPerFoot);
}

// Multiply operator implementation - right operand double
Length^ Length::operator*(Length^ len, double x)
{ return operator*(x, len);  }

int main(array<System::String ^> ^args)
{
  Length^ len1 = gcnew Length(2,6);              // 2 feet 6 inches
  Length^ len2 = gcnew Length(3,5);              // 3 feet 5 inches
  Length^ len3 = gcnew Length(14,6);             // 14 feet 6 inches

  // Use +, * and / operators
  Length^ total = 12*(len1+len2+len3) + (len3/gcnew Length(1,7))*len2;
  Console::WriteLine(total);

  // Use remainder operator
  Console::WriteLine(
              L"{0} can be cut into {1} pieces {2} long with {3} left over.",
                                               len3, len3/len1, len1, len3%len1);
  Length^ len4 = gcnew Length(1, 11);            // 1 foot 11 inches

  // Use pre- and postfix increment operator
  Console::WriteLine(len4++);                    // Use postfix increment operator
  Console::WriteLine(++len4);                    // Use prefix increment operator
  Console::WriteLine(len4);                      // Final value of len4
  return 0;
}
