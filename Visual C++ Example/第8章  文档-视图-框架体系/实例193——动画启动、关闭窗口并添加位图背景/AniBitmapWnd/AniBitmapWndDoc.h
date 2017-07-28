// AniBitmapWndDoc.h : interface of the CAniBitmapWndDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_ANIBITMAPWNDDOC_H__D6791162_DCDF_4FEE_9558_5EED1A1942AC__INCLUDED_)
#define AFX_ANIBITMAPWNDDOC_H__D6791162_DCDF_4FEE_9558_5EED1A1942AC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CAniBitmapWndDoc : public CDocument
{
protected: // create from serialization only
	CAniBitmapWndDoc();
	DECLARE_DYNCREATE(CAniBitmapWndDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAniBitmapWndDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CAniBitmapWndDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CAniBitmapWndDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ANIBITMAPWNDDOC_H__D6791162_DCDF_4FEE_9558_5EED1A1942AC__INCLUDED_)
