// ODBCDatabase3Doc.h : interface of the CODBCDatabase3Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_ODBCDatabase3DOC_H__E80EBBB9_4231_4F35_BF8D_8EE640DC8FB3__INCLUDED_)
#define AFX_ODBCDatabase3DOC_H__E80EBBB9_4231_4F35_BF8D_8EE640DC8FB3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "ODBCDatabase3Set.h"


class CODBCDatabase3Doc : public CDocument
{
protected: // create from serialization only
	CODBCDatabase3Doc();
	DECLARE_DYNCREATE(CODBCDatabase3Doc)

// Attributes
public:
	CODBCDatabase3Set m_ODBCDatabase3Set;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CODBCDatabase3Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CODBCDatabase3Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CODBCDatabase3Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ODBCDatabase3DOC_H__E80EBBB9_4231_4F35_BF8D_8EE640DC8FB3__INCLUDED_)
