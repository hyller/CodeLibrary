// Ex7_16.cpp : main project file.
// Using scalar properties

#include "stdafx.h"

using namespace System;

// Class defining a person's height
value class Height
{
private:
  // Records the height in feet and inches
  int feet;
  int inches;

  literal int inchesPerFoot = 12;
  literal double inchesToMeters = 2.54/100;

public:
  // Create a height from inches value
  Height(int ins)
  {
    feet = ins / inchesPerFoot;
    inches = ins % inchesPerFoot;
  }

  // Create a height from feet and inches
  Height(int ft, int ins) : feet(ft), inches(ins){}

  // The height in meters
  property double meters                         // Scalar property
  {
    // Returns the property value
    double get()
    {
      return inchesToMeters*(feet*inchesPerFoot+inches);
    }

    // You would define the set() function for the property here...
  }

  // Create a string representation of the object
  virtual  String^ ToString() override
  {
    return feet + L" feet "+ inches + L" inches";
  }
};

// Class defining a person's weight
value class Weight
{
private:
  int lbs;
  int oz;

  literal int ouncesPerPound = 16;
  literal double lbsToKg = 1.0/2.2;

public:
  Weight(int pounds, int ounces)
  {
    lbs = pounds;
    oz = ounces;
  }

  property int pounds                            // Scalar property
  {
    int get() { return lbs;  }
    void set(int value) {  lbs = value;  }
  }

  property int ounces                            // Scalar property
  {
    int get() { return oz;  }
    void set(int value) {  oz = value;  }
  }

  property double kilograms                      // Scalar property
  {
    double get() { return lbsToKg*(lbs + oz/ouncesPerPound);  }
  }

  virtual String^ ToString() override
  { return lbs + L" pounds " + oz + L" ounces"; }
};

// Class defining a person
ref class Person
{
private:
  Height ht;
  Weight wt;

public:
  property String^ Name;                         // Trivial scalar property
  Person(String^ name, Height h, Weight w) : ht(h), wt(w)
  {
    Name = name;
  }

  property Height height
  {
    Height get(){ return ht;  }
  }

  property Weight weight
  {
    Weight get(){ return wt;  }
  }
};

int main(array<System::String ^> ^args)
{
  Weight hisWeight(185, 7);
  Height hisHeight(6, 3);
  Person^ him(gcnew Person(L"Fred", hisHeight, hisWeight));

  Weight herWeight(Weight(105, 3));
  Height herHeight(Height(5, 2));
  Person^ her(gcnew Person(L"Freda", herHeight, herWeight));

  Console::WriteLine(L"She is {0}", her->Name);
  Console::WriteLine(L"Her weight is {0:F2} kilograms.",
                                                    her->weight.kilograms);
  Console::WriteLine(L"Her height is {0} which is {1:F2} meters.",
                                      her->height,her->height.meters);

  Console::WriteLine(L"He is {0}", him->Name);
  Console::WriteLine(L"His weight is {0}.", him->weight);
  Console::WriteLine(L"His height is {0} which is {1:F2} meters.",
                                       him->height,him->height.meters);
  return 0;
}
