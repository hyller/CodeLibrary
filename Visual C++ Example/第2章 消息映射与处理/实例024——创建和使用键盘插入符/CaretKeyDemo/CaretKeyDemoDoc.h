// CaretKeyDemoDoc.h : interface of the CCaretKeyDemoDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CARETKEYDEMODOC_H__37924664_CC59_41A8_80CD_1AF859B65BBE__INCLUDED_)
#define AFX_CARETKEYDEMODOC_H__37924664_CC59_41A8_80CD_1AF859B65BBE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CCaretKeyDemoDoc : public CDocument
{
protected: // create from serialization only
	CCaretKeyDemoDoc();
	DECLARE_DYNCREATE(CCaretKeyDemoDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCaretKeyDemoDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CCaretKeyDemoDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CCaretKeyDemoDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CARETKEYDEMODOC_H__37924664_CC59_41A8_80CD_1AF859B65BBE__INCLUDED_)
