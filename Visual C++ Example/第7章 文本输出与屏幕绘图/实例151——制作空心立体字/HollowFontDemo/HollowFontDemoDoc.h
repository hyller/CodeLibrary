// HollowFontDemoDoc.h : interface of the CHollowFontDemoDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_HOLLOWFONTDEMODOC_H__C0BF5CA5_C020_4E89_9EF4_E004D6441EB0__INCLUDED_)
#define AFX_HOLLOWFONTDEMODOC_H__C0BF5CA5_C020_4E89_9EF4_E004D6441EB0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CHollowFontDemoDoc : public CDocument
{
protected: // create from serialization only
	CHollowFontDemoDoc();
	DECLARE_DYNCREATE(CHollowFontDemoDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHollowFontDemoDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CHollowFontDemoDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CHollowFontDemoDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HOLLOWFONTDEMODOC_H__C0BF5CA5_C020_4E89_9EF4_E004D6441EB0__INCLUDED_)
