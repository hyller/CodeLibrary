// DebugDemoDoc.h : interface of the CDebugDemoDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DEBUGDEMODOC_H__8DC7967E_B983_427E_96A9_4CAEAB8A99EE__INCLUDED_)
#define AFX_DEBUGDEMODOC_H__8DC7967E_B983_427E_96A9_4CAEAB8A99EE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CDebugDemoDoc : public CDocument
{
protected: // create from serialization only
	CDebugDemoDoc();
	DECLARE_DYNCREATE(CDebugDemoDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDebugDemoDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDebugDemoDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDebugDemoDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DEBUGDEMODOC_H__8DC7967E_B983_427E_96A9_4CAEAB8A99EE__INCLUDED_)
