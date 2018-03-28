#if !defined(AFX_NEWLISTBOX_H__851E5AF1_5BA6_43B5_BB21_5899641CE290__INCLUDED_)
#define AFX_NEWLISTBOX_H__851E5AF1_5BA6_43B5_BB21_5899641CE290__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// NewListBox.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// NewListBox window

class NewListBox : public CListBox
{
// Construction
public:
	NewListBox();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(NewListBox)
	public:
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~NewListBox();

	// Generated message map functions
protected:
	//{{AFX_MSG(NewListBox)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NEWLISTBOX_H__851E5AF1_5BA6_43B5_BB21_5899641CE290__INCLUDED_)
