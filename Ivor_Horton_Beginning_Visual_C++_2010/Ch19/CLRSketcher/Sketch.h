// Sketch.h
// Defines a sketch

#pragma once
#include <cliext/list>
#include "Elements.h"

using namespace System;
using namespace cliext;
using namespace System::Runtime::Serialization;

namespace CLRSketcher 
{
  [Serializable]
  public ref class Sketch
  {
  private:
    [NonSerialized]
    list<Element^>^ elements;
    array<Element^>^ elementArray;

  public:
    Sketch() : elementArray(nullptr)
      , saved(true)
    {
    elements = gcnew list<Element^>();
    }

        [OnSerializing]
    void ListToArray(StreamingContext context)
    {
      elementArray = elements->to_array();
    }

    [OnDeserialized]
    void ArrayToList(StreamingContext context)
    {
      elements = gcnew list<Element^>(elementArray);
      elementArray = nullptr;
    }

    // Add an element to the sketch
    Sketch^ operator+=(Element^ element)
    {
      elements->push_back(element);
      return this;
    }

    // Remove an element from the sketch
    Sketch^ operator-=(Element^ element)
    {
      elements->remove(element);
      return this;
    }

    void Draw(Graphics^ g)
    {
      for each(Element^ element in elements)
        element->Draw(g);
    }

    // Find element under point
    Element^ HitElement(Point p)
    {
      for (auto riter = elements->rbegin(); riter != elements->rend() ; ++riter)
      {
        if((*riter)->Hit(p))
          return *riter;
      }
      return nullptr;
    }

    // Add element to the front of the list
    void push_front(Element^ element)
    {
      elements->push_front(element);
    }
    bool saved;
  };
}
