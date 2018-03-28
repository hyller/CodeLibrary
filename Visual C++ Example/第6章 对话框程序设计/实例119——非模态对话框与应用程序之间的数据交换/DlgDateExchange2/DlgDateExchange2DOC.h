// DlgDateExchange2Doc.h : interface of the CDlgDateExchange2Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DlgDateExchange2DOC_H__491C4E05_6A0E_4D6D_AA3F_4675B260CC48__INCLUDED_)
#define AFX_DlgDateExchange2DOC_H__491C4E05_6A0E_4D6D_AA3F_4675B260CC48__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CDlgDateExchange2Doc : public CDocument
{
protected: // create from serialization only
	CDlgDateExchange2Doc();
	DECLARE_DYNCREATE(CDlgDateExchange2Doc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgDateExchange2Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDlgDateExchange2Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDlgDateExchange2Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DlgDateExchange2DOC_H__491C4E05_6A0E_4D6D_AA3F_4675B260CC48__INCLUDED_)
