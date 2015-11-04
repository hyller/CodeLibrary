// Ex2_13.cpp : main project file.
// Defining and using a C++/CLI enumeration.

#include "stdafx.h"

using namespace System;

// Define the enumeration at global scope
enum class Suit{Clubs, Diamonds, Hearts, Spades};

int main(array<System::String ^> ^args)
{
    Suit suit = Suit::Clubs;
    int value = safe_cast<int>(suit);
    Console::WriteLine(L"Suit is {0} and the value is {1} ", suit, value);
    suit = Suit::Diamonds;
    value = safe_cast<int>(suit);
    Console::WriteLine(L"Suit is {0} and the value is {1} ", suit, value);
    suit = Suit::Hearts;
    value = safe_cast<int>(suit);
    Console::WriteLine(L"Suit is {0} and the value is {1} ", suit, value);
    suit = Suit::Spades;
    value = safe_cast<int>(suit);
    Console::WriteLine(L"Suit is {0} and the value is {1} ", suit, value);
    return 0;
}
