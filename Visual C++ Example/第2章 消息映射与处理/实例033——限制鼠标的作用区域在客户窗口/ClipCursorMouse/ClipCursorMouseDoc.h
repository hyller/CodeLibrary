// ClipCursorMouseDoc.h : interface of the CClipCursorMouseDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CLIPCURSORMOUSEDOC_H__72EF3248_E47B_4B01_AB8D_225060067558__INCLUDED_)
#define AFX_CLIPCURSORMOUSEDOC_H__72EF3248_E47B_4B01_AB8D_225060067558__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CClipCursorMouseDoc : public CDocument
{
protected: // create from serialization only
	CClipCursorMouseDoc();
	DECLARE_DYNCREATE(CClipCursorMouseDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CClipCursorMouseDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CClipCursorMouseDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CClipCursorMouseDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CLIPCURSORMOUSEDOC_H__72EF3248_E47B_4B01_AB8D_225060067558__INCLUDED_)
