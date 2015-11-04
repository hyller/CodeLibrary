// Elements.cpp : implementation file
//

#include "stdafx.h"
#include <cmath>
#include <algorithm>
#include "Sketcher.h"
#include "Elements.h"

IMPLEMENT_SERIAL(CElement, CObject, VERSION_NUMBER)
IMPLEMENT_SERIAL(CLine, CElement, VERSION_NUMBER)
IMPLEMENT_SERIAL(CRectangle, CElement, VERSION_NUMBER)
IMPLEMENT_SERIAL(CCircle, CElement, VERSION_NUMBER)
IMPLEMENT_SERIAL(CCurve, CElement, VERSION_NUMBER)
IMPLEMENT_SERIAL(CText, CElement, VERSION_NUMBER)

// CElement

CElement::CElement()
{
}

CElement::~CElement()
{
}

// CElement member functions
// Get the bounding rectangle for an element
CRect CElement::GetBoundRect() const
{
   CRect boundingRect(m_EnclosingRect);           // Object to store bounding rectangle

   // Increase the rectangle by the pen width and return it
   int Offset = m_PenWidth == 0 ? 1 : m_PenWidth; // Width must be at least 1
   boundingRect.InflateRect(Offset, Offset);
   return boundingRect;
}

void CElement::Serialize(CArchive& ar)
{
  CObject::Serialize(ar);              // Call the base class function

  if (ar.IsStoring())
   {
     ar << m_PenWidth                  // the pen width
        << m_Color                     // Store the color,
        << m_EnclosingRect;            // and the enclosing rectangle
  }
  else
  {
     ar >> m_PenWidth                  // the pen width
        >> m_Color                     // the color
        >> m_EnclosingRect;            // and the enclosing rectangle
  }
}


// CLine

// CLine class constructor
CLine::CLine(const CPoint& start, const CPoint& end, COLORREF aColor, int penWidth):
         m_StartPoint(start), m_EndPoint(end)
{
   m_PenWidth = penWidth;              // Set pen width
   m_Color = aColor;                   // Set line color

   // Define the enclosing rectangle
   m_EnclosingRect = CRect(start, end);
   m_EnclosingRect.NormalizeRect();
}

CLine::~CLine()
{
}

// CLine member functions

// Draw a CLine object
void CLine::Draw(CDC* pDC, CElement* pElement)
{
   // Create a pen for this object and
   // initialize it to the object color and line width m_PenWidth
   CPen aPen;
   if(!aPen.CreatePen(PS_SOLID, m_PenWidth, this==pElement ? SELECT_COLOR : m_Color))
   {
      // Pen creation failed. Abort the program
      AfxMessageBox(_T("Pen creation failed drawing a line"), MB_OK);
      AfxAbort();
   }

   CPen* pOldPen = pDC->SelectObject(&aPen);  // Select the pen

   // Now draw the line
   pDC->MoveTo(m_StartPoint);
   pDC->LineTo(m_EndPoint);

   pDC->SelectObject(pOldPen);                  // Restore the old pen
}

// Move a line
void CLine::Move(const CSize& aSize)
{
  m_StartPoint += aSize;               // Move the start point
  m_EndPoint += aSize;                 // and the end point
  m_EnclosingRect += aSize;            // Move the enclosing rectangle
}

void CLine::Serialize(CArchive& ar)
{
  CElement::Serialize(ar);             // Call the base class function

  if (ar.IsStoring())
  {
    ar << m_StartPoint                 // Store the line start point,
       << m_EndPoint;                  // and the end point
  }
  else
  {
    ar >> m_StartPoint                 // Retrieve the line start point,
       >> m_EndPoint;                  // and the end point
  }
}


// CRectangle

// CRectangle class constructor
CRectangle:: CRectangle(const CPoint& start, const CPoint& end, COLORREF aColor, int penWidth)
{
   m_Color = aColor;          // Set rectangle color
   m_PenWidth = penWidth;     // Set pen width

   // Define the enclosing rectangle 
   m_EnclosingRect = CRect(start, end);
   m_EnclosingRect.NormalizeRect();
}

CRectangle::~CRectangle()
{
}

// CRectangle member functions

// Draw a CRectangle object
void CRectangle::Draw(CDC* pDC, CElement* pElement)
{
   // Create a pen for this object and
   // initialize it to the object color and line width of m_PenWidth
   CPen aPen;
   if(!aPen.CreatePen(PS_SOLID, m_PenWidth, this==pElement ? SELECT_COLOR : m_Color))
   {
      // Pen creation failed
      AfxMessageBox(_T("Pen creation failed drawing a rectangle"), MB_OK);
      AfxAbort();
   }

   // Select the pen
   CPen* pOldPen = pDC->SelectObject(&aPen);
   // Select the brush
   CBrush* pOldBrush = (CBrush*)pDC->SelectStockObject(NULL_BRUSH);

   // Now draw the rectangle
   pDC->Rectangle(m_EnclosingRect);

   pDC->SelectObject(pOldBrush);       // Restore the old brush
   pDC->SelectObject(pOldPen);         // Restore the old pen
}

// Move a rectangle
void CRectangle::Move(const CSize& aSize)
{
  m_EnclosingRect+= aSize;             // Move the rectangle
}

void CRectangle::Serialize(CArchive& ar)
{
  CElement::Serialize(ar);             // Call the base class function
}


// CCircle

// Constructor for a circle object
CCircle::CCircle(const CPoint& start, const CPoint& end, COLORREF aColor, int penWidth)
{
   // First calculate the radius
   // We use floating point because that is required by 
   // the library function (in cmath) for calculating a square root.
   long radius = static_cast<long> (sqrt(
                  static_cast<double>((end.x-start.x)*(end.x-start.x)+
                                      (end.y-start.y)*(end.y-start.y))));

   // Now calculate the rectangle enclosing
   // the circle assuming the MM_TEXT mapping mode
   m_EnclosingRect = CRect(start.x-radius, start.y-radius,
                           start.x+radius, start.y+radius);
   m_EnclosingRect.NormalizeRect();    // Normalize-in case it's not MM_TEXT

   m_Color = aColor;                   // Set the color for the circle
   m_PenWidth = penWidth;              // Set pen width to 1
}

CCircle::~CCircle()
{
}

// CCircle member functions

// Draw a circle
void CCircle::Draw(CDC* pDC, CElement* pElement)
{
   // Create a pen for this object and
   // initialize it to the object color and line width of 1 pixel
   CPen aPen;
   if(!aPen.CreatePen(PS_SOLID, m_PenWidth, this==pElement ? SELECT_COLOR : m_Color))
   {
      // Pen creation failed
      AfxMessageBox(_T("Pen creation failed drawing a circle"), MB_OK);
      AfxAbort();
   }

   CPen* pOldPen = pDC->SelectObject(&aPen);  // Select the pen

   // Select a null brush
   CBrush* pOldBrush = (CBrush*)pDC->SelectStockObject(NULL_BRUSH);

   // Now draw the circle
   pDC->Ellipse(m_EnclosingRect);

   pDC->SelectObject(pOldPen);                // Restore the old pen
   pDC->SelectObject(pOldBrush);              // Restore the old brush
} 

// Move a circle
void CCircle::Move(const CSize& aSize)
{
  m_EnclosingRect+= aSize;             // Move rectangle defining the circle
}

void CCircle::Serialize(CArchive& ar)
{
  CElement::Serialize(ar);             // Call the base class function
}


// CCurve

// Constructor for a curve object
CCurve::CCurve(const CPoint& first, const CPoint& second, COLORREF aColor, int penWidth)
{
   // Store the points
   m_Points.push_back(first);
   m_Points. push_back(second);
   m_Color = aColor;
   m_EnclosingRect = CRect(min(first.x, second.x), min(first.y, second.y),
                           max(first.x, second.x), max(first.y, second.y));
   m_PenWidth = penWidth;
}

CCurve::~CCurve()
{
}

// CCurve member functions

// Draw a curve
void CCurve::Draw(CDC* pDC, CElement* pElement)
{
   // Create a pen for this object and
   // initialize it to the object color and line width of m_PenWidth
   CPen aPen;
   if(!aPen.CreatePen(PS_SOLID, m_PenWidth, this==pElement ? SELECT_COLOR : m_Color))
   {
      // Pen creation failed
      AfxMessageBox(_T("Pen creation failed drawing a curve"), MB_OK);
      AfxAbort();
   }

   CPen* pOldPen = pDC->SelectObject(&aPen);  // Select the pen

   // Now draw the curve
   pDC->MoveTo(m_Points[0]);
   for(size_t i = 1 ; i<m_Points.size() ; ++i)
     pDC->LineTo(m_Points[i]);

   pDC->SelectObject(pOldPen);                // Restore the old pen
}

// Add a segment to the curve
void CCurve::AddSegment(const CPoint& point)
{
   m_Points. push_back(point);                // Add the point to the end

   // Modify the enclosing rectangle for the new point
   m_EnclosingRect = CRect(min(point.x, m_EnclosingRect.left),
                           min(point.y, m_EnclosingRect.top),
                           max(point.x, m_EnclosingRect.right),
                           max(point.y, m_EnclosingRect.bottom));
}

// Move a curve
void CCurve::Move(const CSize& aSize)
{
  m_EnclosingRect += aSize;            // Move the rectangle
  // Now move all the points
  std::for_each(m_Points.begin(), m_Points.end(),
                                 [&aSize](CPoint& p){ p += aSize; });
}

void CCurve::Serialize(CArchive& ar)
{
  CElement::Serialize(ar);             // Call the base class function
  // Serialize the vector of points
  if (ar.IsStoring())
  {
    ar << m_Points.size();             // Store the point count
    // Now store the points
    for(size_t i = 0 ; i< m_Points.size() ; ++i)
      ar << m_Points[i];
  }
  else
  {
    size_t nPoints(0);                 // Stores number of points
    ar >> nPoints;                     // Retrieve the number of points
    // Now retrieve the points
    CPoint point;
    for(size_t i = 0 ; i< nPoints ; ++i)
    {
      ar >> point;
      m_Points.push_back(point);
    }
  }
}


// CText

// Constructor
// CText constructor
CText::CText(const CString& aString, const CRect& rect, COLORREF aColor)
{
  m_PenWidth = 1;                      // Set the pen width
  m_Color = aColor;                    // Set the color for the text
  m_String = aString;                  // Make a copy of the string

  m_EnclosingRect = rect;
  m_EnclosingRect.NormalizeRect();
}

// Draw a tet element
void CText::Draw(CDC* pDC, CElement* pElement)
{
  COLORREF Color(m_Color);             // Initialize with element color

  if(this==pElement)
    Color = SELECT_COLOR;              // Set selected color

  // Set the text color and output the text
  pDC->SetTextColor(Color);
  pDC->DrawText(m_String, m_EnclosingRect, DT_CENTER|DT_VCENTER|
                                                        DT_SINGLELINE|DT_NOCLIP);
}

// Move a text element
void CText::Move(const CSize& size)
{
  m_EnclosingRect += size;            // Move the rectangle
}

void CText::Serialize(CArchive& ar)
{
  CElement::Serialize(ar);             // Call the base class function

  if (ar.IsStoring())
  {
      ar << m_String;                    // and Store the text string
  }
  else
  {
      ar >> m_String;                    // and Retrieve the text string
  }
}
