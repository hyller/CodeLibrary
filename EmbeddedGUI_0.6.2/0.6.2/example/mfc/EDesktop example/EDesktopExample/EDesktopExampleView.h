// EDesktopExampleView.h : interface of the CEDesktopExampleView class
//


#pragma once
#include "ExtGDIplus.h"
#include "EFrame.h"

class CEDesktopExampleView : public CView
{
protected: // create from serialization only
	CEDesktopExampleView();
	DECLARE_DYNCREATE(CEDesktopExampleView)

// Attributes
public:
	CEDesktopExampleDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Implementation
public:
	virtual ~CEDesktopExampleView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
#ifdef EG_RGB_COLOR
	EG_RGBBufferDisplay rbd;
#else
	EG_BinaryBufferDisplay rbd;
#endif

	bool first;
	EDesktop desk;
	CTime time;

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnDesktopCreatedesktop();
protected:
	virtual void OnActivateFrame(UINT nState, CFrameWnd* pDeactivateFrame);
public:
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // debug version in EDesktopExampleView.cpp
inline CEDesktopExampleDoc* CEDesktopExampleView::GetDocument() const
   { return reinterpret_cast<CEDesktopExampleDoc*>(m_pDocument); }
#endif

