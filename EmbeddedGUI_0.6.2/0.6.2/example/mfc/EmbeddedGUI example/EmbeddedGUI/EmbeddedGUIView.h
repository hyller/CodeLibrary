// EmbeddedGUIView.h : interface of the CEmbeddedGUIView class
//


#pragma once
#include "ExtGDIplus.h"
#include "EFrame.h"

class CEmbeddedGUIView : public CView
{
protected: // create from serialization only
	CEmbeddedGUIView();
	DECLARE_DYNCREATE(CEmbeddedGUIView)

// Attributes
public:
	CEmbeddedGUIDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Implementation
public:
	virtual ~CEmbeddedGUIView();
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

	ESimpleDesktop desk;
	bool deskOpen;
	bool first;
	bool max;
// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnGraphicfunctionDrawhorizonline();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
protected:
	virtual void OnActivateFrame(UINT nState, CFrameWnd* pDeactivateFrame);
public:
	afx_msg void OnDesktopClearscreen();
	afx_msg void OnGraphicfunctionDrawverticalline();
	afx_msg void OnGraphicfunctionDrawline();
	afx_msg void OnGraphicfunctionDrawcircle();
	afx_msg void OnGraphicfunctionDrawfilledcircle();
	afx_msg void OnGraphicfunctionDr();
	afx_msg void OnGraphicfunctionDrawfilledrectangle();
	afx_msg void OnControlLabel();
	afx_msg void OnControlExtLabel();
	afx_msg void OnControlButton();
	afx_msg void OnControlEdit();
	afx_msg void OnControlCombobox();
	afx_msg void OnControlCheckbutton();
	afx_msg void OnControlProgress();
	afx_msg void OnGraphicfunctionDrawstring();
	afx_msg void OnWindowPlainwindow();
	afx_msg void OnWindowWindow();
	afx_msg void OnMenu();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnGraphicfunctionDrawfontstring();
	afx_msg void OnGraphicfunctionDrawimage();
	afx_msg void OnDesktopMessageboxindesktop();
	afx_msg void OnDesktopDialogboxindesktop();
	afx_msg void OnDesktopNewdesktop2();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnDesktopElistindesktop();
	afx_msg void OnDesktopEmenuindesktop();
	afx_msg void OnDesktopEpopmenuindesktop();
	afx_msg void OnControlTree();
	afx_msg void OnDesktopEtreeindesktop();
	afx_msg void OnControlIconbutton();
	afx_msg void OnGraphicfunctionDrawwidthline();
	afx_msg void OnGraphicfunctionDrawquarterarc();
	afx_msg void OnGraphicfunctionDrawarc();
	afx_msg void OnGraphicfunctionDrawpieslice();
	afx_msg void OnGraphicfunctionDrawellipse();
	afx_msg void OnGraphicfunctionDrawfilledellipse();
	afx_msg void OnDesktopEtoolbarindesktop();
	afx_msg void OnControlStatusbar();
	afx_msg void OnDesktopNewdesktop3();
	afx_msg void OnDesktopChangedesktop3state();
	afx_msg void OnDesktopMovedesktop3();
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnDesktopEbarchartindesktop();
	afx_msg void OnControlClock();
};

#ifndef _DEBUG  // debug version in EmbeddedGUIView.cpp
inline CEmbeddedGUIDoc* CEmbeddedGUIView::GetDocument() const
   { return reinterpret_cast<CEmbeddedGUIDoc*>(m_pDocument); }
#endif

