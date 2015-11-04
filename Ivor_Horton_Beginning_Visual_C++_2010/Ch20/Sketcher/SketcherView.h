
// SketcherView.h : interface of the CSketcherView class
//


#pragma once
#include "Elements.h"

class CSketcherView : public CScrollView
{
protected: // create from serialization only
	CSketcherView();
	DECLARE_DYNCREATE(CSketcherView)

// Attributes
public:
	CSketcherDoc* GetDocument() const;

// Operations
public:

protected:
  CElement* CreateElement(void) const;                    // Create a new element on the heap
  void MoveElement(CClientDC& aDC, const CPoint& point);  // Move an element

  // Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CSketcherView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
  afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
  afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
  afx_msg void OnMouseMove(UINT nFlags, CPoint point);
protected:
  CPoint m_FirstPoint;              // First point recorded for an element
  CPoint m_SecondPoint;             // Second point recorded for an element
  CElement* m_pTempElement;         // Pointer to a temporary element
  CElement* m_pSelected;            // Pointer to currently selected element
  bool m_MoveMode;                  // Move element flag
  CPoint m_CursorPos;               // Cursor position
  CPoint m_FirstPos;                // Original position in a move
  int m_Scale;                      // Current view scale

  virtual void OnUpdate(CView* /*pSender*/, LPARAM /*lHint*/, CObject* /*pHint*/);
public:
  virtual void OnInitialUpdate();
public:
  afx_msg void OnElementMove();
  afx_msg void OnElementDelete();
  afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
  afx_msg void OnElementSendtoback();
  afx_msg void OnViewScale();
  virtual void OnPrepareDC(CDC* pDC, CPrintInfo* pInfo = NULL);
  void ResetScrollSizes(void);
  afx_msg void OnUpdateScale(CCmdUI *pCmdUI);
  virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);
};

#ifndef _DEBUG  // debug version in SketcherView.cpp
inline CSketcherDoc* CSketcherView::GetDocument() const
   { return reinterpret_cast<CSketcherDoc*>(m_pDocument); }
#endif

