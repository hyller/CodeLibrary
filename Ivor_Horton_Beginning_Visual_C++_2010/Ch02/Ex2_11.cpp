// Ex2_11.cpp : main project file.
#include "stdafx.h"

using namespace System;

int main(array<System::String ^> ^args)
{
   int apples, oranges;                   // Declare two integer variables
   int fruit;                             // ...then another one

   apples = 5; oranges = 6;                 // Set initial values
   fruit = apples + oranges;                // Get the total fruit

   Console::WriteLine(L"\nOranges are not the only fruit...");
   Console::Write(L"- and we have ");
   Console::Write(fruit);
   Console::Write(L" fruits in all.\n");
   return 0;
}
