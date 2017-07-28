// OpenURLDoc.h : interface of the COpenURLDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_OPENURLDOC_H__83C31490_31FE_4F83_9780_187853E2D6E0__INCLUDED_)
#define AFX_OPENURLDOC_H__83C31490_31FE_4F83_9780_187853E2D6E0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class COpenURLDoc : public CDocument
{
protected: // create from serialization only
	COpenURLDoc();
	DECLARE_DYNCREATE(COpenURLDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COpenURLDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~COpenURLDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(COpenURLDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OPENURLDOC_H__83C31490_31FE_4F83_9780_187853E2D6E0__INCLUDED_)
