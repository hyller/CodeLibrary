#if !defined(AFX_ROUNDBUTTON_H__E5743415_E81F_4F1D_B2AA_9D58F39530AD__INCLUDED_)
#define AFX_ROUNDBUTTON_H__E5743415_E81F_4F1D_B2AA_9D58F39530AD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RoundButton.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CRoundButton window

class AFX_EXT_CLASS CRoundButton : public CButton
{
// Construction
public:
	CRoundButton();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRoundButton)
	public:
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);//CButton成员函数
	protected:
	virtual void PreSubclassWindow();//CWnd成员函数
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CRoundButton();

	// Generated message map functions
protected:
	//{{AFX_MSG(CRoundButton)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()

public:
	CRgn   m_ValidRegion;  //显示区域  
	CPoint m_ptCentre;   //圆心
	int    m_nRadius;    //半径

};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ROUNDBUTTON_H__E5743415_E81F_4F1D_B2AA_9D58F39530AD__INCLUDED_)
