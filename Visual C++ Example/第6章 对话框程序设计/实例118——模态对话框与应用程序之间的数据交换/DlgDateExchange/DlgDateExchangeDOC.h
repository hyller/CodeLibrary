// DlgDateExchangeDoc.h : interface of the CDlgDateExchangeDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DlgDateExchangeDOC_H__F5C4EC22_5F06_4202_ADEA_2B6D9ECDB4B6__INCLUDED_)
#define AFX_DlgDateExchangeDOC_H__F5C4EC22_5F06_4202_ADEA_2B6D9ECDB4B6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CDlgDateExchangeDoc : public CDocument
{
protected: // create from serialization only
	CDlgDateExchangeDoc();
	DECLARE_DYNCREATE(CDlgDateExchangeDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgDateExchangeDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDlgDateExchangeDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDlgDateExchangeDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DlgDateExchangeDOC_H__F5C4EC22_5F06_4202_ADEA_2B6D9ECDB4B6__INCLUDED_)
