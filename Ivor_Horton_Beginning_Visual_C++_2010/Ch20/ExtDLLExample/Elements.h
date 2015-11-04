#pragma once
#include <vector>

// Macro to make the code more readable
#ifdef ELEMENT_EXPORTS
#define SKETCHER_API   __declspec(dllexport)
#else
#define SKETCHER_API   __declspec(dllimport)
#endif


// CElement command target

class SKETCHER_API CElement : public CObject
{
   DECLARE_SERIAL(CElement)
   protected:
      int m_PenWidth;                        // Pen width
      COLORREF m_Color;                      // Color of an element
      CRect m_EnclosingRect;                 // Rectangle enclosing an element

   public:
      virtual ~CElement();  
      virtual void Draw(CDC* pDC, CElement* pElement=0) {}   // Virtual draw operation
      virtual void Move(const CSize& aSize){}                // Move an element

      CRect GetBoundRect() const;            // Get the bounding rectangle for an element
      virtual void Serialize(CArchive& ar);  // Serialize function for the class
   protected:
      CElement();                            // Here to prevent it being called
};

class SKETCHER_API CLine : public CElement
{
   DECLARE_SERIAL(CLine)
   public:
      ~CLine(void);
      virtual void Draw(CDC* pDC, CElement* pElement=0);     // Function to display a line
      virtual void Move(const CSize& aSize);                 // Move a line
      virtual void Serialize(CArchive& ar);                  // Serialize function for the class

      // Constructor for a line object
      CLine(const CPoint& start, const CPoint& end, COLORREF aColor, int penWidth);

   protected:
      CPoint m_StartPoint;             // Start point of line
      CPoint m_EndPoint;               // End point of line

      CLine(void){}                    // Default constructor should not be used
};

class SKETCHER_API CRectangle : public CElement
{
   DECLARE_SERIAL(CRectangle)
   public:
      ~CRectangle(void);
      virtual void Draw(CDC* pDC, CElement* pElement=0);     // Function to display a rectangle
      virtual void Move(const CSize& aSize);                 // Move a rectangle
      virtual void Serialize(CArchive& ar);                  // Serialize function for the class

      // Constructor for a rectangle object
      CRectangle(const CPoint& start, const CPoint& end, COLORREF aColor, int pehWidth);

   protected:
     CRectangle(void){}                                      // Default constructor - should not be used
};

class SKETCHER_API CCircle : public CElement
{
   DECLARE_SERIAL(CCircle)
   public:
      ~CCircle(void);
      virtual void Draw(CDC* pDC, CElement* pElement=0);     // Function to display a circle
      virtual void Move(const CSize& aSize);                 // Move a circle
      virtual void Serialize(CArchive& ar);                  // Serialize function for the class

      // Constructor for a circle object
      CCircle(const CPoint& sStart, const CPoint& eEnd, COLORREF aColor, int penWidth);

   protected:
     CCircle(void){}                                         // Default constructor - should not be used
};

class SKETCHER_API CCurve: public CElement
{
   DECLARE_SERIAL(CCurve)
  public:
    ~CCurve(void);
    virtual void Draw(CDC* pDC, CElement* pElement=0);     // Function to display a curve
    virtual void Move(const CSize& aSize);                 // Move a curve

    // Constructor for a curve object
    CCurve(const CPoint& first, const CPoint& second, COLORREF aColor, int pehWidth);
    void AddSegment(const CPoint& point);                  // Add a segment to the curve
    virtual void Serialize(CArchive& ar);                  // Serialize function for the class

 protected:
    std::vector<CPoint> m_Points;                          // Points defining the curve
    CCurve(void){}                                         // Default constructor - should not be used
};

// Class defining a text object
class SKETCHER_API CText: public CElement
{
   DECLARE_SERIAL(CText)
  public:
    // Function to display a text element
    virtual void Draw(CDC* pDC, CElement* pElement=nullptr);

    // Constructor for a text element
    CText(const CString& aString, const CRect& rect, COLORREF aColor);
    virtual void Move(const CSize& size);                  // Move a text element
    virtual void Serialize(CArchive& ar);                  // Serialize function for the class

  protected:
    CString m_String;                                      // Text to be displayed
    CText(){}                                              // Default constructor
};
