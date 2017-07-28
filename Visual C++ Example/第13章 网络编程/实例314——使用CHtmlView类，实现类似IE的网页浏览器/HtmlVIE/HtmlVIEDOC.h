// HtmlVIEDoc.h : interface of the CHtmlVIEDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_HtmlVIEDOC_H__2A1CE6FE_C12F_4371_8C15_D15CB984BD04__INCLUDED_)
#define AFX_HtmlVIEDOC_H__2A1CE6FE_C12F_4371_8C15_D15CB984BD04__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CHtmlVIEDoc : public CDocument
{
protected: // create from serialization only
	CHtmlVIEDoc();
	DECLARE_DYNCREATE(CHtmlVIEDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHtmlVIEDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CHtmlVIEDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CHtmlVIEDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HtmlVIEDOC_H__2A1CE6FE_C12F_4371_8C15_D15CB984BD04__INCLUDED_)
