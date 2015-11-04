// Sketch.h
// Defines a sketch

#pragma once
#include <cliext/list>
#include "Elements.h"

using namespace System;
using namespace cliext;

namespace CLRSketcher 
{
 public ref class Sketch
  {
  private:
    list<Element^>^ elements;

  public:
    Sketch()
    {
    elements = gcnew list<Element^>();
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
 };
}
