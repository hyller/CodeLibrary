// ProgressbarStatusDoc.h : interface of the CProgressbarStatusDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_PROGRESSBARSTATUSDOC_H__631F6184_357B_474F_AEFB_7577AD3ACF21__INCLUDED_)
#define AFX_PROGRESSBARSTATUSDOC_H__631F6184_357B_474F_AEFB_7577AD3ACF21__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CProgressbarStatusDoc : public CDocument
{
protected: // create from serialization only
	CProgressbarStatusDoc();
	DECLARE_DYNCREATE(CProgressbarStatusDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CProgressbarStatusDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CProgressbarStatusDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CProgressbarStatusDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PROGRESSBARSTATUSDOC_H__631F6184_357B_474F_AEFB_7577AD3ACF21__INCLUDED_)
