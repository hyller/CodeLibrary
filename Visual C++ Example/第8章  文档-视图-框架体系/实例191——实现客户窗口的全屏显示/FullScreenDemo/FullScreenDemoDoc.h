// FullScreenDemoDoc.h : interface of the CFullScreenDemoDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_FULLSCREENDEMODOC_H__E9A5731C_8B67_4E3B_9044_DC9797BDF3E5__INCLUDED_)
#define AFX_FULLSCREENDEMODOC_H__E9A5731C_8B67_4E3B_9044_DC9797BDF3E5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CFullScreenDemoDoc : public CDocument
{
protected: // create from serialization only
	CFullScreenDemoDoc();
	DECLARE_DYNCREATE(CFullScreenDemoDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFullScreenDemoDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CFullScreenDemoDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CFullScreenDemoDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FULLSCREENDEMODOC_H__E9A5731C_8B67_4E3B_9044_DC9797BDF3E5__INCLUDED_)
