// SysMenuItemDoc.h : interface of the CSysMenuItemDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SYSMENUITEMDOC_H__B10A043E_57EA_4A28_AA0A_AAE1783716C6__INCLUDED_)
#define AFX_SYSMENUITEMDOC_H__B10A043E_57EA_4A28_AA0A_AAE1783716C6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CSysMenuItemDoc : public CDocument
{
protected: // create from serialization only
	CSysMenuItemDoc();
	DECLARE_DYNCREATE(CSysMenuItemDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSysMenuItemDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSysMenuItemDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSysMenuItemDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SYSMENUITEMDOC_H__B10A043E_57EA_4A28_AA0A_AAE1783716C6__INCLUDED_)
