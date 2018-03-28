// StatusBmpDoc.h : interface of the CStatusBmpDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_STATUSBMPDOC_H__BF8A472F_B39A_4885_BFED_5CF5EB334DF9__INCLUDED_)
#define AFX_STATUSBMPDOC_H__BF8A472F_B39A_4885_BFED_5CF5EB334DF9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CStatusBmpDoc : public CDocument
{
protected: // create from serialization only
	CStatusBmpDoc();
	DECLARE_DYNCREATE(CStatusBmpDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStatusBmpDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CStatusBmpDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CStatusBmpDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STATUSBMPDOC_H__BF8A472F_B39A_4885_BFED_5CF5EB334DF9__INCLUDED_)
