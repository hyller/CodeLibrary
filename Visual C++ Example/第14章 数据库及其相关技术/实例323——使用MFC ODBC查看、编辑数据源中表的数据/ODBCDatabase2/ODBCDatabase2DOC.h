// ODBCDatabase2Doc.h : interface of the CODBCDatabase2Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_ODBCDatabase2DOC_H__E80EBBB9_4231_4F35_BF8D_8EE640DC8FB3__INCLUDED_)
#define AFX_ODBCDatabase2DOC_H__E80EBBB9_4231_4F35_BF8D_8EE640DC8FB3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "ODBCDatabase2Set.h"


class CODBCDatabase2Doc : public CDocument
{
protected: // create from serialization only
	CODBCDatabase2Doc();
	DECLARE_DYNCREATE(CODBCDatabase2Doc)

// Attributes
public:
	CODBCDatabase2Set m_ODBCDatabase2Set;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CODBCDatabase2Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CODBCDatabase2Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CODBCDatabase2Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ODBCDatabase2DOC_H__E80EBBB9_4231_4F35_BF8D_8EE640DC8FB3__INCLUDED_)
