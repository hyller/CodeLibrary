// KeyMessageMenuDoc.h : interface of the CKeyMessageMenuDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_KEYMESSAGEMENUDOC_H__A2DF755E_3F2A_49C2_AC4F_DDB374602A77__INCLUDED_)
#define AFX_KEYMESSAGEMENUDOC_H__A2DF755E_3F2A_49C2_AC4F_DDB374602A77__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CKeyMessageMenuDoc : public CDocument
{
protected: // create from serialization only
	CKeyMessageMenuDoc();
	DECLARE_DYNCREATE(CKeyMessageMenuDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CKeyMessageMenuDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CKeyMessageMenuDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CKeyMessageMenuDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_KEYMESSAGEMENUDOC_H__A2DF755E_3F2A_49C2_AC4F_DDB374602A77__INCLUDED_)
