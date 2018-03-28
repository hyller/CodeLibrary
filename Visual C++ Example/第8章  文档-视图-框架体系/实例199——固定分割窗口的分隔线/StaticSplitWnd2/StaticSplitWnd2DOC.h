// StaticSplitWnd2Doc.h : interface of the CStaticSplitWnd2Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_StaticSplitWnd2DOC_H__A27EEC7F_5A32_11D6_8F32_00E04CE76240__INCLUDED_)
#define AFX_StaticSplitWnd2DOC_H__A27EEC7F_5A32_11D6_8F32_00E04CE76240__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CStaticSplitWnd2Doc : public CDocument
{
protected: // create from serialization only
	CStaticSplitWnd2Doc();
	DECLARE_DYNCREATE(CStaticSplitWnd2Doc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStaticSplitWnd2Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CStaticSplitWnd2Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CStaticSplitWnd2Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_StaticSplitWnd2DOC_H__A27EEC7F_5A32_11D6_8F32_00E04CE76240__INCLUDED_)
