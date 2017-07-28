// AutoHelpDoc.h : interface of the CAutoHelpDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_AUTOHELPDOC_H__4B3676F6_3922_4DFF_ADD6_3DEDD47222C3__INCLUDED_)
#define AFX_AUTOHELPDOC_H__4B3676F6_3922_4DFF_ADD6_3DEDD47222C3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CAutoHelpDoc : public CDocument
{
protected: // create from serialization only
	CAutoHelpDoc();
	DECLARE_DYNCREATE(CAutoHelpDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAutoHelpDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CAutoHelpDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CAutoHelpDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AUTOHELPDOC_H__4B3676F6_3922_4DFF_ADD6_3DEDD47222C3__INCLUDED_)
