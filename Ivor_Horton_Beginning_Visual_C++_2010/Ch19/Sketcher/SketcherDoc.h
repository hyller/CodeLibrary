
// SketcherDoc.h : interface of the CSketcherDoc class
//


#pragma once
#include <list>
#include "Elements.h"
#include "SketcherConstants.h"

class CSketcherDoc : public CDocument
{
protected: // create from serialization only
	CSketcherDoc();
	DECLARE_DYNCREATE(CSketcherDoc)
  // Attributes
public:

// Operations
public:
  unsigned int GetElementType() const                 // Get the element type
     { return m_Element; }
  COLORREF GetElementColor() const                    // Get the element color
     { return m_Color; }

  // Add an element to the list
  void AddElement(CElement* pElement)                
   {
     m_ElementList.push_back(pElement);
     SetModifiedFlag();                    // Set the modified flag
   }

   std::list<CElement*>::const_iterator begin() const // Get list begin iterator
                   { return m_ElementList.begin(); }
   std::list<CElement*>::const_iterator end() const   // Get list end iterator
                   { return m_ElementList.end(); }
   CElement* FindElement(const CPoint point) const;   // Finds the element under the point
   void DeleteElement(CElement* pElement);            // Delete an element
   void CSketcherDoc::SendToBack(CElement* pElement); // Move element to front of list
   int GetPenWidth() const                            // Get the current pen width
      { return m_PenWidth; }
  CSize GetDocSize() const                            // Retrieve the document size
    { return m_DocSize; }              
  CRect GetDocExtent();                               // Get the bounding rectangle for the whole document
// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Implementation
public:
	virtual ~CSketcherDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
  int m_PenWidth;                                     // Current pen width
  CSize m_DocSize;                                    // Document size
  ElementType m_Element;                              // Current element type
  COLORREF m_Color;                                   // Current element color
  std::list<CElement*> m_ElementList;                 // List of elements in the sketch

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Helper function that sets search content for a Search Handler
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
  afx_msg void OnColorBlack();
  afx_msg void OnColorRed();
  afx_msg void OnColorGreen();
  afx_msg void OnElementLine();
  afx_msg void OnElementRectangle();
  afx_msg void OnElementCircle();
  afx_msg void OnElementCurve();
  afx_msg void OnColorBlue();
  afx_msg void OnUpdateColorBlack(CCmdUI *pCmdUI);
  afx_msg void OnUpdateColorRed(CCmdUI *pCmdUI);
  afx_msg void OnUpdateColorGreen(CCmdUI *pCmdUI);
  afx_msg void OnUpdateColorBlue(CCmdUI *pCmdUI);
  afx_msg void OnUpdateElementLine(CCmdUI *pCmdUI);
  afx_msg void OnUpdateElementRectangle(CCmdUI *pCmdUI);
  afx_msg void OnUpdateElementCircle(CCmdUI *pCmdUI);
  afx_msg void OnUpdateElementCurve(CCmdUI *pCmdUI);
  afx_msg void OnPenWidth();
  afx_msg void OnElementText();
  afx_msg void OnUpdateElementText(CCmdUI *pCmdUI);
};
