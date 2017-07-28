// TextButtonToolDoc.h : interface of the CTextButtonToolDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TextButtonToolDOC_H__1F261D4B_ABCB_11D5_8C1B_CC1A6D330B6E__INCLUDED_)
#define AFX_TextButtonToolDOC_H__1F261D4B_ABCB_11D5_8C1B_CC1A6D330B6E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CTextButtonToolDoc : public CDocument
{
protected: // create from serialization only
	CTextButtonToolDoc();
	DECLARE_DYNCREATE(CTextButtonToolDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTextButtonToolDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTextButtonToolDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTextButtonToolDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TextButtonToolDOC_H__1F261D4B_ABCB_11D5_8C1B_CC1A6D330B6E__INCLUDED_)
