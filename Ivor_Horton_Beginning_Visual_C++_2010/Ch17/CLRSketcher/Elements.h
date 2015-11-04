// Elements.h
// Defines element types
#pragma once
#include <cliext/vector>

using namespace System;
using namespace System::Drawing;
using namespace cliext;

namespace CLRSketcher 
{

  public ref class Element abstract
  {
  protected:
    Point position;
    Color color;
    System::Drawing::Rectangle boundRect;
    Pen^ pen;
    Color highlightColor;

  public: 
    property bool highlighted;

    property System::Drawing::Rectangle bound
    {
      System::Drawing::Rectangle get() { return boundRect; }
    }

  public:
    Element() : highlightColor(Color::Magenta) {   highlighted = false;  }
    virtual void Draw(Graphics^ g) abstract;
    bool Hit(Point p) {  return boundRect.Contains(p);  }
    void Move(int dx, int dy)
    {
      position.Offset(dx, dy);
      boundRect.X += dx;
      boundRect.Y += dy;
    }
  };

public ref class Line : Element
{
  protected:
    Point end;

  public:
    // Constructor
    Line(Color color, Point start, Point end)
    {
      pen = gcnew Pen(color);
      this->color = color;
      position = start;
      this->end = end - Size(start);
      boundRect = System::Drawing::Rectangle(Math::Min(position.X, end.X),
                                             Math::Min(position.Y, end.Y),
                    Math::Abs(position.X - end.X), Math::Abs(position.Y - end.Y));

      int penWidth(safe_cast<int>(pen->Width));        // Pen width as an integer
      boundRect.Inflate(penWidth, penWidth);
    }

    // Function to draw a line
    virtual void Draw(Graphics^ g) override
    {
         pen->Color = highlighted ? highlightColor : color;
         g->TranslateTransform(safe_cast<float>(position.X),
                              safe_cast<float>(position.Y));
        g->DrawLine(pen, 0, 0, end.X, end.Y);
        g->ResetTransform();
    }
  };

  public ref class Rectangle : Element
  {
  protected:
    int width;
    int height;

  public:
    Rectangle(Color color, Point p1, Point p2)
    {
      pen = gcnew Pen(color);
      this->color = color;
      position = Point(Math::Min(p1.X, p2.X), Math::Min(p1.Y,p2.Y));
      width = Math::Abs(p1.X - p2.X);
      height = Math::Abs(p1.Y - p2.Y);
      boundRect = System::Drawing::Rectangle(position, Size(width, height));
      int penWidth(safe_cast<int>(pen->Width));        // Pen width as an integer
      boundRect.Inflate(penWidth, penWidth);
   }

    virtual void Draw(Graphics^ g) override
    {
     pen->Color = highlighted ? highlightColor : color;
     g->TranslateTransform(safe_cast<float>(position.X), 
                            safe_cast<float>(position.Y));
      g->DrawRectangle(pen, 0, 0, width, height);
      g->ResetTransform();
    }
  };

  public ref class Circle : Element
  {
  protected:
    int width;
    int height;

  public:
    Circle(Color color, Point center, Point circum)
    {
      pen = gcnew Pen(color);
      this->color = color;
      int radius = safe_cast<int>(Math::Sqrt(
                  (center.X-circum.X)*(center.X-circum.X) +
                                 (center.Y-circum.Y)*(center.Y-circum.Y)));
      position = Point(center.X - radius, center.Y - radius);
      width = height = 2*radius;
      boundRect = System::Drawing::Rectangle(position, Size(width, height));
      int penWidth(safe_cast<int>(pen->Width));        // Pen width as an integer
      boundRect.Inflate(penWidth, penWidth);
   }

    virtual void Draw(Graphics^ g) override
    {
      pen->Color = highlighted ? highlightColor : color;
      g->TranslateTransform(safe_cast<float>(position.X),
                            safe_cast<float>(position.Y));
      g->DrawEllipse(pen, 0, 0, width,height);
      g->ResetTransform();
    }
  };

  public ref class Curve : Element
  {
  private:
    vector<Point>^ points;

  public:
    Curve(Color color, Point p1, Point p2)
    {
      pen = gcnew Pen(color);
      this->color = color;
      points = gcnew vector<Point>();
      position = p1;
      points->push_back(p2 - Size(position));

      // Find the minimum and maximum coordinates
      int minX = p1.X < p2.X ? p1.X : p2.X;
      int minY = p1.Y < p2.Y ? p1.Y : p2.Y;
      int maxX = p1.X > p2.X ? p1.X : p2.X;
      int maxY = p1.Y > p2.Y ? p1.Y : p2.Y;
      int width = maxX - minX;
      int height = maxY - minY;
      boundRect = System::Drawing::Rectangle(minX, minY, width, height);
      int penWidth(safe_cast<int>(pen->Width));        // Pen width as an integer
      boundRect.Inflate(penWidth, penWidth);
    }

    // Add a point to the curve
    void Add(Point p)
    {
      points->push_back(p - Size(position));

      // Modify the bounding rectangle to accommodate the new point
     int penWidth(safe_cast<int>(pen->Width));        // Pen width as an integer
     boundRect.Inflate(-penWidth, -penWidth);         // Reduce the rectangle by the pen width
      if(p.X < boundRect.X)
      {
        boundRect.Width = boundRect.Right - p.X;
        boundRect.X = p.X;
      }
      else if(p.X > boundRect.Right)
        boundRect.Width = p.X - boundRect.Left;

      if(p.Y < boundRect.Y)
      {
        boundRect.Height = boundRect.Bottom - p.Y;
        boundRect.Y = p.Y;
      }
      else if(p.Y > boundRect.Bottom)
        boundRect.Height = p.Y - boundRect.Top;

      boundRect.Inflate(penWidth, penWidth);          // Inflate the rectangle by the pen width
   }

     virtual void Draw(Graphics^ g) override
    {
      pen->Color = highlighted ? highlightColor : color;
      g->TranslateTransform(safe_cast<float>(position.X), 
                            safe_cast<float>(position.Y));
      Point previous(0,0);
      for each(Point p in points)
      {
        g->DrawLine(pen, previous, p);
        previous = p;
      }
      g->ResetTransform();
    }
  };
}
