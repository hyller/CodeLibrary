// BmpZoomPartDoc.h : interface of the CBmpZoomPartDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_BMPZOOMPARTDOC_H__C07C8632_4822_4687_9E62_0EC19867EAB2__INCLUDED_)
#define AFX_BMPZOOMPARTDOC_H__C07C8632_4822_4687_9E62_0EC19867EAB2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CBmpZoomPartDoc : public CDocument
{
protected: // create from serialization only
	CBmpZoomPartDoc();
	DECLARE_DYNCREATE(CBmpZoomPartDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBmpZoomPartDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CBmpZoomPartDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CBmpZoomPartDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BMPZOOMPARTDOC_H__C07C8632_4822_4687_9E62_0EC19867EAB2__INCLUDED_)
