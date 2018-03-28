// MirroBmpDemoDoc.h : interface of the CMirroBmpDemoDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MIRROBMPDEMODOC_H__1D30AC12_0851_414B_A3BD_1EFD6DDA36DF__INCLUDED_)
#define AFX_MIRROBMPDEMODOC_H__1D30AC12_0851_414B_A3BD_1EFD6DDA36DF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMirroBmpDemoDoc : public CDocument
{
protected: // create from serialization only
	CMirroBmpDemoDoc();
	DECLARE_DYNCREATE(CMirroBmpDemoDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMirroBmpDemoDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMirroBmpDemoDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMirroBmpDemoDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MIRROBMPDEMODOC_H__1D30AC12_0851_414B_A3BD_1EFD6DDA36DF__INCLUDED_)
