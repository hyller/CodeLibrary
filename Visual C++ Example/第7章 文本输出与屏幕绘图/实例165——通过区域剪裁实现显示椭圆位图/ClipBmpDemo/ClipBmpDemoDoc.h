// ClipBmpDemoDoc.h : interface of the CClipBmpDemoDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CLIPBMPDEMODOC_H__8B261C24_19DF_4BBD_A70D_439CDAA08A72__INCLUDED_)
#define AFX_CLIPBMPDEMODOC_H__8B261C24_19DF_4BBD_A70D_439CDAA08A72__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CClipBmpDemoDoc : public CDocument
{
protected: // create from serialization only
	CClipBmpDemoDoc();
	DECLARE_DYNCREATE(CClipBmpDemoDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CClipBmpDemoDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CClipBmpDemoDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CClipBmpDemoDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CLIPBMPDEMODOC_H__8B261C24_19DF_4BBD_A70D_439CDAA08A72__INCLUDED_)
