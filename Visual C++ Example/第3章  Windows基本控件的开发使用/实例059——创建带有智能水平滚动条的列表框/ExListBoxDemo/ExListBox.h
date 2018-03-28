#if !defined(AFX_EXLISTBOX_H__CE3B8328_FA4D_4F60_B4A6_7E8B91C54B52__INCLUDED_)
#define AFX_EXLISTBOX_H__CE3B8328_FA4D_4F60_B4A6_7E8B91C54B52__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ExListBox.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CExListBox window

class CExListBox : public CListBox
{
// Construction
public:
	CExListBox();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CExListBox)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CExListBox();
	int AddString( LPCTSTR lpszItem );
	// Generated message map functions
protected:
	//{{AFX_MSG(CExListBox)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	int     m_nMaxWidth;
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EXLISTBOX_H__CE3B8328_FA4D_4F60_B4A6_7E8B91C54B52__INCLUDED_)
