#if !defined(AFX_COMBOTOOL_H__3CF9439C_85C0_4E70_BB5A_1BD4CB355546__INCLUDED_)
#define AFX_COMBOTOOL_H__3CF9439C_85C0_4E70_BB5A_1BD4CB355546__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ComboTool.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CComboTool window

class CComboTool : public CToolBar
{
// Construction
public:
	CComboTool();

// Attributes
public:

// Operations
public:
	//创建组合框函数
	BOOL CreateCombo(DWORD dwStyle, CComboBox *pComboBox, UINT nID,int nWidth, int nHeight );


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CComboTool)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CComboTool();

	// Generated message map functions
protected:
	//{{AFX_MSG(CComboTool)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COMBOTOOL_H__3CF9439C_85C0_4E70_BB5A_1BD4CB355546__INCLUDED_)
