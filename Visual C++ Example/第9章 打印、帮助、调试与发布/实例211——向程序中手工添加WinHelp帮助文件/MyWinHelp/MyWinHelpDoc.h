// MyWinHelpDoc.h : interface of the CMyWinHelpDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYWINHELPDOC_H__4AF34352_EF0B_4B42_8D6C_1B681A63713F__INCLUDED_)
#define AFX_MYWINHELPDOC_H__4AF34352_EF0B_4B42_8D6C_1B681A63713F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMyWinHelpDoc : public CDocument
{
protected: // create from serialization only
	CMyWinHelpDoc();
	DECLARE_DYNCREATE(CMyWinHelpDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyWinHelpDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMyWinHelpDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMyWinHelpDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYWINHELPDOC_H__4AF34352_EF0B_4B42_8D6C_1B681A63713F__INCLUDED_)
