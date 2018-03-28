#if !defined(AFX_COLORCOMBO_H__01B62923_FA10_4C75_A6EE_B6BEADDDDCC4__INCLUDED_)
#define AFX_COLORCOMBO_H__01B62923_FA10_4C75_A6EE_B6BEADDDDCC4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ColorCombo.h : header file
//
#include <afxtempl.h>	// CArray类头文件
/////////////////////////////////////////////////////////////////////////////
// CColorCombo window

class CColorCombo : public CComboBox
{
// Construction
public:
	CColorCombo();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CColorCombo)
	public:
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	protected:
	virtual void PreSubclassWindow();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CColorCombo();
	CArray<COLORREF, COLORREF> colors;//定义颜色数组
	// Generated message map functions
protected:
	//{{AFX_MSG(CColorCombo)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COLORCOMBO_H__01B62923_FA10_4C75_A6EE_B6BEADDDDCC4__INCLUDED_)
