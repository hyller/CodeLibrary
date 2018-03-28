#if !defined(AFX_OLEEDITPPG_H__A619BB6A_138B_4078_A178_436CDC8C7ADE__INCLUDED_)
#define AFX_OLEEDITPPG_H__A619BB6A_138B_4078_A178_436CDC8C7ADE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// OleEditPpg.h : Declaration of the COleEditPropPage property page class.

////////////////////////////////////////////////////////////////////////////
// COleEditPropPage : See OleEditPpg.cpp.cpp for implementation.

class COleEditPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(COleEditPropPage)
	DECLARE_OLECREATE_EX(COleEditPropPage)

// Constructor
public:
	COleEditPropPage();

// Dialog Data
	//{{AFX_DATA(COleEditPropPage)
	enum { IDD = IDD_PROPPAGE_OLEEDIT };
	BOOL	m_bText;
	BOOL	m_bNumbers;
	//}}AFX_DATA

// Implementation
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Message maps
protected:
	//{{AFX_MSG(COleEditPropPage)
		// NOTE - ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OLEEDITPPG_H__A619BB6A_138B_4078_A178_436CDC8C7ADE__INCLUDED)
